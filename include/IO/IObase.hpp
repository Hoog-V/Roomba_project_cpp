#pragma once

#include <UART/UART.hpp>
#include <UART/PC/UARTPC.hpp>

namespace IO {
    class IO {
    public:
        static std::shared_ptr<IO> Create(const std::shared_ptr<UART::UART> uartHandle);
    
        virtual void setPinHigh();

        virtual void setPinLow();

    protected:
        std::shared_ptr<UART::UART> mUartHandle;
    };
}