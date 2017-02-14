#include "OI.h"

#include <WPILib.h>

OI::OI()
{
	m_pDriveStick = new Joystick(0);
	// Process operator interface input here.
}

Joystick* OI::GetDriveStick()
{
	return m_pDriveStick;
}
