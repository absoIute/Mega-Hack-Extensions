
# Mega Hack Extensions
Mega Hack Extensions let you create custom, interactive windows in Mega Hack Pro

Please note there is still stuff to be added since it's in beta, on-ready callbacks, get checkbox states, & horizontal layouts, for example.

## Getting Started
Include the [hackpro_ext.h](incl/hackpro_ext.h) file in your project, this will let you dynamically load the extension functions.

Before doing anything you need to call `InitialiseHackpro()` to link to Mega Hack, if the function fails then Mega Hack (hackpro.dll) isn't loaded, so don't attempt  anything silly.

Now just wait until Mega Hack is ready, with by `HackproIsReady()` (or the on-ready callback, when available). If `HackproIsReady()` returns false after `MenuLayer::init()` something very bad has probably happened.

When Mega Hack is ready you can finally create your window! Initialise it with `HackproInitialiseExt()` with your chosen name, add ya buttons & stuff (in reverse order!) then commit the window with `HackproExtCommit()`. After committing a window you can no longer add extra elements to it, you can still update the state of existing elements, however.

## Loading my DLL
To have your DLL load on launch add your DLL to the same folder hackpro.dll is located, then append your DLL to the `absolutedlls` file on a new line, make sure `hackpro.dll` is at the top of the file. Other custom ways of loading your DLL can work but aren't recommended.

## Where Documentation?
Soon!