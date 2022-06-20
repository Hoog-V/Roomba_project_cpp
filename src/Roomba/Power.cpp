#include "Roomba/Roomba.hpp"

namespace Roomba{
    void Roomba::turnOff() {
        if (mCurrControlMode == control::No_init){
            setControlMode(control::Passive);
        }
        mUartHandle->sendByte(command::Power);
        mCurrControlMode = control::Passive;
    }

    void Roomba::turnOn() {
        mIOHandle->setPinHigh();
        SLEEP(1000);
        mIOHandle->setPinLow();
        SLEEP(100);
    }
}