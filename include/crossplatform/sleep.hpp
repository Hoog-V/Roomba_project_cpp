#pragma once


#if defined(__linux__) || defined(__APPLE__) || defined(_WIN32) || defined(_WIN64)

#include <chrono>

#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#elif defined(ESP32)
#define SLEEP(ms) vTaskDelay(ms/portTICK_PERIOD_MS);
#endif
