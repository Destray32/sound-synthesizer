#include <windows.h>

#include "helperfunctions.h"


int SkanowaniePrzycisku(char przycisk)
{
	short	sRet = VkKeyScanEx(przycisk, 0);
	BYTE	vk = LOBYTE(sRet);

	return static_cast<int>(vk);
}