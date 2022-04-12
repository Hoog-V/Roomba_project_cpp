#include <UART/UART.hpp>
#include <Roomba/Roomba.hpp>
#include <array>
#include <crossplatform/function.hpp>

namespace Roomba{

void Roomba::setDockMode()
{
	if(mCurrControlMode == control::No_init)
		setControlMode(control::Passive);
	mUARTHandle->sendByte(command::Dock);
	mCurrControlMode = control::Passive;
}


bool Roomba::mSetPassiveMode()
{
	switch(mCurrControlMode)
	{
	case control::No_init:
	{
		mUARTHandle->sendByte(command::Start);
		SLEEP(25);
		break;
	}
	case control::Safe: case control::Full:
	{
		mUARTHandle->sendByte(command::Spot);
		SLEEP(220);
		mUARTHandle->sendByte(command::Spot);
		SLEEP(25);
		break;
	}
	default:
		return (false);
	}
	return (true);

}


bool Roomba::mSetSafeMode()
{
	if(mCurrControlMode == control::No_init)
		mSetPassiveMode();
	else if(mCurrControlMode == control::Safe)
		return (false);
	mUARTHandle->sendByte(command::Safe);
	SLEEP(25);
	return (true);
}

bool Roomba::mSetFullMode()
{
	if(mCurrControlMode != control::Safe)
		mSetSafeMode();
	else if(mCurrControlMode == control::Full)
		return (false);

	mUARTHandle->sendByte(command::Full);
	SLEEP(25);
	return (true);
}

void Roomba::setControlMode(control ControlMode)
{
	switch(ControlMode)
	{
	case control::Passive:
		if(mSetPassiveMode())
			mCurrControlMode = control::Passive;
		break;
	case control::Safe:
		if(mSetSafeMode())
			mCurrControlMode = control::Safe;
		break;
	case control::Full:
		if(mSetFullMode())
			mCurrControlMode = control::Full;
		break;
	}
}



void Roomba::startCleaning(cleaning cleaningMode)
{
	if(mCurrControlMode == control::No_init)
		setControlMode(control::Passive);

	switch(cleaningMode)
	{
	case cleaning::Spot:
		mUARTHandle->sendByte(command::Spot);
		break;
	case cleaning::Max:
		mUARTHandle->sendByte(command::Max_Clean);
		break;
	case cleaning::Clean:
		mUARTHandle->sendByte(command::Clean);
		break;
	}
	mCurrControlMode = control::Passive;
}

void Roomba::turnOff()
{
	if(mCurrControlMode == control::No_init)
		setControlMode(control::Passive);
	mUARTHandle->sendByte(command::Power);
	mCurrControlMode = control::Passive;
}

void Roomba::turnOn()
{
	;
}

void Roomba::setBaudRate(baudrate BaudRate)
{
	std::array <uint8_t, 2> commands{command::Baud, BaudRate};
	mUARTHandle->sendBytes(commands, std::size(commands));
	SLEEP(100);
	mUARTHandle->changeBaud( baud_mapping.at(BaudRate) );
}

void Roomba::setLed(uint8_t led, LedState state)
{
	bool checkControlMode = mCurrControlMode == control::Passive || mCurrControlMode == control::No_init;
	if(checkControlMode)
		setControlMode(control::Safe);
	uint8_t ledBits = state == LedState::Off ? 0 : led;
	std::array<uint8_t, 4> commands {command::Leds, ledBits , 0, 128};
	mUARTHandle->sendBytes(commands, std::size(commands));
}

void Roomba::setPowerLed(uint8_t color, uint8_t intensity)
{
	;
}


bool Roomba::mGetCurrLedState()
{
return true;
}

}
