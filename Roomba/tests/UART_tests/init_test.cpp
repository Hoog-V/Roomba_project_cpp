#include <gtest/gtest.h>
#include <UART/UART.hpp>

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws an exception when passing an empty device path
 * in the Settings parameter
 */
TEST(UART_init, EmptyDevicePath)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "";
    TestSettings.baudrate = UART::baud_115200;

    EXPECT_ANY_THROW({
        UART* UartHandle = new UART(TestSettings);
    });
}

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws an exception when passing an empty baud rate
 * in the Settings parameter
 */
TEST(UART_init, EmptyBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";

    EXPECT_ANY_THROW({
        UART* UartHandle = new UART(TestSettings);
    });
}

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws an exception when passing an invalid baud rate
 * in the Settings parameter
 */
TEST(UART_init, InvalidBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    TestSettings.baudrate = std::rand() % 100; //Random number between 0 and 100

    EXPECT_ANY_THROW({
        UART* UartHandle = new UART(TestSettings);
    });
}

/**
 * Tests if UART constructor checks its parameters
 * This test in particular tests if the UART constructor function throws no exception when passing
 * valid UART connection settings
 */
TEST(UART_init, ValidUartSettings)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    TestSettings.baudrate = UART::baud_115200;

    EXPECT_NO_THROW({
        UART* UartHandle = new UART(TestSettings);
    });
}