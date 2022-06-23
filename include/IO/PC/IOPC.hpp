#pragma once

#include "IO/IO.hpp"

namespace IO {
    class IOPC : public IO {
    public:
        explicit IOPC(const IOSettings &settings);

        void setPinHigh() override;

        void setPinLow() override;

    private:
    };
}