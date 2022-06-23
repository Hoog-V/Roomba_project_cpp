#include <vector>
#include "UART/UART.hpp"
#include "Roomba/Roomba.hpp"

namespace Roomba {
/// Roomba Dock mode which makes the Roomba go to his docking station.
///
/// This is the detailed description, more stuff here. 
/// @param A this describes parameter A
/// @param B this describes parameter B
/// @returns nothing important
/// @see anotherfunction() anotherfunction2()
/// @note a little side note
/// @attention a little more important than a note
/// @warning a warning is super important!

    void Roomba::setDockMode() {
        if (mCurrControlMode == control::No_init)
            setControlMode(control::Passive);
        mUartHandle->sendByte(command::Dock);
        mCurrControlMode = control::Passive;
    }

    void Roomba::startCleaning(cleaning cleaningMode) {
        if (mCurrControlMode == control::No_init)
            setControlMode(control::Passive);

        switch (cleaningMode) {
            case cleaning::Spot:
                mUartHandle->sendByte(command::Spot);
                break;
            case cleaning::Max:
                mUartHandle->sendByte(command::Max_Clean);
                break;
            case cleaning::Clean:
                mUartHandle->sendByte(command::Clean);
                break;
        }
        mCurrControlMode = control::Passive;
    }

    void Roomba::setBaudRate(UART::Baudrates baudRate) {
        const uint8_t BaudCMD = static_cast<uint8_t>(baudRate) - 1; // -1 because commands are shifted by one to allow
                                                                    // invalid baud rate checking.
        if (BaudCMD == 0 || BaudCMD > 12)
            throw std::invalid_argument("Invalid baudRate or pointer passed in to parameter baudRate");

        std::vector<uint8_t> commands{command::Baud, BaudCMD};
        mUartHandle->sendBytes(commands);
        SLEEP(100);
        mUartHandle->changeBaud(baudRate);
    }

    void Roomba::setLed(uint8_t led, ledState state) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);
        uint8_t ledBits = state == ledState::Off ? 0 : led;
        std::vector<uint8_t> commands{command::Leds, ledBits, 0, 128};
        mUartHandle->sendBytes(commands);
    }

    void Roomba::setPowerLed(uint8_t color, uint8_t intensity) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::vector<uint8_t> commands{command::Leds, 4, color, intensity};
        mUartHandle->sendBytes(commands);
    }

    constexpr void Roomba::playSongNum(uint8_t songNum) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::vector<uint8_t> commands{command::Play, songNum};
        mUartHandle->sendBytes(commands);
    }

    constexpr void Roomba::setSongNum(uint8_t songNum, const std::vector<uint8_t>& notesWithDuration) {
        const bool tooManyNotes = (notesWithDuration.size() > 32);
        const bool numOfNotesAndDurationNotEqual = (notesWithDuration.size() % 2);
        if(tooManyNotes || numOfNotesAndDurationNotEqual) {
            throw std::exception();
        }

        const bool wrongControlMode = (mCurrControlMode == control::Passive || mCurrControlMode == control::No_init);
        if(wrongControlMode) {
            mSetSafeMode();
        }

        const uint8_t numOfNotes = static_cast<uint8_t>(notesWithDuration.size())/2;
        std::vector<uint8_t> commands = {command::Song, songNum, numOfNotes};

        for(uint8_t Note: notesWithDuration){
            commands.push_back(Note);
        }
        mUartHandle->sendBytes(commands);
    }

}
