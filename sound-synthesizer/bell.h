#pragma once

#include "instrument.h"

struct Bell : public Instrument
{
	Bell();

	double sound(double dTime, double dFrequency);
};

