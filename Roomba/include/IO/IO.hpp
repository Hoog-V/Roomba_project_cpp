#pragma once

#include <UART/UART.hpp>

class IO{
public:
    IO(UART *UARTHandle){
        mUARTHandle = UARTHandle;
    }
    void SetBRCPinHIGH();
    void SetBRCPinLOW();
private:
    UART *mUARTHandle;
};