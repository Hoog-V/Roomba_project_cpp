#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include <UARTDefines.hpp>
#include <array>


/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_SendBytes function throws an exception when passing a zero in to
 * the NumOfBytes parameter.
 */
TEST(UART_SendBytes, numOfBytesZero) {
    UART::UARTSettings TestSettings;
    TestSettings.baudrate = TestBaud;
    TestSettings.devicePath = TestPath;
    TestSettings.connectionMethod = TestMethod;

    UART::UART *UartHandle = UART::UART::Create(TestSettings);

    std::array<uint8_t, 10> TestCommands;
    TestCommands.fill(0);
    EXPECT_ANY_THROW({
        UartHandle->sendBytes(TestCommands.data(), 0);
    });
}