#pragma once

#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>
#include <map>
#include <boost/any.hpp>
#include <exception>

namespace UART {

    enum class Baudrates : int8_t {
        baud_invalid = 0,
        baud_300,
        baud_600,
        baud_1200,
        baud_2400,
        baud_4800,
        baud_9600,
        baud_14400,
        baud_19200,
        baud_28800,
        baud_38400,
        baud_57600,
        baud_115200
    };

    enum class connectionMethod;

    struct UARTSettings {
        UART::Baudrates baudrate = Baudrates::baud_115200;
        std::string devicePath;
        UART::connectionMethod connectionMethod;
    };

    class UART {
    public:
        static UART* Create(const UARTSettings Settings);

        virtual void changeBaud(const Baudrates baudrate)= 0;

        virtual void sendByte(const uint8_t byte)= 0;

        virtual void sendBytes(uint8_t* buffer, const uint32_t numOfBytes) =0;

        virtual void readBytes(uint8_t* buffer, const uint32_t numOfBytes) = 0;
    protected:
        const std::array<uint32_t, 13> mBaudMapping = {0, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400,
                                                       57600, 115200};



        uint32_t mBaudEnumToAbsoluteValue(Baudrates baudrate);

        UARTSettings mUartSettings;
    };

}


