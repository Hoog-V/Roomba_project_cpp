#pragma once

#include <UART/UART.hpp>

class IO{
public:
    IO(UART::UART *uartHandle){
        mUartHandle = uartHandle;
    }
    void setPinHigh();
    void setPinLow();
private:
    UART::UART *mUartHandle;
};