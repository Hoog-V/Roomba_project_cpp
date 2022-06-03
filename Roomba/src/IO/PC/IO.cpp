#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::setPinHigh()
{
    mUartHandle->resetDTRPin();
}

void IO::setPinLow()
{
    mUartHandle->setDTRPin();
}