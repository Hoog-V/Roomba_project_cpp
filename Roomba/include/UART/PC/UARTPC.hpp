#pragma once

#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>
#include <map>
#include "UART/UART.hpp"

namespace UART{
    enum class connectionMethod{
        USB, ESP
    };

    class UARTPC : public UART {
    public:

        explicit UARTPC(const UARTSettings settings);

        void changeBaud(const Baudrates baudrate);

        void sendByte(const uint8_t byte);

        template<typename arr, std::size_t size>
        void sendBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes);

        template<typename arr, std::size_t size>
        void readBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes);

        void resetDTRPin();

        void setDTRPin();

        ~UARTPC();

    private:
        typedef boost::shared_ptr<boost::asio::serial_port> mSerialPortPtr;
        mSerialPortPtr mSerialPort;
        boost::asio::io_service mIOService;
    };
#include "UART-tmp-func.inl"
}
