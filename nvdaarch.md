# NonVisual Developer's Aid to NVDA
NVDA internals for developers by developers
Joseph Lee

Revision 1.0 (2018)

## Introduction

Welcome to NVDA to NVDA: NonVisual Developer's Aid to NonVisual Desktop access. This book is designed to provide an in-depth view of internals of NVDA.

If you are a user of NVDA wondering how NVDA works, or a seasoned app developer wishing to know how to communicate app contents to screen readers, this book will give you a detailed tour of NVDA and its internals, from installation to debugging various NVDA modules. Along the way you'll get to learn a history of screen reading algorithms, how NVDA interacts with accessibility API's and tips on unlocking the power of this screen reader that had an impact on thousands of blind computer users around the world.

### How this book is organized

We'll begin our tour of NVDA by meeting NVDA's creators, Mick Curran and Jamie Teh. We'll then learn about its history, what sets this screen reader apart and what to expect after finishing this book.

Part 1, "Welcome to NVDA", provides an overview of NVDA's features, such as various NVDA menus, object navigation and accessibility API handlers.

Part 2, "Screen reading and NVDA 101", provides an overview of screen readers, its history and screen reading basics. You'll then be introduced to modules and dependencies that powers NVDA.

Part 3, "Objects and accessibility representatives", provides an introduction to NVDA's view of controls on screen, as well as an overview of various accessibility API handlers used in NVDA, such as IAccessible, UIA and so on.

Part 4, "Virtual buffers and content presentation", gives a tour of what a virtual buffer is and various virtual buffer implementations. You'll also learn how NvDA uses speech and braille to communicate screen content.

Part 5, "Interface, debugging, add-ons and conclusions", examines GUI components such as various preferences dialogs. You'll then be treated to an overview on how to debug various components of NVDA, as well as miscellaneous topics such as localization and add-ons. We'll conclude our tour with various appendices, such as advanced topics and NVDA's installation, startup and shutdown routines.

This book is loosely based on NVDA's own user guide and technical overview document, both of which can be found on NVDA Community portal at http://community.nvda-project.org.

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
	* Impact of moving to Python 3
	* NVDA modules: an overview
	* Accessibility API handlers
	* Input from keyboard, mouse, braille and touch
	* Speech and braille output
	* Core loop and event handlers
	* Virtual buffers, browse mode and document navigation management
	* Math presentation and content recognition framework
	* NVDA GUI and configuration subsystem
	* Add-ons
4. NVDA's view of screen controls and GUI elements
	* Object representation and navigation
	* Reacting to keyboard input, focus and caret changes
	* Reacting to events from applications
	* Control behaviors
	* Display model: scraping the screen for data
	* Fast inter-process communication with NVDA Helper
	* Secure screens and applications with administrator privileges
	* Handling mouse and touchscreen gestures
	* Conveying information on controls via speech and braille
5. Accessibility API's
	* MSAA and IAccessible
	* Control types and states
	* Events
	* UI Automation
	* Working around broken UIA implementations
	* UIA and recent versions of Windows
	* Java Access Bridge and Java applications
6. Virtual buffers, browse mode and document navigation
	* Virtual buffers
	* ARIA
	* Issues with specific virtual buffer implementations
	* PDF documents
	* A word on EdgeHTML
7. Interpreting and presenting content
	* Control types and states and their effects on speech and braille
	* Speech dictionaries and patterns
	* Regular expressions and reading screen content
	* Braille abbreviations for controls and states
	* Supporting multiple speech and braille languages
	* Content recognition
	* Interacting with math
	* Localizing NVDA
8. GUI and configuration subsystem
	* Installer
	* NVDA menu organization
	* Preference panels
	* Logging and log viewer
	* Add-ons management, installation, import and removal
	* Miscellaneous GUI elements and GUI controls helper
9. Debugging NVDA
	* Log viewer and log levels
	* Application crash dumps
	* Local and Remote Python Consoles
	* Source code level debugging
	* Knowing which modules to debug
	* Debugging speech and braille
	* Unit tests

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
C.4. GitHub, issue tracking and patch submission
C.5. Localization
C.6. Snapshots and releases

Appendix D: Essential Python
D.1. Python compatibility
D.2. Statements, syntax, and indentation
D.3. Imports and variables
D.4. Conditionals
D.5. While and for loops
D.6. Functions
D.7. Classes and objects
D.8. Lists, dictionaries, sets and other data structures
D.9. Modules and Python standard library

### Startup and shutdown procedures

NVDA, like any other app, performs complex yet coordinated routines during startup and shutdown. In this appendix, we'll examine what happens when NVDA starts and exits, as well as answer some troubleshooting questions related to NVDA's startup and shutdown routine.

#### Startup

NVDA's startup routines, found in NVDA launcher and Core loop modules, performs initialization routines for various accessibility API handlers and subsystems. The routines are divided into two phases: launcher and core.main.

Once NVDA has received command-line options, it then runs startup routine found in Core.main. The steps for the second phase are as follows:

1. Locates user configuration store and loads it into memory. By default, it is found in various user config folders depending on installation type, or an alternate path to the directory where the configuration store (nvda.ini) is located.
2. Once configuration has been loaded, NVDA plays startup sound (unless told to use minimal routine or configured to not play sounds) and sets log level and user interface language via values from user configuration store.
3. NVDA then proceeds to determine its version, the version of Python, version of Windows and other dependencies and records them in the log.
4. Locates add-ons and app modules and initializes them. This is perhaps the longest step of the startup phase, as NVDA needs to locate all add-ons and load each add-on serially, especially if an add-on contains additional startup code. If NvDA is told to disable add-ons upon startup, the loaded add-ons will be suspended for the duration of the current NVDA instance.
5. Once add-ons are ready or are told to suspend for the current instance, NvDA then prepares NvDA Helper, processes speech dictionary entries and speaks the sign-in message via the configured speech synthesizer. Along the way, NVDA loads WXPython library, at which point NVDA will be ready to accept events.
6. If a braille display is connected and configured, NvDA attempts to connect to the chosen braille display and prepares itself to receive braille input. If no braille display is configured, this step is skipped. Once NVDA has finished initializing, NVDA displays the startup message on the braille display unless told to start in minimal mode.
7. Continuing from step 5 or 6, NVDA loads display model subsystem and the GUI package, then instructs WXPython to remember the user interface language from user configuration store.
8. Next, various accessibility API's are initialized. This includes Java Access Bridge, IAccessible2, UIA (if running on Windows 7 and later) and Windows console app support.
9. Loads input framework such as mouse support, keyboard handler, touchscreen support (for a touch device running Windows 8 and higher) and other dependencies, then initializes loaded global plugins.
10. Performs queued events such as installation, update check and showing various startup dialogs such as Welcome dialog. Finally, NVDA puts focus on the last focus control such as a webpage, or if no focus control was found, on the taskbar.

