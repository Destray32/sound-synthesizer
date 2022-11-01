#pragma once

#include "instrument.h"

struct Harmonijka : public Instrument
{
	Harmonijka();

	double sound(double dTime, double dFrequency);
};

