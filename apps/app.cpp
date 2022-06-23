#include "UART/UART.hpp"
#include "Roomba/Roomba.hpp"


int main(int argc, char **argv) {
	UART::UARTSettings p;
	p.devicePath = "/dev/ttyUSB0";
	p.baudrate = UART::Baudrates::baud_115200;
    p.connectionMethod = UART::connectionMethod::USB;
	std::shared_ptr<UART::UART> p1 = UART::UART::Create(p);
    std::unique_ptr<Roomba::Roomba> rmb = std::make_unique<Roomba::Roomba>(p1);
    rmb->setDockMode();
	return (0);
}
