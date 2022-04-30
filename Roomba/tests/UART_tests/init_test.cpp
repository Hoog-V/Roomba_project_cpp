//
// Created by victor on 30-4-22.
//

#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include <cstdlib>

TEST(UART_init, EmptyDevicePath){
    UARTSettings p;
    p.DevicePath = "COM1";
    EXPECT_ANY_THROW({
        UART* u = new UART(p);
    });
}

TEST(UART_init, EmptyBaudrate){
    UARTSettings p;
    p.DevicePath = "";
    p.baudrate = UART::baud_115200;
    EXPECT_ANY_THROW({
        UART* u = new UART(p);
    });
}

TEST(UART_init, InvalidBaudrate){
    UARTSettings p;
    p.DevicePath = "COM1";
    p.baudrate = rand() % 100; //Random number between 0 and 100
    EXPECT_ANY_THROW({
        UART* u = new UART(p);
    });
    p.baudrate = UART::baud_115200;
    EXPECT_NO_THROW({
        UART* u = new UART(p);
    });
}

TEST(UART_init, ValidUartSettings){
    UARTSettings p;
    p.DevicePath = "COM1";
    p.baudrate = UART::baud_115200;
    EXPECT_NO_THROW({
        UART* u = new UART(p);
    });
}