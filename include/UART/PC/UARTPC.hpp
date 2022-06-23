#pragma once

#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>
#include <map>
#include "UART/UART.hpp"

namespace UART{

    enum class connectionMethod{
        USB
    };

    class UARTPC : public UART {
    public:
        UARTPC(const UARTSettings &settings);

        void changeBaud(const Baudrates baudrate);

        void sendByte(const uint8_t byte);

        void sendBytes(std::vector<uint8_t> &buffer);

        void readBytes(std::vector<uint8_t> &buffer, size_t numOfBytes);

        void resetDTRPin();

        void setDTRPin();

        ~UARTPC();

    private:
        typedef boost::shared_ptr<boost::asio::serial_port> mSerialPortPtr;
        mSerialPortPtr mSerialPort;
        boost::asio::io_service mIOService;
    };

}
