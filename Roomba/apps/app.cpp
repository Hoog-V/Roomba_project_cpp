#include <UART/UART.hpp>
#include <array>
#include "Roomba/Roomba.hpp"


int main(int argc, char **argv) {
	UART::UARTSettings p;
	p.devicePath = "/dev/ttyUSB0";
	p.baudrate = UART::Baudrates::baud_115200;
    p.connectionMethod = UART::connectionMethod::USB;
	UART::UART * p1 = UART::UART::Create(p);;
    Roomba::Roomba* rmb = new Roomba::Roomba(p1);
    rmb->setDockMode();
	return (0);
}
