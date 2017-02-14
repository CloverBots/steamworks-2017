#include "OI.h"
#include "Commands/ShootSequence.h"
#include "Commands/StopShooting.h"
Joystick* OI::GetStick1()
{
	return pStick1;
}

OI::OI()
{
	pStick1 = new Joystick(0);
	aButton = new JoystickButton(pStick1, 1);
	aButton->WhenPressed(new ShootSequence());
	aButton->WhenReleased(new StopShooting());
	// Process operator interface input here.
}
OI::~OI()
{
	delete pStick1;
}
