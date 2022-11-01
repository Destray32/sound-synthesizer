#include "Envelope.h"

EnvelopeADSR::EnvelopeADSR()
{

}
EnvelopeADSR::~EnvelopeADSR()
{

}

double EnvelopeADSR::GetAmplitude(double dTime)
{
	double dAmplitude = 0.0;
	double dLifeTime = dTime - this->dTriggerOnTime;

	if (bNoteOn)
	{
		// ADS (Attack, decay, sustain)

		// Attack
		if (dLifeTime <= this->dAttackTime)
			dAmplitude = (dLifeTime / this->dAttackTime) * this->dStartAmplitude;
		
		// Decay
		if (dLifeTime > this->dAttackTime && dLifeTime <= (this->dAttackTime + this->dDecayTime))
			dAmplitude = ((dLifeTime - dAttackTime) / dDecayTime) * (dSustainAmplitude - dStartAmplitude) + dStartAmplitude;

		// Sustain
		if (dLifeTime > (this->dAttackTime + this->dDecayTime))
		{
			dAmplitude = this->dSustainAmplitude;
		}
	}
	else
	{
		// R (Release)
		dAmplitude = ((dTime - dTriggerOffTime) / dReleaseTime) * (0.0 - dSustainAmplitude) + dSustainAmplitude;
	}

	if (dAmplitude <= 0.0001)
	{
		dAmplitude = 0.0;
	}

	return dAmplitude;
}

void EnvelopeADSR::NoteOn(double dTimeOn)
{
	this->dTriggerOnTime = dTimeOn;
	this->bNoteOn = true;
}

void EnvelopeADSR::NoteOff(double dTimeOff)
{
	this->dTriggerOffTime = dTimeOff;
	this->bNoteOn = false;
}



