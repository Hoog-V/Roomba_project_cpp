#pragma once

#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>
#include <map>

namespace UART {

    enum class Baudrates : uint32_t {
        baud_300 = 300,
        baud_600 = 600,
        baud_1200 = 1200,
        baud_2400 = 2400,
        baud_4800 = 4800,
        baud_9600 = 9600,
        baud_19200 = 19200,
        baud_57600 = 57600,
        baud_115200 = 115200
    };

    struct UARTSettings {
        UART::Baudrates Baudrate = Baudrates::baud_115200;
        std::string DevicePath;
    };

    class UART {
    public:

        UART(const UARTSettings Settings);

        void changeBaud(const Baudrates baudrate);

        void sendByte(const uint8_t byte);

        template<typename arr, std::size_t size>
        void sendBytes(std::array<arr, size> &buffer, const uint8_t numOfbytes);

        template<typename arr, std::size_t size>
        void readBytes(std::array<arr, size> &buffer, const uint8_t numOfbytes);

        void setDTRPinHigh();

        void setDTRPinLow();

        ~UART();

    private:
        typedef boost::shared_ptr<boost::asio::serial_port> serial_port_ptr;
        serial_port_ptr mSerialPort;
        boost::asio::io_service mIOService;
        const std::map<Baudrates, uint32_t> ImplicitBaud{
                {Baudrates::baud_300,    300},
                {Baudrates::baud_600,    600},
                {Baudrates::baud_1200,   1200},
                {Baudrates::baud_2400,   2400},
                {Baudrates::baud_4800,   4800},
                {Baudrates::baud_9600,   9600},
                {Baudrates::baud_19200,  19200},
                {Baudrates::baud_57600,  57600},
                {Baudrates::baud_115200, 115200}
        };
    };

#include <UART/UART-tmp-func.inl>

}


