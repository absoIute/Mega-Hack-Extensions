#ifndef HACKPRO_EXT_HPP
#define HACKPRO_EXT_HPP

#define HP_IMPORT _cdecl

#include <windows.h>

namespace Hackpro {
	inline HMODULE hMod;
	inline bool(HP_IMPORT* IsReady)() = nullptr;

	inline bool Initialise() {

		if (hMod = GetModuleHandleA("hackpro.dll")) {
			IsReady = reinterpret_cast<decltype(IsReady)>(GetProcAddress(hMod, "?HackproIsReady@@YA_NXZ"));
			return IsReady;
		}
		return false;
	}

	class Extension;
	class Checkbox;
	class ComboBox;
	class TextBox;

	using Callback = void(__stdcall Extension::*)();
	using ComboBoxCallback = void(__stdcall Extension::*)(int, const char*);

	#define callback_func(func) reinterpret_cast<Callback>(&func)
	#define combobox_callback_func(func) reinterpret_cast<ComboBoxCallback>(&func)

	class Extension {
	private:
		Extension() {}

	public:
		static Extension* Create(const char* title) {
			return reinterpret_cast<Extension* (HP_IMPORT*)(const char*)>(
				GetProcAddress(hMod, "?HackproInitialiseExt@@YAPAXPBD@Z")
				)(title);
		}

	public:
		bool AddButton(const char* caption, Callback callback) {
			return reinterpret_cast<bool(HP_IMPORT*)(Extension*, const char*, Callback)>(
				GetProcAddress(hMod, "?HackproAddButton@@YA_NPAXPBDP6GX0@Z@Z")
				)(this, caption, callback);
		}
		Checkbox* AddCheckbox(const char* caption, Callback checked, Callback unchecked) {
			return reinterpret_cast<Checkbox* (HP_IMPORT*)(Extension*, const char*, Callback, Callback)>(
				GetProcAddress(hMod, "?HackproAddCheckbox@@YAPAXPAXPBDP6GX0@Z2@Z")
				)(this, caption, checked, unchecked);
		}
		ComboBox* AddComboBox(ComboBoxCallback callback) {
			return reinterpret_cast<ComboBox* (HP_IMPORT*)(Extension*, ComboBoxCallback)>(
				GetProcAddress(hMod, "?HackproAddComboBox@@YAPAXPAXP6GX0HPBD@Z@Z")
				)(this, callback);
		}
		TextBox* AddTextBox(Callback callback) {
			return reinterpret_cast<TextBox* (HP_IMPORT*)(Extension*, Callback)>(
				GetProcAddress(hMod, "?HackproAddTextBox@@YAPAXPAXP6GX0@Z@Z")
				)(this, callback);
		}
		bool Commit() {
			return reinterpret_cast<bool(HP_IMPORT*)(Extension*)>(
				GetProcAddress(hMod, "?HackproCommitExt@@YA_NPAX@Z")
				)(this);
		}
		bool Withdraw() {
			return reinterpret_cast<bool(HP_IMPORT*)(Extension*)>(
				GetProcAddress(hMod, "?HackproWithdrawExt@@YA_NPAX@Z")
				)(this);
		}
		void SetUserData(void* data) {
			return reinterpret_cast<void(HP_IMPORT*)(Extension*, void*)>(
				GetProcAddress(hMod, "?HackproSetUserData@@YAXPAX0@Z")
				)(this, data);
		}
		void* GetUserData() {
			return reinterpret_cast<void* (HP_IMPORT*)(Extension*)>(
				GetProcAddress(hMod, "?HackproGetUserData@@YAPAXPAX@Z")
				)(this);
		}
	};

	class Checkbox {
	private:
		Checkbox() {}

	public:
		bool SetState(bool state) {
			return reinterpret_cast<bool(HP_IMPORT*)(Checkbox*, bool)>(
				GetProcAddress(hMod, "?HackproSetCheckbox@@YA_NPAX_N@Z")
				)(this, state);
		}
		void SetUserData(void* data) {
			return reinterpret_cast<void(HP_IMPORT*)(Checkbox*, void*)>(
				GetProcAddress(hMod, "?HackproSetUserData@@YAXPAX0@Z")
				)(this, data);
		}
		void* GetUserData() {
			return reinterpret_cast<void* (HP_IMPORT*)(Checkbox*)>(
				GetProcAddress(hMod, "?HackproGetUserData@@YAPAXPAX@Z")
				)(this);
	};

	class ComboBox {
	private:
		ComboBox() {}

	public:
		bool SetStrings(const char* strings[]) {
			return reinterpret_cast<bool(HP_IMPORT*)(ComboBox*, const char*[])>(
				GetProcAddress(hMod, "?HackproSetComboBoxStrs@@YA_NPAXPAPBD@Z")
				)(this, strings);
		}
		bool SetIndex(int index) {
			return reinterpret_cast<bool(HP_IMPORT*)(ComboBox*, int)>(
				GetProcAddress(hMod, "?HackproSetComboBoxIndex@@YA_NPAXH@Z")
				)(this, index);
		}
		void SetUserData(void* data) {
			return reinterpret_cast<void(HP_IMPORT*)(ComboBox*, void*)>(
				GetProcAddress(hMod, "?HackproSetUserData@@YAXPAX0@Z")
				)(this, data);
		}
		void* GetUserData() {
			return reinterpret_cast<void* (HP_IMPORT*)(ComboBox*)>(
				GetProcAddress(hMod, "?HackproGetUserData@@YAPAXPAX@Z")
				)(this);
		}
	};

	class TextBox {
	private:
		TextBox() {}

	public:
		bool SetText(const char* text) {
			return reinterpret_cast<bool(HP_IMPORT*)(TextBox*, const char*)>(
				GetProcAddress(hMod, "?HackproSetTextBoxText@@YA_NPAXPBD@Z")
				)(this, text);
		}
		bool SetPlaceholder(const char* text) {
			return reinterpret_cast<bool(HP_IMPORT*)(TextBox*, const char*)>(
				GetProcAddress(hMod, "?HackproSetTextBoxPlaceholder@@YA_NPAXPBD@Z")
				)(this, text);
		}
		const char* GetText() {
			return reinterpret_cast<const char* (HP_IMPORT*)(TextBox*)>(
				GetProcAddress(hMod, "?HackproGetTextBoxText@@YAPBDPAX@Z")
				)(this);
		}
		void SetUserData(void* data) {
			return reinterpret_cast<void(HP_IMPORT*)(TextBox*, void*)>(
				GetProcAddress(hMod, "?HackproSetUserData@@YAXPAX0@Z")
				)(this, data);
		}
		void* GetUserData() {
			return reinterpret_cast<void* (HP_IMPORT*)(TextBox*)>(
				GetProcAddress(hMod, "?HackproGetUserData@@YAPAXPAX@Z")
				)(this);
		}
	};
}

#endif