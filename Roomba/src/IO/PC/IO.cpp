#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::SetBRCPinHIGH()
{
    mUARTHandle->setRTSHigh();
}

void IO::SetBRCPinLOW()
{
    mUARTHandle->setRTSLow();
}