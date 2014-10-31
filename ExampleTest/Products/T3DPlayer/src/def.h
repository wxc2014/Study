#define WIN32_LEAN_AND_MEAN		//just say no to MFC

#include <windows.h>		//include all the windows headers
#include <windowsx.h>		//include useful macros
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _def_h_
#define _def_h_
//MACROS
#define KEYDOWN(vk_code)	((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)	((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#define WINDOW_CLASS_NAME "WINCLASS1"

#define WINDOW_WIDTH	400
#define WINDOW_HEIGHT	300

#define NUM_STARS		256


//types
typedef struct STAR_TYP
{
	int x, y;
	int vel;
	COLORREF col;
}	STAR, *STAR_PTR;

#endif