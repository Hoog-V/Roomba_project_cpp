#include <iostream>
#include <UART/UART.hpp>
#include <unistd.h>
#include <thread>
#include <algorithm>
#include <array>
#include <Roomba/Roomba.hpp>
#include <crossplatform/function.hpp>

int main(int argc, char **argv)
{
	UARTSettings p;
	p.DevicePath = "/dev/ttyUSB0";
	p.baudrate = UART::baud_115200;
	UART * p1 = new UART(p);
	Roomba::Roomba* rmb = new Roomba::Roomba(p1);
	rmb->setDockMode();
	delete p1;
	return (0);
}
