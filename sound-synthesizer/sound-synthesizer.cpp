#include "olcNoiseMaker.h"
#include "helperfunctions.h"
#include "definicje.h"

#include "envelope.h"
#include "note.h"

#include "instrument.h"

#include "bell.h"

FTYPE MakeNoise(int nChannel, FTYPE dTime);
void ShowKeyboard();

namespace
{
	vector<Note> vecNotes;
	mutex muxNotes;
	Bell bell;
}

namespace synth
{
	//////////////////////////////////////////////////////////////////////////
	// Utilities

	FTYPE w(FTYPE dHertz)
	{
		return dHertz * 2.0 * PI;
	}

	FTYPE osc(const FTYPE dTime, const FTYPE dHertz, const int nType = OSC_SINE,
		const FTYPE dLFOHertz = 0.0, const FTYPE dLFOAmplitude = 0.0, FTYPE dCustom = 50.0)
	{
		FTYPE dFreq = w(dHertz) * dTime + dLFOAmplitude * dHertz * sin(w(dLFOHertz) * dTime);

		switch (nType)
		{
		case OSC_SINE: // Fala sinusoidalna
			return sin(dFreq);

		case OSC_SQUARE: // Fala kwadratowa
			return sin(dFreq) > 0.0 ? 1.0 : -1.0;

		case OSC_TRIANGLE: // Fala trójkątna
			return asin(sin(dFreq) * 2.0 / PI);

		case OSC_SAW_ANA: // Fala piłowa (saw wave), wersja analogowa
		{
			FTYPE dOutput = 0.0;

			for (FTYPE n = 1.0; n < dCustom; n++)
			{
				dOutput += (sin(n * dFreq)) / n;
			}
			return dOutput * (2.0 * PI);
		}

		case OSC_SAW_DIG: // Saw wave wersja cyfrowa
			return 2.0 * (dFreq / PI - floor((dFreq / PI) + 0.5));

		case OSC_NOISE: // Pseudo randomowe dźwięki
			return 2.0 * ((FTYPE)rand() / (FTYPE)RAND_MAX) - 1.0;

		default:
			return 0.0;

		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// Scale to Frequency conversion

	const int SCALE_DEFAULT = 0;

	FTYPE scale(const int nNoteID, const int nScaleID = SCALE_DEFAULT)
	{
		switch (nScaleID)
		{
		case SCALE_DEFAULT: default:
			return 256 * pow(1.0594630943592952645618252949463, nNoteID);
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// Envelope amplitude
	FTYPE env(const FTYPE dTime, envelope& env, const FTYPE dTimeOn, const FTYPE dTimeOff)
	{
		return env.GetAmplitude(dTime, dTimeOn, dTimeOff);
	}
}


void ShowKeyboard()
{
	wcout << endl <<
		"|   |   |   |   |   | |   |   |   |   | |   | |   |   |   |" << endl <<
		"|   | S |   |   | F | | G |   |   | J | | K | | L |   |   |" << endl <<
		"|   |___|   |   |___| |___|   |   |___| |___| |___|   |   |__" << endl <<
		"|     |     |     |     |     |     |     |     |     |     |" << endl <<
		"|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |" << endl <<
		"|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;

}

typedef bool(*lambda)(Note const& item);
template<class T>
void safe_remove(T& v, lambda f)
{
	auto n = v.begin();
	while (n != v.end())
		if (!f(*n))
			n = v.erase(n);
		else
			++n;
}

FTYPE MakeNoise(int nChannel, FTYPE dTime)
{
	unique_lock<mutex> lm(muxNotes);
	FTYPE dMixedOutput = 0.0;

	for (auto& n : vecNotes)
	{
		bool bNoteFinished = false;
		FTYPE dSound = 0;
		if (n.channel == 2)
			dSound = bell.sound(dTime, n, bNoteFinished);
		dMixedOutput += dSound;

		if (bNoteFinished && n.off > n.on)
			n.active = false;
	}

	safe_remove<vector<Note>>(vecNotes, [](Note const& item) { return item.active; });

	return dMixedOutput * 0.2;
}

int main()
{
	ShowKeyboard();

	// wydobadz wszystkie odbiorniki
	vector<wstring> devices = olcNoiseMaker<int>::Enumerate();

	// Stworz sound machine
	olcNoiseMaker<int> sound(devices[0], 44100, 1, 8, 512);

	// Linkowanie funkcji do obiektu
	sound.SetUserFunction(MakeNoise);

	char keyboard[129];
	memset(keyboard, ' ', 127);
	keyboard[128] = '\0';

	auto clock_old_time = chrono::high_resolution_clock::now();
	auto clock_real_time = chrono::high_resolution_clock::now();
	double dElapsedTime = 0.0;

	while (1)
	{
		for (int k = 0; k < 16; k++)
		{
			short nKeyState = GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe\xbf"[k]));

			double dTimeNow = sound.GetTime();

			// Check if note already exists in currently playing notes
			muxNotes.lock();
			auto noteFound = find_if(vecNotes.begin(), vecNotes.end(), [&k](Note const& item) { return item.id == k; });
			if (noteFound == vecNotes.end())
			{
				// Note not found in vector

				if (nKeyState & 0x8000)
				{
					// Key has been pressed so create a new note
					Note n;
					n.id = k;
					n.on = dTimeNow;
					n.channel = 2;
					n.active = true;

					// Add note to vector
					vecNotes.emplace_back(n);
				}
				else
				{
					// Note not in vector, but key has been released...
					// ...nothing to do
				}
			}
			else
			{
				// Note exists in vector
				if (nKeyState & 0x8000)
				{
					// Key is still held, so do nothing
					if (noteFound->off > noteFound->on)
					{
						// Key has been pressed again during release phase
						noteFound->on = dTimeNow;
						noteFound->active = true;
					}
				}
				else
				{
					// Key has been released, so switch off
					if (noteFound->off < noteFound->on)
					{
						noteFound->off = dTimeNow;
					}
				}
			}
			muxNotes.unlock();
		}
		wcout << "\rNotes: " << vecNotes.size() << "    ";
	}

	return 0;
}




