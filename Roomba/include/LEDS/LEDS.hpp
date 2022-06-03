#pragma once

#include <Roomba/Roomba.hpp>
#include <crossplatform/function.hpp>


 enum leds : uint8_t {
        LED_Debris = 1, LED_Spot = 2, LED_Dock = 4, LED_Check_Robot = 8
    };

    enum command : uint8_t {
        Leds, Schedule_Leds = 162, Digit_Leds_Raw, Digit_Leds_Ascii,
    };


    enum class LedState {
        On, Off
    };

    class LEDS {
        public: 
        void setLed(uint8_t led, LedState state);

        void setPowerLed(uint8_t color, uint8_t intensity);
    }