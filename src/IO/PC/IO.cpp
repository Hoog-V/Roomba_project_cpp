#include "IO/IO.hpp"
#include "UART/UART.hpp"

namespace IO {
    IOPC::IOPC(const IOSettings &settings) {
        mIOSettings = settings;
    }

    void IOPC::setPinHigh() {
        mIOSettings.mUartHandle->resetDTRPin();
    }

    void IOPC::setPinLow() {
        mIOSettings.mUartHandle->setDTRPin();
    }

    std::shared_ptr<IO> IO::Create(const IOSettings &settings) {
        if (settings.mConnectionMethod == UART::connectionMethod::USB) {
            return std::make_shared<IOPC>(settings);
        }
        throw std::exception();
    }
}