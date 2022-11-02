#include "envelope-adsr.h"

EnvelopeADSR::EnvelopeADSR()
{
	this->dAttackTime = 0.1;
	this->dDecayTime = 0.1;
	this->dSustainAmplitude = 1.0;
	this->dReleaseTime = 0.2;
	this->dStartAmplitude = 1.0;
}
EnvelopeADSR::~EnvelopeADSR()
{

}

FTYPE EnvelopeADSR::GetAmplitude(const FTYPE dTime, const FTYPE dTimeOn, const FTYPE dTimeOff)
{
	FTYPE dAmplitude = 0.0;
	FTYPE dReleaseAmplitude = 0.0;

	if (dTimeOn > dTimeOff) // Note is on
	{
		FTYPE dLifeTime = dTime - dTimeOn;

		if (dLifeTime <= dAttackTime)
			dAmplitude = (dLifeTime / dAttackTime) * dStartAmplitude;

		if (dLifeTime > dAttackTime && dLifeTime <= (dAttackTime + dDecayTime))
			dAmplitude = ((dLifeTime - dAttackTime) / dDecayTime) * (dSustainAmplitude - dStartAmplitude) + dStartAmplitude;

		if (dLifeTime > (dAttackTime + dDecayTime))
			dAmplitude = dSustainAmplitude;
	}
	else // Note is off
	{
		FTYPE dLifeTime = dTimeOff - dTimeOn;

		if (dLifeTime <= dAttackTime)
			dReleaseAmplitude = (dLifeTime / dAttackTime) * dStartAmplitude;

		if (dLifeTime > dAttackTime && dLifeTime <= (dAttackTime + dDecayTime))
			dReleaseAmplitude = ((dLifeTime - dAttackTime) / dDecayTime) * (dSustainAmplitude - dStartAmplitude) + dStartAmplitude;

		if (dLifeTime > (dAttackTime + dDecayTime))
			dReleaseAmplitude = dSustainAmplitude;

		dAmplitude = ((dTime - dTimeOff) / dReleaseTime) * (0.0 - dReleaseAmplitude) + dReleaseAmplitude;
	}

	// Amplitude should not be negative
	if (dAmplitude <= 0.000)
		dAmplitude = 0.0;

	return dAmplitude;
}




