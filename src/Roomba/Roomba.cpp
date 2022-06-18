#include <UART/UART.hpp>
#include <Roomba/Roomba.hpp>
#include <array>
#include <crossplatform/function.hpp>
#include <IO/IO.hpp>

namespace Roomba {
/// Roomba Dockmode which makes the Roomba go to his docking station.
///
/// This is the detailed description, more stuff here. 
    void Roomba::setDockMode() {
        /// @param A this discribes parameter A
        /// @param B this discribes parameter B
        /// @returns nothing important
        /// @see anotherfunction() anotherfunction2()
        /// @note a little side note
        /// @attention a little more important than a note
        /// @warning a warning is super important!

        if (mCurrControlMode == control::No_init)
            setControlMode(control::Passive);
        mUartHandle->sendByte(command::Dock);
        mCurrControlMode = control::Passive;
    }

    bool Roomba::mSetPassiveMode() {
        switch (mCurrControlMode) {
            case control::No_init: {
                mUartHandle->sendByte(command::Start);
                SLEEP(25);
                break;
            }
            case control::Safe:
            case control::Full: {
                mUartHandle->sendByte(command::Spot);
                SLEEP(220);
                mUartHandle->sendByte(command::Spot);
                SLEEP(25);
                break;
            }
            default:
                return (false);
        }
        return (true);

    }


    bool Roomba::mSetSafeMode() {
        if (mCurrControlMode == control::No_init)
            mSetPassiveMode();
        else if (mCurrControlMode == control::Safe)
            return (false);
        mUartHandle->sendByte(command::Safe);
        SLEEP(25);
        return (true);
    }

    bool Roomba::mSetFullMode() {
        if (mCurrControlMode != control::Safe)
            mSetSafeMode();
        else if (mCurrControlMode == control::Full)
            return (false);

        mUartHandle->sendByte(command::Full);
        SLEEP(25);
        return (true);
    }

    void Roomba::setControlMode(control ControlMode) {
        switch (ControlMode) {
            case control::Passive:
                if (mSetPassiveMode())
                    mCurrControlMode = control::Passive;
                break;
            case control::Safe:
                if (mSetSafeMode())
                    mCurrControlMode = control::Safe;
                break;
            case control::Full:
                if (mSetFullMode())
                    mCurrControlMode = control::Full;
                break;
        }
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

    void Roomba::turnOff() {
        if (mCurrControlMode == control::No_init)
            setControlMode(control::Passive);
        mUartHandle->sendByte(command::Power);
        mCurrControlMode = control::Passive;
    }

    void Roomba::turnOn() {
        mIOHandle->setPinHigh();
        SLEEP(1000);
        mIOHandle->setPinLow();
        SLEEP(100);
    }

    void Roomba::setBaudRate(UART::Baudrates baudRate) {
        const uint8_t BaudCMD = static_cast<uint8_t>(baudRate) - 1; // -1 because commands are shifted by one to allow
                                                                    // invalid baudrate checking.
        if (BaudCMD == 0 || BaudCMD > 12)
            throw std::invalid_argument("Invalid baudRate or pointer passed in to parameter baudRate");

        std::array<uint8_t, 2> commands{command::Baud, BaudCMD};
        mUartHandle->sendBytes(commands.data(), commands.size());
        SLEEP(100);
        mUartHandle->changeBaud(baudRate);
    }

    void Roomba::setLed(uint8_t led, ledState state) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);
        uint8_t ledBits = state == ledState::Off ? 0 : led;
        std::array<uint8_t, 4> commands{command::Leds, ledBits, 0, 128};
        mUartHandle->sendBytes(commands.data(), std::size(commands));
    }

    void Roomba::setPowerLed(uint8_t color, uint8_t intensity) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::array<uint8_t, 4> commands{command::Leds, 4, color, intensity};
        mUartHandle->sendBytes(commands.data(), std::size(commands));
    }

    void Roomba::playSongNum(uint8_t songNum) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::array<uint8_t, 2> commands{command::Play, songNum};
        mUartHandle->sendBytes(commands.data(), std::size(commands));
    }

    void Roomba::setSongNum(uint8_t songNum, uint8_t songLength, ...) {
        std::array<uint8_t, 32> commands{command::Song, songLength};
        int lenList = (songLength * 2);
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;

        if (songLength > 16)
            return;

        if (checkControlMode)
            setControlMode(control::Safe);

        va_list vaList;
        va_start(vaList, lenList);

        for (int i = 2; i < songLength * 2; i++) {
            commands[i] = va_arg(vaList, uint8_t);
        }

        mUartHandle->sendBytes(commands.data(), std::size(commands));
    }

    void Roomba::driveForward() {
        driveCommand(500, 32768);
    }

    void Roomba::driveBackward() {
        driveCommand(-500, 32768);
    }

    void Roomba::driveLeft() {
        driveCommand(0, -2000);
    }

    void Roomba::driveRight() {
        driveCommand(0, 2000);
    }

/// velocity value may be between 500 and -500
/// radius value may be between 2000 and -2000
    void Roomba::driveCommand(int16_t velocity, int16_t radius) {
        std::array<uint8_t, 5> commands{command::Drive, static_cast<uint8_t>(velocity & 0xFF),
                                        static_cast<uint8_t>(velocity >> 8),
                                        static_cast<uint8_t>(radius & 0xFF),
                                        static_cast<uint8_t>(radius >> 8)};
        mUartHandle->sendBytes(commands.data(), std::size(commands));
    }

}
