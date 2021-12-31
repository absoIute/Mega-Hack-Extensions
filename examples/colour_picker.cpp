#include <Windows.h>
#include <iostream>
#include <iomanip>

#include "extensions2.h"

DWORD MainThread(LPVOID lpParam)
{
	using namespace MegaHackExt;

	Window *window = Window::Create("Window");

	ColourPicker *picker = ColourPicker::Create({ 238, 119, 98 });
	picker->setCallback([](ColourPicker *, Colour col) { std::cout << std::hex << std::setfill('0') << std::setw(2) << col.r << col.g << col.b << '\n'; });
	window->add(picker);

	Client::commit(window);

	return S_OK;
}

DWORD DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0x1000, reinterpret_cast<LPTHREAD_START_ROUTINE>(&MainThread), NULL, 0, NULL);
		break;

	default:
		break;
	}

	return TRUE;
}