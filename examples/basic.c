#include "hackpro_ext.h"

void __stdcall mycallback(void *aaa) {}
void __stdcall check_callback(void *cb) {}
void __stdcall uncheck_callback(void *cb) {}

DWORD WINAPI MainThread(LPVOID lpParam)
{
	if (InitialiseHackpro())
	{
		//. . .
		//wait for MenuLayer::init(), not required but recommended until a callback is added
		//. . .

		if (HackproIsReady())
		{
			void *ext = HackproInitialiseExt("My Extension");
			HackproAddButton(ext, "Bottom", mycallback);
			HackproAddCheckbox(ext, "Check me!", check_callback, uncheck_callback);
			HackproAddButton(ext, "Top", mycallback);
			HackproCommitExt(ext);
		}
	}

	return S_OK;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
		CreateThread(0, 0x1000, MainThread, NULL, 0, NULL);
	return TRUE;
}
