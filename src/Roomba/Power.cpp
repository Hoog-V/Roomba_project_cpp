#include "Roomba/Roomba.hpp"
#include "crossplatform/function.hpp"

namespace Roomba{
    constexpr void Roomba::turnOff() {
        if (mCurrControlMode == control::No_init){
            setControlMode(control::Passive);
        }
        this->mUartHandle->sendByte(command::Power);
        mCurrControlMode = control::Passive;
    }

    constexpr void Roomba::turnOn() {
        mIOHandle->setPinHigh();
        SLEEP(1000);
        mIOHandle->setPinLow();
        SLEEP(100);
    }
}