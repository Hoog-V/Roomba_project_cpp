#include <UART/UART.hpp>
#include <stdint.h>
#include <iostream>
#include <boost/asio.hpp>

namespace UART {


    UART::UART(const UARTSettings Settings) {
        const uint32_t BaudrateVal = ImplicitBaud.at(Settings.Baudrate);

        bool emptyDevicePath = (Settings.DevicePath == "");
        if (emptyDevicePath)
            throw "Empty DevicePath!";

        std::cout << "New instance of the UART object" << '\n';
        std::cout << "Uartsettings Path: " << Settings.DevicePath << " Baudrate: " << BaudrateVal << '\n';

        mSerialPort = serial_port_ptr(new boost::asio::serial_port(mIOService));
        mSerialPort->open(Settings.DevicePath);
        mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(BaudrateVal));
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

    void UART::changeBaud(const Baudrates Baudrate) {
        boost::system::error_code ec;
        const uint32_t BaudrateVal = ImplicitBaud.at(Baudrate);
        mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(BaudrateVal));
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


    void UART::setDTRPinHigh() {
        const int NativeHandle = mSerialPort->native_handle();
        const int Pin = TIOCM_DTR;
        ioctl(NativeHandle, TIOCMBIS, &Pin);
    }

    void UART::setDTRPinLow() {
        const int NativeHandle = mSerialPort->native_handle();
        const int Pin = TIOCM_DTR;
        ioctl(NativeHandle, TIOCMBIC, &Pin);
    }

}