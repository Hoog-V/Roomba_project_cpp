#include <gtest/gtest.h>
#include <UART/UART.hpp>

/**
 * Tests if UART_init function checks its parameters
 * This test in particular tests if the UART_init function throws an exception when passing an empty devicepath
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
 * Tests if UART_init function checks its parameters
 * This test in particular tests if the UART_init function throws an exception when passing an empty baudrate
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
 * Tests if UART_init function checks its parameters
 * This test in particular tests if the UART_init function throws an exception when passing an invalid baudrate
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
 * Tests if UART_init function checks its parameters
 * This test in particular tests if the UART_init function throws no exception when passing
 * valid UART connection Settings
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