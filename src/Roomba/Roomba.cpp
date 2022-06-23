#include <UART/UART.hpp>
#include <Roomba/Roomba.hpp>
#include <array>
#include <IO/IO.hpp>
#include <vector>

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
                                                                    // invalid baudrate checking.
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

    void Roomba::playSongNum(const uint8_t songNum) {
        bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
        if (checkControlMode)
            setControlMode(control::Safe);

        std::vector<uint8_t> commands{command::Play, songNum};
        mUartHandle->sendBytes(commands);
    }

    void Roomba::setSongNum(const uint8_t songNum, const std::vector<uint8_t> notesWithDuration) {
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

    

    sensorData Roomba::getSensorData(sensors sensor) {
        std::vector<uint8_t> sensorCommand = { command::Sensor, sensor };
        std::vector<uint8_t> sensorDataRead = { 0 };
        sensorData sensorDataOut;

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorDataRead);

        ///@note the numbers seen here are form the datasheet https://cdn-shop.adafruit.com/datasheets/create_2_Open_Interface_Spec.pdf seen at page 22 to 31, all these numbers are the PacketID's
        if((sensor == 24) || (sensor == 45)) {
            sensorDataOut.s8 = (int8_t)sensorDataRead[0];
        }
        if((sensor >= 7 && sensor <= 18) || (sensor >= 34 && sensor <= 38) || (sensor == 21) || (sensor == 52) || (sensor == 53) || (sensor == 58)) {
            sensorDataOut.u8 = (uint8_t)sensorDataRead[0];
        }
        if((sensor == 19) || (sensor == 20) || (sensor == 23) || (sensor >= 29 && sensor <= 42) || (sensor >= 54 && sensor <= 57)) {
            sensorDataOut.s16 = (int16_t)((sensorDataRead[0] << 8) | sensorDataRead[1]);
        }
        if((sensor == 22) || (sensor >= 25 && sensor <= 31) || (sensor == 43) || (sensor == 44) || (sensor >= 46 && sensor <= 51)) {
            sensorDataOut.u16 = (uint16_t)((sensorDataRead[0] << 8) | sensorDataRead[1]);
        }

        return sensorDataOut;
    }

    std::vector<uint8_t> Roomba::getSensorDataList(std::vector<sensors> sensor) {
        std::vector<uint8_t> sensorCommand = { command::SensorList };
        std::vector<uint8_t> sensorData = { 0 };

        sensorCommand.push_back(sensor.size());
        sensorCommand.insert(sensorCommand.end(), sensor.begin(), sensor.end());

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorData);

        return sensorData;
    }

}
