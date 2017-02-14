#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* m_pDriveStick;
	JoystickButton* m_pXButton;

	std::shared_ptr<NetworkTable> m_pNetworkTable;

public:
	OI();

	const int CAMERA_X_RES = 320;
	const int CAMERA_Y_RES = 240;

	Joystick* GetDriveStick();

	std::vector<double> GetContourValues(std::string value);
};

#endif
