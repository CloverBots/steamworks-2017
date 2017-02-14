/*
 * CANPIDSource.h
 *
 *  Created on: Dec 19, 2016
 *      Author: Mackinnon Buck
 */

#ifndef SRC_CANPIDSOURCE_H_
#define SRC_CANPIDSOURCE_H_

#include "WPILib.h"

class CANPIDSource : public PIDSource
{
private:

	CANTalon* m_pTalon;
	double m_range;

public:
	CANPIDSource(CANTalon* pTalon, double range);
	virtual ~CANPIDSource();

	virtual double PIDGet();
};

#endif /* SRC_CANPIDSOURCE_H_ */
