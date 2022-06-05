#include <UART/UART.hpp>
#include <stdint.h>
#include <iostream>
#include <boost/asio.hpp>

//Unfornately needed for setting and resetting the DTR pin under Windows
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

namespace UART {


    UART::UART(const UARTSettings settings) {
        const uint32_t baudrateVal = mBaudEnumToAbsoluteValue(settings.baudrate);
        bool emptyDevicePath = (settings.devicePath == "");
        if (emptyDevicePath)
            throw "Empty devicePath!";

        std::cout << "New instance of the UART object" << '\n';
        std::cout << "Uartsettings Path: " << settings.devicePath << " baudrate: " << baudrateVal << '\n';
        mUartSettings = settings;
        mSerialPort = mSerialPortPtr(new boost::asio::serial_port(mIOService));
        mSerialPort->open(settings.devicePath);
        mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(baudrateVal));
    }

    UART::~UART() {
        boost::system::error_code ec;
        std::cout << "Destructor Called\n";
        mSerialPort->close(ec);
        mIOService.stop();
        if (ec)
            std::cerr << "Closing serialport failed!" << '\n';
        else
            std::cout << "Serial port succesfully closed!" << '\n';
    }

    void UART::changeBaud(const Baudrates baudrate) {
        boost::system::error_code ec;
        const uint32_t baudrateVal = mBaudEnumToAbsoluteValue(baudrate);
        mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(baudrateVal));
        if (ec)
            std::cerr << "Changing baudrate failed!" << '\n';
        else
            std::cout << "Succesfully changed baudrate!" << '\n';
    }


    void UART::sendByte(const uint8_t byte) {
        uint8_t buff = byte;
        boost::system::error_code ec;
        mSerialPort->write_some(boost::asio::buffer(&buff, sizeof(buff)), ec);
    }


    void UART::resetDTRPin() {
        using namespace boost::asio;

        serial_port::native_handle_type nativeHandle = mSerialPort->native_handle();

#if defined(_WIN32) || defined(_WIN64)
        EscapeCommFunction(nativeHandle, SETDTR);
#else
        const int Pin = TIOCM_DTR;
        ioctl(nativeHandle, TIOCMBIS, &Pin);
#endif
    }

    void UART::setDTRPin() {
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
    uint32_t UART::mBaudEnumToAbsoluteValue(Baudrates baudrate) {
        int baudEnumIndex = static_cast<uint32_t>(baudrate);
        std::cout << baudEnumIndex << '\n';
        if (baudEnumIndex == 0)
            throw std::invalid_argument("baudrate is invalid or an empty pointer!");

        uint32_t baud = mBaudMapping.at(baudEnumIndex);
        return baud;
    }

}