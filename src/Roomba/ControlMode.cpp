#include "Roomba/Roomba.hpp"
#include <crossplatform/function.hpp>

namespace Roomba{
        bool Roomba::mSetPassiveMode() {
        switch (mCurrControlMode) {
            case control::No_init: {
                this->mUartHandle->sendByte(command::Start);
                SLEEP(25);
                break;
            }
            case control::Safe:
            case control::Full: {
                this->mUartHandle->sendByte(command::Spot);
                SLEEP(220);
                this->mUartHandle->sendByte(command::Spot);
                SLEEP(25);
                break;
            }
            default:
                return (false);
        }
        return (true);

    }


    bool Roomba::mSetSafeMode() {
        if (mCurrControlMode == control::No_init){
            mSetPassiveMode();
        }else if (mCurrControlMode == control::Safe){
            return (false);
        }
        this->mUartHandle->sendByte(command::Safe);
        SLEEP(25);
        return (true);
    }

    bool Roomba::mSetFullMode() {
        if (mCurrControlMode != control::Safe){
            mSetSafeMode();
        }else if (mCurrControlMode == control::Full){
            return (false);
        }
        this->mUartHandle->sendByte(command::Full);
        SLEEP(25);
        return (true);
    }


    void Roomba::setControlMode(control ControlMode) {
        switch (ControlMode) {
            case control::Passive:
                if (mSetPassiveMode()){
                    mCurrControlMode = control::Passive;
                }
                break;
            case control::Safe:
                if (mSetSafeMode()){
                    mCurrControlMode = control::Safe;
                }
                break;
            case control::Full:
                if (mSetFullMode()){
                    mCurrControlMode = control::Full;
                }
                break;
        }
    }
}