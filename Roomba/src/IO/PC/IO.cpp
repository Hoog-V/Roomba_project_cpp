#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::SetBRCPinHIGH()
{
    mUARTHandle->setDTRHigh();
}

void IO::SetBRCPinLOW()
{
    mUARTHandle->setDTRLow();
}