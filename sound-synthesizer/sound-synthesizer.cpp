#include "olcNoiseMaker.h"
#include "helperfunctions.h"
#include "envelope.h"
#include "instrument.h"
#include "definicje.h"

#include "bell.h"
#include "harmonijka.h"

double MakeNoise(double dTime);
void Loop(double&, double&, olcNoiseMaker<int>&);
void ShowKeyboard();

namespace
{
	atomic<double>	dFrequencyOutput = 0.0;
	double	dOcataveBaseFrequency = 110.0; // A2
	double	d12thRootOf2 = pow(2.0, 1.0 / 12.0);
	Instrument* instrument = nullptr;

}

namespace synth
{
	//////////////////////////////////////////////////////////////////////////
	// Utilities

	FTYPE w(FTYPE dHertz)
	{
		return dHertz * 2.0 * PI;
	}

	// note
	struct Note
	{
		Note()
			:
			id(0),
			on(0.0),
			off(0.0),
			active(false),
			channel(0)
		{

		}

		int id;			// pozycja w skali
		FTYPE on;		// czas w ktorym nuta została aktywowana
		FTYPE off;		// czas w ktorym nuta została dezaktywowana
		bool active;
		int channel;
	};

	FTYPE osc(FTYPE dHertz, FTYPE dTime, const int nType = OSC_SINE, FTYPE dLFOHertz = 0.0, FTYPE dLFOAmplitude = 0.0)
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

			for (FTYPE n = 1.0; n < 40.0; n++)
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
}

void Loop(double& dOcataveBaseFrequency, double& d12thRootOf2, olcNoiseMaker<int>& sound)
{
	int nCurrentKey = -1;
	bool bKeyPressed = false;
	while (1)
	{
		bKeyPressed = false;
		for (int k = 0; k < 16; k++)
		{
			if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe\xbf"[k])) & 0x8000)
			{
				if (nCurrentKey != k)
				{
					dFrequencyOutput = dOcataveBaseFrequency * pow(d12thRootOf2, k);
					instrument->env.NoteOn(sound.GetTime());
					wcout << "\rNote On : " << sound.GetTime() << "s " << dFrequencyOutput << "Hz";
					nCurrentKey = k;
				}

				bKeyPressed = true;
			}
		}

		if (!bKeyPressed)
		{
			if (nCurrentKey != -1)
			{
				wcout << "\rNote Off: " << sound.GetTime() << "s                        ";
				instrument->env.NoteOff(sound.GetTime());
				nCurrentKey = -1;
			}
		}
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

double MakeNoise(double dTime)
{
	double dOut = instrument->sound(dTime, dFrequencyOutput);

	return dOut * 0.10;
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

	instrument = new Harmonijka();

	Loop(dOcataveBaseFrequency, d12thRootOf2, sound);

	return 0;
}




