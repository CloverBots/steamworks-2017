#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* pStick1;
	JoystickButton* aButton;
public:
	Joystick* GetStick1();
	OI();
	~OI();
};

#endif
