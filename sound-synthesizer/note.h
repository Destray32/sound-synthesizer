#pragma once

#include "definicje.h"

struct Note
{
	Note();

	int id;			// pozycja w skali
	FTYPE on;		// czas w ktorym nuta zosta³a aktywowana
	FTYPE off;		// czas w ktorym nuta zosta³a dezaktywowana
	bool active;
	int channel;
};
