#pragma once

#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>
#include <map>

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

    struct UARTSettings {
        UART::Baudrates baudrate = Baudrates::baud_115200;
        std::string devicePath;
    };

    class UART {
    public:

        UART(const UARTSettings settings);

        void changeBaud(const Baudrates baudrate);

        void sendByte(const uint8_t byte);

        template<typename arr, std::size_t size>
        void sendBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes);

        template<typename arr, std::size_t size>
        void readBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes);

        void resetDTRPin();

        void setDTRPin();

        ~UART();

    private:
        const std::array <uint32_t, 13> mBaudMapping = {0, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400,
                                                        57600, 115200};

        typedef boost::shared_ptr<boost::asio::serial_port> mSerialPortPtr;
        mSerialPortPtr mSerialPort;
        boost::asio::io_service mIOService;

        uint32_t mBaudEnumToAbsoluteValue(Baudrates baudrate);
        UARTSettings mUartSettings;
    };

#include <UART/UART-tmp-func.inl>

}


