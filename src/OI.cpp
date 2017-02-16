#include "OI.h"
//#include <windows.h> <- some men just want to watch the world burn

#include "Commands/LiftOn.h"
#include "Commands/LiftOff.h"
#include "WPILib.h"


OI::OI() {

	//Pointer initialization
	//Main Driver Joystick
	m_pJoystick1 = new Joystick(0);
	m_pJoystick2 = new Joystick(1);

	m_pButtonA1 = new JoystickButton(m_pJoystick1, 1);
	m_pButtonB1 = new JoystickButton(m_pJoystick1, 2);
	m_pButtonX1 = new JoystickButton(m_pJoystick1, 3);
	m_pButtonY1 = new JoystickButton(m_pJoystick1, 4);

	//Assistant Driver Joystick


	m_pButtonA2 = new JoystickButton(m_pJoystick2, 1);
	m_pButtonB2 = new JoystickButton(m_pJoystick2, 2);
	m_pButtonX2 = new JoystickButton(m_pJoystick2, 3);
	m_pButtonY2 = new JoystickButton(m_pJoystick2, 4);

	m_pButtonA2->WhenPressed(new LiftOn());
	m_pButtonA2->WhenReleased(new LiftOff());
}

OI::~OI()
{
	//delete them pointers yo
	delete m_pJoystick1; delete m_pJoystick2;

	delete m_pButtonA1; delete m_pButtonA2;
}
