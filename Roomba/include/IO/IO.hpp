#pragma once

#include <UART/UART.hpp>
#include <UART/PC/UARTPC.hpp>
class IO {
public:
    IO(UART::UARTPC *uartHandle) {
        mUartHandle = uartHandle;
    }

    void setPinHigh();

    void setPinLow();

private:
    UART::UARTPC *mUartHandle;
};