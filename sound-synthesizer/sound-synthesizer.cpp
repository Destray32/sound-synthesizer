#include "olcNoiseMaker.h"
#include "helperfunctions.h"
#include "Envelope.h"

double MakeNoise(double dTime);
double w(double);
double osc(double, double, int);

void Loop(double&, double&, olcNoiseMaker<int>&);
void ShowKeyboard();

namespace
{
	atomic<double>	dFrequencyOutput = 0.0;
	EnvelopeADSR envelope;
	double	dOcataveBaseFrequency = 110.0; // A2
	double	d12thRootOf2 = pow(2.0, 1.0 / 12.0);

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

	Loop(dOcataveBaseFrequency, d12thRootOf2, sound);

	return 0;
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
					envelope.NoteOn(sound.GetTime());
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
				envelope.NoteOff(sound.GetTime());
				nCurrentKey = -1;
			}
		}
	}
}

double MakeNoise(double dTime)
{
	double dNoise = envelope.GetAmplitude(dTime) * osc(dFrequencyOutput, dTime, 4);

	return dNoise * 0.2;
}

double w(double dHertz)
{
	return dHertz * 2.0 * PI;
}

double osc(double dHertz, double dTime, int nType)
{
	switch (nType)
	{
		// Fala sinusoidalna
	case 0:
		return sin(w(dHertz) * dTime);
		break;
	case 1: // Fala kwadratowa
		return sin(w(dHertz) * dTime) > 0.0 ? 1.0 : -1.0;
		break;
	case 2: // Fala trójkątna
		return asin(sin(w(dHertz) * dTime)) * 2.0 / PI;
		break;
	case 3: // Fala piłowa (saw wave), wersja niezoptymalizowana
	{
		double dOutput = 0.0;

		for (double n = 1.0; n < 100.0; n++)
		{
			dOutput += (sin(n * w(dHertz) * dTime)) / n;
		}
		return dOutput * (2.0 * PI);
		break;
	}
	case 4: // Saw wave zoptymalizowana
		return (2.0 / PI) * (dHertz * PI * fmod(dTime, 1.0 / dHertz) - (2.0 * PI));
		break;
	case 5: // Pseudo randomowe dźwięki
		break;
	default:
		return 0.0;
		break;
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




