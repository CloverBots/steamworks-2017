#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* m_pDriveStick;
public:
	OI();


	Joystick* GetDriveStick();
};

#endif  // OI_H
