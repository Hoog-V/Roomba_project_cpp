#include <iostream>
#include <UART/UART.hpp>



int main(int argc, char **argv)
{
	UARTSettings p;
	p.DevicePath = "/dev/ttyUSB0";
	p.baudrate = UART::baud_115200;
	UART * p1 = new UART(p);
	const uint8_t bytes[] = {128,130,133};
	p1->sendBytes(bytes, std::size(bytes));
	delete p1;
	return (0);
}
