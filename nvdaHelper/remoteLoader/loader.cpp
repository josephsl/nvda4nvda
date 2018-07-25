/*
This file is a part of the NVDA project.
URL: http://www.nvda-project.org/
Copyright 2006-2010 NVDA contributers.
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2.0, as published by
    the Free Software Foundation.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
This license can be found at:
http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
*/

#include <cstdio>
#include <cassert>
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <remote/nvdaHelperRemote.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdline, int flags) {
	int res=0;
	#ifndef NDEBUG
	Beep(440,100);
	#endif
	res=injection_initialize(0);
	assert(res!=0); //nvdaHelper_initialize
	// Wait for input or EOF.
	getc(stdin);
	res=injection_terminate();
	assert(res!=0); //nvdaHelper_terminate
	#ifndef NDEBUG
	Beep(880,100);
	#endif
	return 0;
}