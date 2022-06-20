#pragma once

#include <array>

#if defined(__linux__) || defined(__APPLE__) || defined(_WIN32) || defined(_WIN64)

#include <chrono>

#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#elif defined(ESP32)
#define SLEEP(ms) vTaskDelay(ms/portTICK_PERIOD_MS);
#endif

template<typename T, std::size_t size>
constexpr int16_t convert_to_signed_short(const std::array<T, size> &buf) {
    try {
#if(defined(LITTLE_ENDIAN) || !defined(BIG_ENDIAN))
        return ((static_cast<uint16_t>(buf.at(0)) << 8) |
                (static_cast<uint16_t>(buf.at(1))));
#elif (defined(BIG_ENDIAN))
        return ((static_cast<uint16_t>(unsigned short)buf[0]) |
               ((static_cast<uint16_t>(unsigned short)buf[1]) << 8);
# else
#error *** You have an Unsupported compiler or mixed-endian system set as compilation target ->
                         This library requires either an little or big-endian target***
#endif
    }
    catch (std::out_of_range const &exc) {
        std::terminate();
    }
    return 0;
}
