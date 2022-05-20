#pragma once

#include <UART/UART.hpp>
#include <map>

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

    enum leds : uint8_t {
        LED_Debris = 1, LED_Spot = 2, LED_Dock = 4, LED_Check_Robot = 8
    };

    enum command : uint8_t {
        Start = 128, Baud, Control, Safe, Full, Power, Spot, Clean,
        Max_Clean, Drive, Motors, Leds, Song, Play, Query, Dock,
        Motor_PWM, Drive_Wheels, Stream = 148, Query_List, Do_Stream,
        Schedule_Leds = 162, Digit_Leds_Raw, Digit_Leds_Ascii,
        Buttons, Schedule = 167, Set_Date_Time, Stop = 173
    };


    enum class LedState {
        On, Off
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

        void setLed(uint8_t led, LedState state);

        void setPowerLed(uint8_t color, uint8_t intensity);

        void setBaudRate(UART::Baudrates BaudRate);

        void getSensorData(uint16_t sensor);

        void setSongNum(uint8_t songnum);

        void turnOn();

        void turnOff();

        void Roomba::driveCommand();

        void Roomba::driveForward();
        
        void Roomba::driveBackward();

        void Roomba::driveLeft();

        void Roomba::driveRight();

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


