#include "bell.h"
#include "definicje.h"

namespace synth
{
	FTYPE osc(FTYPE, FTYPE, const int, FTYPE = 0.0, FTYPE = 0.0);
}

Bell::Bell()
{
	env.dAttackTime = 0.01;
	env.dDecayTime = 1.0;
	env.dStartAmplitude = 1.0;
	env.dSustainAmplitude = 0.0;
	env.dReleaseTime = 1.0;
	env.dTriggerOnTime = 0.0;
	env.dTriggerOffTime = 0.0;
	env.bNoteOn = false;

	// bazowa gloœnoœæ
	dVolume = 0.2;
}

double Bell::sound(double dTime, double dFrequencyOutput)
{
	double dNoise = env.GetAmplitude(dTime) *
		(
			+ 1.0 * synth::osc(dFrequencyOutput * 2.0, dTime, OSC_SINE, 5.0, 0.001)
			+ 0.5 * synth::osc(dFrequencyOutput * 3.0, dTime, OSC_SINE)
			+ 0.25 * synth::osc(dFrequencyOutput * 4.0, dTime, OSC_SINE)
		);

	return dNoise * this->dVolume;
}
