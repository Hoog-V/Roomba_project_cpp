#include <IO/IO.hpp>
#include <UART/UART.hpp>

namespace IO {
    IOPC::IOPC(const std::shared_ptr<UART::UARTPC> uartHandle) {
        mUartHandle = uartHandle;
    }

    void IOPC::setPinHigh() {
        this->mUartHandle->resetDTRPin();
    }

    void IOPC::setPinLow() {
        this->mUartHandle->setDTRPin();
    }
}