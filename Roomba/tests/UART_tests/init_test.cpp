#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include "UARTDefines.hpp"

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws an exception when passing an empty device path
 * in the Settings parameter
 */
TEST(UART_init, EmptyDevicePath) {
    UART::UARTSettings TestSettings;
    TestSettings.devicePath = "";
    TestSettings.baudrate = TestBaud;

    EXPECT_ANY_THROW({
       UART::UART *UartHandle = new UART::UART(TestSettings);
    });
}

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws an exception when passing an empty baud rate
 * in the Settings parameter. If all goes well the baudrate should default to 115200 baud
 */
TEST(UART_init, EmptyBaudrate) {
    UART::UARTSettings TestSettings;
    TestSettings.devicePath = TestPath;

    EXPECT_NO_THROW({
        std::cout << static_cast<uint32_t>(TestSettings.baudrate) << '\n';
        UART::UART *UartHandle = new UART::UART(TestSettings);
    });
}

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws no exception when passing
 * valid UART connection settings
 */
TEST(UART_init, ValidUartSettings) {
    UART::UARTSettings TestSettings;
    TestSettings.devicePath = TestPath;
    TestSettings.baudrate = TestBaud;

    EXPECT_NO_THROW({
        UART::UART *UartHandle = new UART::UART(TestSettings);
    });
}