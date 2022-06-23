#pragma once

#include "UART/UART.hpp"
#include "UART/PC/UARTPC.hpp"

namespace IO {

    struct IOSettings{
        std::shared_ptr<UART::UART> mUartHandle;
        UART::connectionMethod mConnectionMethod;
    };

    class IO {
    public:
        static std::shared_ptr<IO> Create(const IOSettings &settings);
    
        virtual void setPinHigh() = 0;

        virtual void setPinLow() = 0;

    protected:
        IOSettings mIOSettings;
    };
}
