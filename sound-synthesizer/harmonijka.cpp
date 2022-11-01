#include "harmonijka.h"
#include "definicje.h"

namespace synth
{
	FTYPE osc(FTYPE, FTYPE, const int, FTYPE = 0.0, FTYPE = 0.0);
}



Harmonijka::Harmonijka()
{
	env.dAttackTime = 0.1;
	env.dDecayTime = 0.01;
	env.dStartAmplitude = 1.0;
	env.dSustainAmplitude = 0.8;
	env.dReleaseTime = 0.2;
	env.dTriggerOnTime = 0.0;
	env.dTriggerOffTime = 0.0;
	env.bNoteOn = false;

	// bazowa gloœnoœæ
	dVolume = 0.2;
}

double Harmonijka::sound(double dTime, double dFrequencyOutput)
{
	double dOut = env.GetAmplitude(dTime) *
		(
			+1.0 * synth::osc(dFrequencyOutput * 2.0, dTime, OSC_SQUARE, 5.0, 0.001)
			+ 0.5 * synth::osc(dFrequencyOutput * 3.0, dTime, OSC_SQUARE)
			+ 0.25 * synth::osc(dFrequencyOutput * 4.0, dTime, OSC_NOISE)
		);

	return dOut * this->dVolume;
}
