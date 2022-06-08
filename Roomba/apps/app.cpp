#include <UART/PC/UARTPC.hpp>
#include <array>


int main(int argc, char **argv) {
	UART::UARTSettings p;
	p.devicePath = "COM6";
	p.baudrate = UART::Baudrates::baud_115200;
    p.connectionMethod = UART::connectionMethod::USB;
	UART::UART * p1 = UART::UART::Create(p);;
	delete p1;
	return (0);
}
