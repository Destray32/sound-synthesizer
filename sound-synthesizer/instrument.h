#pragma once

#include "envelope.h"

struct Instrument
{
	double dVolume;
	EnvelopeADSR env;

	virtual double sound(double dTime, double dFrequency) = 0;

	void SetVolume(double vol);
};

