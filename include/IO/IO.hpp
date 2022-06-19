#pragma once

#include <UART/UART.hpp>
#include <UART/PC/UARTPC.hpp>
class IO {
public:
    IO(std::shared_ptr<UART::UART> uartHandle) {
        mUartHandle = uartHandle;
    }

    void setPinHigh();

    void setPinLow();

private:
    std::shared_ptr<UART::UART> mUartHandle;
};