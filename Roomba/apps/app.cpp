#include <iostream>
#include <UART/UART.hpp>
#include <thread>
#include <algorithm>
#include <array>
#include <Roomba/Roomba.hpp>
#include <crossplatform/function.hpp>

int main(int argc, char **argv)
{
	UARTSettings p;
	p.DevicePath = "COM3";
	p.baudrate = baudrates::baud_115200;
	UART * p1 = new UART(p);
	Roomba::Roomba* rmb = new Roomba::Roomba(p1);
	//rmb->setDockMode();
	rmb->setLed(Roomba::leds::LED_Dock, Roomba::LedState::On);
	rmb->setControlMode(Roomba::control::Passive);
	delete p1;
	return (0);
}
