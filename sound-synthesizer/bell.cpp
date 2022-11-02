#include "bell.h"
#include "definicje.h"


namespace synth
{
	FTYPE osc(const FTYPE dTime, const FTYPE dHertz, const int nType = OSC_SINE,
		const FTYPE dLFOHertz = 0.0, const FTYPE dLFOAmplitude = 0.0, FTYPE dCustom = 50.0);
	FTYPE env(const FTYPE dTime, envelope& env, const FTYPE dTimeOn, const FTYPE dTimeOff);
	FTYPE scale(const int nNoteID, const int nScaleID = 0);
}

Bell::Bell()
{
	env.dAttackTime = 0.01;
	env.dDecayTime = 0.5;
	env.dSustainAmplitude = 0.8;
	env.dReleaseTime = 1.0;

	// bazowa gloœnoœæ
	dVolume = 0.5;
}

double Bell::sound(const FTYPE dTime, Note n, bool& bNoteFinished)
{
	FTYPE dAmplitude = synth::env(dTime, env, n.on, n.off);
	if (dAmplitude <= 0.0)
		bNoteFinished = true;
	
	FTYPE dSound = 
		+ 1.00 * synth::osc(n.on - dTime, synth::scale(n.id + 12), OSC_SINE, 5.0, 0.001)
		+ 0.50 * synth::osc(n.on - dTime, synth::scale(n.id + 24))
		+ 0.25 * synth::osc(n.on - dTime, synth::scale(n.id + 24));

	return dAmplitude * dSound * dVolume;
}
