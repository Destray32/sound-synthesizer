#pragma once
#ifndef ENVELOPE_C
#define ENVELOPE_C

#include "definicje.h"
#include "envelope.h"

struct EnvelopeADSR : public envelope
{
	EnvelopeADSR();
	~EnvelopeADSR();

	FTYPE GetAmplitude(const FTYPE dTime, const FTYPE dTimeOn, const FTYPE dTimeOff);


	FTYPE	
		dAttackTime,
		dDecayTime,
		dReleaseTime,
		dSustainAmplitude,
		dStartAmplitude;
};

#endif
