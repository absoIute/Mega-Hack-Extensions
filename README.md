
# Mega Hack Pro - Extensions
Mega Hack Extensions let you create custom, interactive windows in Mega Hack Pro

Extensions1 (v6 extensions) are still supported [here](extensions1) and work in both v6 & v7

## Getting Started
Include the [extensions2.h](include/extensions2.h) file in your project and link to [hackpro.lib](bin/hackpro.lib) to be able to use the library.

To setup your extensions simply create a new window with `MegaHackExt::Window::Create(const char *)`, this will return a `MegaHackExt::Window *` where you will add all your UI elements.

Now you can create your UI elements by calling `MegaHackExt::[UIelement]::Create(...)` and then adding them to the window with `MegaHackExt::Window::add`, but note elements are always added to the top so you will need to add elements in the reverse order of which you want them displayed.

Now you've added your elements just call `MegaHackExt::Client::commit(void *)` and the window will appear when opening Mega Hack! Make sure you don't try to add more UI elements to your window after this though as it won't work.

You can also pass singular elements like buttons & checkboxes to the `MegaHackExt::Client::commit(void *)` function if you're only adding a toggle for your mod and it will be added to Mega Hack's Extensions window instead!

## Compatibility

| Name | Minimum Version | Latest Supported Version |
| --- | --- | --- |
| Extensions1 | v6.2.0-beta4 | v7-GM1 |
| Extensions2 | v7.0.0-beta1 | v7-GM1 |
| MegaHackExt::Label | v7-GM1 | v7-GM1 |

## Importing My DLL
Click the "Extensions Folder" button in Mega Hack, put your DLL there & restart Geometry Dash

## Examples

[basic.cpp](examples/basic.cpp) - Basic callbacks & setup for Windows, Buttons, Checkboxes & HorizontalLayouts

[combo.cpp](examples/combo.cpp) - Basic callbacks & setup for ComboBoxes

[colour_picker.cpp](examples/colour_picker.cpp) - Basic callbacks & setup for ColourPickers