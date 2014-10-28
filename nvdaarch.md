# NonVisual Developer's Aid to NVDA
Explaining NVDA's architecture for developers by developers
Joseph Lee

Revision 1.0 (October 2014)

Welcome to NVDA to NVDA: NonVisual Developer's Aid to NonVisual Desktop access.

## Contents

1. What is NVDA
1.1. NVDA: A History
1.2. Meet the lead developers
1.3. What sets NVDA apart
2. Introduction to screen reading
2.1. What is screen reading?
2.2. A history of screen readers
2.3. Screen reading algorithms
2.3.1. Fetching information
2.3.2. Interpreting screen data
2.3.3. Presenting data in user-friendly way
2.4. Screen reading methods used by NVDA
3. Meet NVDA's modules
3.1. Teaching Python to NVDA: Python modules
3.2. Equipping NVDA for its work: dependencies
3.3.1. Why Python 2?
3.4. NVDA modules: an overview
3.4.1. Accessibility API handlers
3.4.2. Input from keyboard, mouse, braille and touch
3.4.3. Speech and braille output
3.4.4. Core loop and event handlers
3.4.5. Virtual buffers and document navigation management
3.4.6. NVDA GUI and configuration subsystem
3.4.7. Add-ons
4. NVDA's view of screen controls and GUI elements
4.1. Object representation and navigation
4.2. Reacting to keyboard input, focus and caret changes
4.3. Reacting to events from applications
4.4. Display model: scraping the screen for data
4.5. Fast inter-process communication with NVDA Helper
4.6. Secure screens and applications with administrator privileges
4.7. Handling mouse and touchscreen gestures
4.8. Conveying information on controls via speech and braille
5. Accessibility API's
5.1. MSAA and IAccessible
5.1.1. Control types and states
5.1.2. Events
5.2. User Interface Automation
5.2.1. Working around broken UIA implementations
5.2.2. UIA and recent versions of Windows
5.3. Java Access Bridge and Java applications
6. Virtual buffers and document navigation
6.1. Virtual buffers
6.2. ARIA
6.3. Issues with specific virtual buffer implementations
6.4. PDF documents
7. Interpreting and presenting content
7.1. Control types and states and their effects on speech and braille
7.2. Speech dictionaries and patterns
7.3. Regular expressions and reading screen content
7.4. Braille abbreviations for controls and states
7.5. Supporting multiple speech and braille languages
7.6. Localizing NVDA
8. GUI and configuration subsystem
8.1. Installer
8.2. NVDA menu organization
8.3. Preference dialogs
8.4. Logging and log viewer
8.5. Add-ons management, installation, import and removal
8.6. Miscellaneous GUI elements
9. Debugging NVDA
9.1. Log viewer and log levels
9.2. Application crash dumps
9.3. Local and Remote Python Consoles
9.4. source code level debugging
9.4.1. Knowing which modules to debug
9.5. Debugging speech and braille
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

