
#include <stdio.h>
#include <windows.h>

#include "ketypes.h"
#include "parallel.h"

#ifndef _CRTAPI1
#define _CRTAPI1 __cdecl
#endif

int _CRTAPI1 main ()
{
	HANDLE hLPT;
	PARCLASS_NEGOTIATION_MASK Mode;
	DWORD dwRet;

	hLPT = CreateFile ("LPT1:", GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, 0, NULL);
	if (hLPT == INVALID_HANDLE_VALUE) {
		puts ("Port open error.");
		return 0;
	}
	puts ("Port is opened successfully.");
	if (!DeviceIoControl (hLPT, IOCTL_IEEE1284_GET_MODE, NULL, 0,
		&Mode, sizeof (Mode), &dwRet, NULL)) {
			puts ("DeviceIoControl() failed.");
	}
	puts ("Closing port.");
	CloseHandle (hLPT);
	return 0;
}
