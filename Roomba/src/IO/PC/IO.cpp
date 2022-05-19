#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::SetPinHIGH()
{
    mUARTHandle->setDTRHigh();
}

void IO::SetPinLOW()
{
    mUARTHandle->setDTRLow();
}