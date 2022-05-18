#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include "UARTDefines.hpp"


/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_ReadBytes function throws an exception when creating an out of bounds
 * situation.
 *
 * This is done by entering a bigger size (than the array which is meant to store it all)
 * in the NumOfBytes parameter of the ReadBytes function.
 */
TEST(UART_ReadBytes, OutOfBoundsCheck)
{
    UART::UARTSettings TestSettings;
    TestSettings.Baudrate = TestBaud;
    TestSettings.DevicePath = TestPath;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    std::array<uint8_t, 10> TinyBuffer;
    const uint8_t OutOfBoundsVal = 2 * TinyBuffer.size();
    EXPECT_ANY_THROW({
        UartHandle->readBytes(TinyBuffer, OutOfBoundsVal);
    });
}


/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_ReadBytes function throws an exception when passing a zero in to
 * the NumOfBytes parameter.
 */
TEST(UART_ReadBytes, numOfBytesZero)
{
    UART::UARTSettings TestSettings;
    TestSettings.Baudrate = TestBaud;
    TestSettings.DevicePath = TestPath;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    std::array<uint8_t, 10> TinyBuffer;
    EXPECT_ANY_THROW({
        UartHandle->readBytes(TinyBuffer, 0);
    });
}
