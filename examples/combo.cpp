#include <Windows.h>
#include <iostream>

#include "extensions2.h"

DWORD MainThread(LPVOID lpParam)
{
	using namespace MegaHackExt;

	Window *window = Window::Create("Window");

	const char *strs[] = { "One", "Two", "Three", nullptr };
	ComboBox *combo = ComboBox::Create("Select: ", nullptr);
	combo->setCallback([](ComboBox *obj, int index, const char *str) { std::cout << "index " << index << " selected: " << str << '\n'; });
	combo->setValues(strs);
	window->add(combo);

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