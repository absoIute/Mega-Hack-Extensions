#pragma once

#define MH_DLL __declspec(dllimport)
#define MH_CALL __stdcall

namespace MegaHackExt
{
	struct Colour { unsigned char r, g, b; };

	namespace Client
	{
		void MH_DLL setModEnabled(const char *str, bool b);
		bool MH_DLL getModEnabled(const char *str);

		void MH_DLL commit(void *ptr);
	}

	class MH_DLL Window
	{
	public:
		Window() = delete;
		Window(const Window &) = delete;
		Window &operator=(const Window &) = delete;
		~Window() = delete;

		static Window *Create(const char *title);

		void add(void *obj);
	};

	class MH_DLL HorizontalLayout
	{
	public:
		HorizontalLayout() = delete;
		HorizontalLayout(const HorizontalLayout &) = delete;
		HorizontalLayout &operator=(const HorizontalLayout &) = delete;
		~HorizontalLayout() = delete;

		static HorizontalLayout *Create(void *left, void *right);
	};

	class MH_DLL Label
	{
	public:
		Label() = delete;
		Label(const Label &) = delete;
		Label &operator=(const Label &) = delete;
		~Label() = delete;

		static Label *Create(const char *str);

		void set(const char *str);
	};

	class MH_DLL Button
	{
		typedef void (MH_CALL *Callback)(Button *);
	public:
		Button() = delete;
		Button(const Button &) = delete;
		Button &operator=(const Button &) = delete;
		~Button() = delete;

		static Button *Create(const char *str);

		void setCallback(Callback callback);
	};

	class MH_DLL CheckBox
	{
		typedef void (MH_CALL *Callback)(CheckBox *, bool);
	public:
		CheckBox() = delete;
		CheckBox(const CheckBox &) = delete;
		CheckBox &operator=(const CheckBox &) = delete;
		~CheckBox() = delete;

		static CheckBox *Create(const char *str);

		void setCallback(Callback callback);

		void set(bool b, bool trigger_callback = true);
		bool get() const;
	};

	class MH_DLL ComboBox
	{
		typedef void (MH_CALL *Callback)(ComboBox *, int, const char *);
	public:
		ComboBox() = delete;
		ComboBox(const ComboBox &) = delete;
		ComboBox &operator=(const ComboBox &) = delete;
		~ComboBox() = delete;

		static ComboBox *Create(const char *prefix, const char *suffix);

		void setCallback(Callback callback);

		void setValues(const char *strs[], bool trigger_callback = true);

		void set(int i, bool trigger_callback = true);
		int get() const;
	};

	class MH_DLL SelectionBox
	{
		typedef void (MH_CALL *Callback)(SelectionBox *);
	public:
		SelectionBox() = delete;
		SelectionBox(const SelectionBox &) = delete;
		SelectionBox &operator=(const SelectionBox &) = delete;
		~SelectionBox() = delete;

		static SelectionBox *Create(const char *str);

		void setCallback(Callback callback);

		void setValues(const char *strs[]);

		void set(int i, bool b);
		bool get(int i) const;
	};

	class MH_DLL TextBox
	{
		typedef void (MH_CALL *Callback)(TextBox *, const char *);
	public:
		TextBox() = delete;
		TextBox(const TextBox &) = delete;
		TextBox &operator=(const TextBox &) = delete;
		~TextBox() = delete;

		static TextBox *Create(const char *placeholder);

		void setCallback(Callback callback);

		void set(const char *str);
		const char *get() const;
	};

	class MH_DLL Spinner
	{
		typedef void (MH_CALL *Callback)(Spinner *, double value);
	public:
		Spinner() = delete;
		Spinner(const Spinner &) = delete;
		Spinner &operator=(const Spinner &) = delete;
		~Spinner() = delete;

		static Spinner *Create(const char *prefix, const char *suffix);

		void setCallback(Callback callback);

		void set(double v, bool trigger_callback = true);
		double get() const;
	};

	class MH_DLL ColourPicker
	{
		typedef void (MH_CALL *Callback)(ColourPicker *, Colour);
	public:
		ColourPicker() = delete;
		ColourPicker(const ColourPicker &) = delete;
		ColourPicker &operator=(const ColourPicker &) = delete;
		~ColourPicker() = delete;

		static ColourPicker *Create(Colour colour);

		void setCallback(Callback callback);

		void set(Colour colour, bool trigger_callback = true);
		Colour get() const;
	};
}