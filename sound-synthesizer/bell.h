#pragma once

#include "instrument.h"
#include "note.h"

struct Bell : public Instrument
{
	Bell();

	double sound(const FTYPE dTime, Note n, bool& bNoteFinished);
};

