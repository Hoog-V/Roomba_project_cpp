#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::SetPinHIGH()
{
    mUARTHandle->unsetDTRPin();
}

void IO::SetPinLOW()
{
    mUARTHandle->setDTRPin();
}