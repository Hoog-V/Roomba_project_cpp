#include "UART/UART.hpp"
#include <iostream>
#include "boost/asio.hpp"

//Unfortunately needed for setting and resetting the DTR pin under Windows
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

namespace UART {


    UARTPC::UARTPC(const UARTSettings &settings) {
        const uint32_t baudrateVal = mBaudEnumToAbsoluteValue(settings.baudrate);
        bool emptyDevicePath = settings.devicePath.empty();
        if (emptyDevicePath)
            throw "Empty devicePath!";

        std::cout << "New instance of the UART object" << '\n';
        std::cout << "Uartsettings Path: " << settings.devicePath << " baudrate: " << baudrateVal << '\n';
        this->mUartSettings = settings;
        this->mSerialPort = mSerialPortPtr(new boost::asio::serial_port(mIOService));
        this->mSerialPort->open(settings.devicePath);
        this->mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(baudrateVal));
    }

    UARTPC::~UARTPC()  {
        boost::system::error_code ec;
        std::cout << "Destructor Called\n";
        this->mSerialPort->close(ec);
        this->mIOService.stop();
        if (ec) {
            std::cerr << "Closing serialport failed!" << '\n';
        }
    }

    void UARTPC::changeBaud(const Baudrates baudrate) {
        boost::system::error_code ec;
        const uint32_t baudrateVal = this->mBaudEnumToAbsoluteValue(baudrate);
        this->mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(baudrateVal));
        if (ec)
            throw "Changing baudrate failed!";
    }


    void UARTPC::sendByte(const uint8_t byte) {
        uint8_t buff = byte;
        boost::system::error_code ec;
        this->mSerialPort->write_some(boost::asio::buffer(&buff, sizeof(buff)), ec);
    }

    void UARTPC::sendBytes(std::vector<uint8_t> &buffer){
        if (buffer.empty()) {
            throw "Number of bytes to read is zero or negative";
        }
        boost::system::error_code ec;
        boost::asio::mutable_buffer mBuffer = boost::asio::mutable_buffer(buffer.data(), buffer.size());

        this->mSerialPort->write_some(mBuffer, ec);
    }

    void UARTPC::readBytes(std::vector<uint8_t> &buffer, size_t numOfBytes){
        if (numOfBytes < 1) {
            throw "Number of bytes to read is zero or negative";
        }
        buffer.reserve(numOfBytes);
        boost::system::error_code ec;
        boost::asio::mutable_buffer mBuffer = boost::asio::mutable_buffer(buffer.data(), numOfBytes);

        this->mSerialPort->read_some(mBuffer, ec);
    }


    void UARTPC::resetDTRPin() {
        using namespace boost::asio;

        serial_port::native_handle_type nativeHandle = mSerialPort->native_handle();

#if defined(_WIN32) || defined(_WIN64)
        EscapeCommFunction(nativeHandle, SETDTR);
#else
        const int Pin = TIOCM_DTR;
        ioctl(nativeHandle, TIOCMBIS, &Pin);
#endif
    }

    void UARTPC::setDTRPin() {
        using namespace boost::asio;

        serial_port::native_handle_type nativeHandle = mSerialPort->native_handle();

#if defined(_WIN32) || defined(_WIN64)
        EscapeCommFunction(nativeHandle, CLRDTR);
#else
        const int Pin = TIOCM_DTR;
        ioctl(nativeHandle, TIOCMBIC, &Pin);
#endif
    }


    /**
    * Converts Baudrates enum to an implicit uint32_t value.
    * If invalid baudrate or pointer is passed in to arguments it will throw an exception
    */
    constexpr uint32_t UART::mBaudEnumToAbsoluteValue(Baudrates baudrate) {
        uint8_t baudEnumIndex = static_cast<uint8_t>(baudrate);
        if (baudEnumIndex == 0) {
            throw std::invalid_argument("baudrate is invalid or an empty pointer!");
        }
        uint32_t baud = mBaudMapping.at(baudEnumIndex);
        return baud;
    }

    std::shared_ptr<UART> UART::Create(const UARTSettings &Settings){
        if (Settings.connectionMethod == connectionMethod::USB) {
            return std::make_shared<UARTPC>(Settings);
        }
        throw std::exception();
    }
}