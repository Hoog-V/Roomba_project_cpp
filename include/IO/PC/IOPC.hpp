#pragma once

#include "IO/IO.hpp"

namespace IO {
    class IOPC : public IO {
    public:
        IOPC(const std::shared_ptr<UART::UARTPC> uartHandle);

        void setPinHigh();

        void setPinLow();

    private:
    };
}