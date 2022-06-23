#pragma once

#include <UART/UART.hpp>
#include <UART/PC/UARTPC.hpp>

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

///usr/include/c++/9/bits/unique_ptr.h:857:30: error: no matching function for call to ‘IO::IO::IO(std::shared_ptr<UART::UART>&)’