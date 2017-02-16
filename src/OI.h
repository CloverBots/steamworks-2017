#ifndef OI_H
#define OI_H
#include <WPILib.h>

class OI {
private:
	Joystick* m_pJoystick1;
	Joystick* m_pJoystick2;

	JoystickButton* m_pButtonA1,
			m_pButtonB1,
			m_pButtonX1,
			m_pButtonY1;
	JoystickButton* m_pButtonA2,
			m_pButtonB2,
			m_pButtonX2,
			m_pButtonY2;

public:
	OI();
	~OI();

	//Joysticks and joystick button. Y'all can just use my oi for everything if you want.
	//I'm going to define and initialize the four main buttons. I know that the shooter
	//and the toploading-washing machine thing will probably use WhenPressed/WhenReleased

	Joystick* getJoystick1() { return m_pJoystick1; }
	Joystick* getJoystick2() { return m_pJoystick2; }


};

#endif  // OI_H
