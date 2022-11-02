#pragma once

#include "definicje.h"
#include "envelope-adsr.h"

#include "note.h"

struct Instrument
{
	FTYPE dVolume;
	EnvelopeADSR env;

	virtual FTYPE sound(const FTYPE dTime, Note n, bool& bNoteFinished) = 0;

	void SetVolume(double vol);
};

