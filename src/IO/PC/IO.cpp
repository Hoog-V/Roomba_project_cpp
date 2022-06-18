#include <IO/IO.hpp>
#include <UART/UART.hpp>

void IO::setPinHigh() {
    this->mUartHandle->resetDTRPin();
}

void IO::setPinLow() {
    this->mUartHandle->setDTRPin();
}