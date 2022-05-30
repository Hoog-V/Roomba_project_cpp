#pragma once

#include <UART/UART.hpp>

class IO{
public:
    IO(UART::UART *UARTHandle){
        mUARTHandle = UARTHandle;
    }
    void SetPinHIGH();
    void SetPinLOW();
private:
    UART::UART *mUARTHandle;
};