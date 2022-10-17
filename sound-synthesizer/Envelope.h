#pragma once
#ifndef ENVELOPE_C
#define ENVELOPE_C



struct EnvelopeADSR
{
	EnvelopeADSR();
	~EnvelopeADSR();

	double GetAmplitude(double dTime);

	void NoteOn(double dTimeOn);
	void NoteOff(double dTimeOff);



	double	dAttackTime, dDecayTime, dReleaseTime,
		dSustainAmplitude, dStartAmplitude, dTriggerOnTime,
		dTriggerOffTime;
	bool	bNoteOn;
};

#endif
