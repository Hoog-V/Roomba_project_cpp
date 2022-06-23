#ifndef UARTDEFINESHPP
#define UARTDEFINESHPP

#include "UART/UART.hpp"

const char TestPath[] = "/dev/pts/2"; //standard path for linux (virtual file descriptor)
const UART::Baudrates TestBaud = UART::Baudrates::baud_115200;
const UART::connectionMethod TestMethod = UART::connectionMethod::USB;

#endif


