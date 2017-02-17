#ifndef OI_H
#define OI_H
#include <WPILib.h>

class OI {
private:
	Joystick* m_pAccessoryStick;

public:
	OI();
	Joystick* GetJoystick();
};

#endif  // OI_H
