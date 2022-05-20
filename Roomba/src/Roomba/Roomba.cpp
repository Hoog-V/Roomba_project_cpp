#include <UART/UART.hpp>
#include <Roomba/Roomba.hpp>
#include <array>
#include <crossplatform/function.hpp>

namespace Roomba{
/// Roomba Dockmode which makes the Roomba go to his docking station.
///
/// This is the detailed description, more stuff here. 
void Roomba::setDockMode()
{
	/// @param A this discribes parameter A
	/// @param B this discribes parameter B
	/// @returns nothing important
	/// @see anotherfunction() anotherfunction2()
	/// @note a little side note
	/// @attention a little more important than a note
	/// @warning a warning is super important! 
	
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

void Roomba::setBaudRate(UART::Baudrates BaudRate)
{
    const uint8_t BaudCMD = static_cast<uint8_t>(BaudRate)-1; // -1 because commands are shifted by one to allow invalid
                                                              // baudrate checking.
    if(BaudCMD == 0 || BaudCMD > 12)
        throw std::invalid_argument("Invalid BaudRate or pointer passed in to parameter BaudRate");

	std::array <uint8_t, 2> commands{command::Baud, BaudCMD};
	mUARTHandle->sendBytes(commands, std::size(commands));
	SLEEP(100);
	mUARTHandle->changeBaud(BaudRate);
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
