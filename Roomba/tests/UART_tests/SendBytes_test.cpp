#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include <UARTDefines.hpp>
#include <array>


/**
 * Tests if UART_SendBytes function checks its parameters
 * This test in particular tests if the UART_SendBytes function throws an exception when creating an out of bounds
 * situation.
 *
 * This is done by entering a bigger size (than the array which stores the bytes to send)
 * in the NumOfBytes parameter of the SendBytes function.
 */
TEST(UART_SendBytes, OutOfBoundsCheck) {
    UART::UARTSettings TestSettings;
    TestSettings.baudrate = TestBaud;
    TestSettings.devicePath = TestPath;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    std::array<uint8_t, 10> TestCommands;
    TestCommands.fill(0);

    const uint8_t OutOfBoundsVal = 2 * TestCommands.size();

    EXPECT_ANY_THROW({
        UartHandle->sendBytes(TestCommands, OutOfBoundsVal);
    });
}


/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_SendBytes function throws an exception when passing a zero in to
 * the NumOfBytes parameter.
 */
TEST(UART_SendBytes, numOfBytesZero) {
    UART::UARTSettings TestSettings;
    TestSettings.baudrate = TestBaud;
    TestSettings.devicePath = TestPath;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    std::array<uint8_t, 10> TestCommands;
    TestCommands.fill(0);
    EXPECT_ANY_THROW({
        UartHandle->sendBytes(TestCommands, 0);
    });
}