#pragma once

#include <UART/UART.hpp>
#include <map>
#include <stdarg.h>


namespace Roomba {


    enum class cleaning {
        Spot, Clean, Max
    };

    enum class control {
        No_init, Passive, Safe, Full
    };

    enum class sensors : uint8_t {
        Bumps_wheeldrop, Wall, Cliff_Left, Cliff_Right, VirtualWall,
        MotorOvercurrent, DirtDetector_Left, DirtDetector_Right, RCM,
        Buttons, Distance, Angle, ChargingState, Voltage, Current, Temperature,
        Charge, Capacity
    };

   

    class Roomba {
    public:
        Roomba(UART::UART *UARTHandle) {
            mUARTHandle = UARTHandle;
            mCurrControlMode = control::No_init;
        }

        void rotate(int16_t angle);

        void setMotor(uint8_t motor, uint8_t velocity);

        void startCleaning(cleaning cleaningMode);

        void setDockMode();

        void setControlMode(control ControlMode);

       
        void setBaudRate(UART::Baudrates BaudRate);

        void getSensorData(uint16_t sensor);

        /*
         * ...(Variable Length Argument) = NoteNumber N & NoteDuration N
         */
        void setSongNum(uint8_t songNum, uint8_t songLength, ...);

        void playSongNum(uint8_t songNum);

        void turnOn();

        void turnOff();

        void driveCommand(int16_t velocity, int16_t radius);

        void driveForward();
        
        void driveBackward();

        void driveLeft();

        void driveRight();

        ~Roomba() {
            mUARTHandle->sendByte(command::Stop);
        }

    private:
        bool mSetPassiveMode();

        bool mSetSafeMode();

        bool mSetFullMode();

        bool mGetCurrLedState();

        UART::UART *mUARTHandle;
        control mCurrControlMode;
    };

}


