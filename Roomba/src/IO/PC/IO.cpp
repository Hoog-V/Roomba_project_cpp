#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::setPinHigh() {
    UART::UARTPC* mUartHandlePC = static_cast<UART::UARTPC*>(mUartHandle);
    mUartHandlePC->resetDTRPin();
}

void IO::setPinLow() {
    UART::UARTPC* mUartHandlePC = static_cast<UART::UARTPC*>(mUartHandle);
    mUartHandlePC->setDTRPin();
}