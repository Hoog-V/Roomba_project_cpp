#pragma once

#include <LEDS/LEDS.hpp>    

    
    void Roomba::setLed(uint8_t led, LedState state) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);
        uint8_t ledBits = state == LedState::Off ? 0 : led;
        std::array<uint8_t, 4> commands{command::Leds, ledBits, 0, 128};
        mUARTHandle->sendBytes(commands, std::size(commands));
    }

    void Roomba::setPowerLed(uint8_t color, uint8_t intensity) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::array<uint8_t, 4> commands{command::Leds, 4, color, intensity};
        mUARTHandle->sendBytes(commands, std::size(commands));
    }


    bool Roomba::mGetCurrLedState() {
        return true;
    }