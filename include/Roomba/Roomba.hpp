#pragma once

#include <UART/UART.hpp>
#include <map>
#include <stdarg.h>
#include <IO/IO.hpp>

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


    enum class ledState {
        On, Off
    };

    class Roomba {
    public:
        Roomba(std::shared_ptr<UART::UART> UARTHandle) {
            mUartHandle = UARTHandle;
            mIOHandle =  std::make_unique<IO>(mUartHandle);
            mCurrControlMode = control::No_init;
        }

        void rotate(int16_t angle);

        void setMotor(uint8_t motor, uint8_t velocity);

        void startCleaning(cleaning cleaningMode);

        void setDockMode();

        void setControlMode(control ControlMode);

        void setLed(uint8_t led, ledState state);

        void setPowerLed(uint8_t color, uint8_t intensity);

        void setBaudRate(UART::Baudrates baudRate);

        void getSensorData(uint16_t sensor);

        void setSongNum(const uint8_t songNum, const std::vector<uint8_t> notesWithDuration);

        void playSongNum(const uint8_t songNum);

        void turnOn();

        void turnOff();

        void driveCommand(int16_t velocity, int16_t radius);

        void driveForward();

        void driveBackward();

        void driveLeft();

        void driveRight();

        ~Roomba() {
            mUartHandle->sendByte(command::Stop);
        }

    private:
        bool mSetPassiveMode();

        bool mSetSafeMode();

        bool mSetFullMode();
        std::unique_ptr<IO> mIOHandle;
        std::shared_ptr<UART::UART> mUartHandle;
        control mCurrControlMode;
    };

}


