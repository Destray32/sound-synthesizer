#pragma once

#include "definicje.h"

struct envelope
{
	virtual FTYPE GetAmplitude(const FTYPE dTime, const FTYPE dTimeOn, const FTYPE dTimeOff) = 0;
};

