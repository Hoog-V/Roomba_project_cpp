#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::SetPinHIGH()
{
    mUARTHandle->setDTRPinHigh();
}

void IO::SetPinLOW()
{
    mUARTHandle->setDTRPinLow();
}