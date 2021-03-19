#include "hackpro_ext.hpp"

class MyExtension : public Hackpro::Extension 
{
protected:
	void __stdcall mycallback() {}
	void __stdcall check_callback() {}
	void __stdcall uncheck_callback() {}

	void Initialise() 
	{
		using namespace Hackpro;

		this->AddButton("Bottom", callback_func(MyExtension::mycallback));
		this->AddCheckbox("Check me!", callback_func(MyExtension::check_callback), callback_func(MyExtension::uncheck_callback));
		this->AddButton("Top", callback_func(MyExtension::mycallback));
		this->Commit();
	}

public:
	static MyExtension* Create() 
	{
		using namespace Hackpro;

		auto pRet = static_cast<MyExtension*>(Extension::Create("My Extension"));
		pRet->Initialise();
		return pRet;
	}
};

DWORD WINAPI MainThread(LPVOID lpParam)
{
	if (Hackpro::Initialise())
	{
		//. . .
		//wait for MenuLayer::init(), not required but recommended until a callback is added
		//. . .

		if (Hackpro::IsReady())
		{
			auto ext = MyExtension::Create();
		}
	}

	return S_OK;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
		CreateThread(0, 0x1000, MainThread, nullptr, 0, nullptr);
	return TRUE;
}