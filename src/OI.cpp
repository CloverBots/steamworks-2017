#include "OI.h"

#include <WPILib.h>

OI::OI()
{
	m_pAccessoryStick = new Joystick(1);
}

Joystick* OI::GetJoystick()
{
	return m_pAccessoryStick;
}
