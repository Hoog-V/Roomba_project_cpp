#pragma once

#include <UART/UART.hpp>

class IO{
public:
    IO(UART *UARTHandle){
        mUARTHandle = UARTHandle;
    }
    void SetPinHIGH();
    void SetPinLOW();
private:
    UART *mUARTHandle;
};