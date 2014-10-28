# NonVisual Developer's Aid to NVDA
Explaining NVDA's architecture for developers by developers
Joseph Lee


Revision 1.0 (October 2014)

Welcome to NVDA to NVDA: NonVisual Developer's Aid to NonVisual Desktop access.

## Contents

1. What is NVDA
* NVDA: A History
* Meet the lead developers
* What sets NVDA apart
2. Introduction to screen reading
* What is screen reading?
* A history of screen readers
* Screen reading algorithms
* Fetching information
* Interpreting screen data
* Presenting data in user-friendly way
* Screen reading methods used by NVDA
3. Meet NVDA's modules
* Teaching Python to NVDA: Python modules
* Equipping NVDA for its work: dependencies
* Why Python 2?
* NVDA modules: an overview
* Accessibility API handlers
* Input from keyboard, mouse, braille and touch
* Speech and braille output
* Core loop and event handlers
* Virtual buffers and document navigation management
* NVDA GUI and configuration subsystem
* Add-ons
4. NVDA's view of screen controls and GUI elements
* Object representation and navigation
* Reacting to keyboard input, focus and caret changes
* Reacting to events from applications
* Display model: scraping the screen for data
* Fast inter-process communication with NVDA Helper
* Secure screens and applications with administrator privileges
* Handling mouse and touchscreen gestures
* Conveying information on controls via speech and braille
5. Accessibility API's
* MSAA and IAccessible
* Control types and states
* Events
* User Interface Automation
* Working around broken UIA implementations
* UIA and recent versions of Windows
* Java Access Bridge and Java applications
6. Virtual buffers and document navigation
* Virtual buffers
* ARIA
* Issues with specific virtual buffer implementations
* PDF documents
7. Interpreting and presenting content
* Control types and states and their effects on speech and braille
* Speech dictionaries and patterns
* Regular expressions and reading screen content
* Braille abbreviations for controls and states
* Supporting multiple speech and braille languages
* Localizing NVDA
8. GUI and configuration subsystem
* Installer
* NVDA menu organization
* Preference dialogs
* Logging and log viewer
* Add-ons management, installation, import and removal
* Miscellaneous GUI elements
9. Debugging NVDA
* Log viewer and log levels
* Application crash dumps
* Local and Remote Python Consoles
* Source code level debugging
* Knowing which modules to debug
* Debugging speech and braille

Appendix A: Installation, startup and shutdown routines
A.1. Installation and portable copy generation
A.2. Startup and shutdown procedures

Appendix B: Calling Windows API functions from Python
B.1. The ctypes module
B.2. Using ANSI versus wide char version of a function

Appendix C: NVDA development process
C.1. Obtaining Git and NVDA source code
C.2. Compiling NVDA for the first time
C.3. Project workflow
C.4. Issue tracking and patch submission
C.5. Localization
C.6. Snapshots and releases

