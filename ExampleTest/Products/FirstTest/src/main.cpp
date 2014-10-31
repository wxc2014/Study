#define WIN32_LEAN_AND_MEAN		//just say no to MFC

#include <windows.h>		//include all the windows headers
#include <windowsx.h>		//include useful macros
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "resourcedef.h"
#include "def.h"

//#pragma comment( lib, "winmm.lib" )

//defines for windows
#define	WINDOW_CLASS_NAME	"WINCLASS1"	

HWND main_window_handle = NULL;
HINSTANCE hinstance_app = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT	ps;	//used in WM_PAINT
	HDC		hdc;	//handle to a device context
	RECT	rect;	//rectangle of window
	char buffer[80];

	static UINT	count1 = 0, count2 = 0;

	//what is the message
	switch(msg)
	{
	case WM_CREATE:
		{
			//play the create sound once
			//PlaySound(MAKEINTRESOURCE(SOUND_ID_CREATE), hinstance_app, SND_RESOURCE | SND_SYNC);
			//play the music in loop mode
			//PlaySound(MAKEINTRESOURCE(SOUND_ID_MUSIC), hinstance_app, SND_RESOURCE | SND_ASYNC | SND_LOOP);

			//SetTimer(hwnd, TIMER_ID_1SEC, 1000, NULL);
			//SetTimer(hwnd, TIMER_ID_3SEC, 3000, NULL);
			
			break;
		}

	case WM_COMMAND:
		{
			switch(LOWORD(wparam))
			{
			case MENU_FILE_ID_EXIT:
				{
					PostQuitMessage(0);
					break;
				}

			case MENU_HELP_ABOUT:
				{
					MessageBox(hwnd, "Menu Sound Demo", "About Sound Menu", MB_OK | MB_ICONEXCLAMATION);
					break;
				}

			case MENU_PLAY_ID_ENERGIZE:
				{
					PlaySound(MAKEINTRESOURCE(SOUND_ID_ENERGIZE), hinstance_app, SND_RESOURCE | SND_ASYNC);
					break;
				}
			case MENU_PLAY_ID_BEAM:
				{
					PlaySound(MAKEINTRESOURCE(SOUND_ID_BEAM), hinstance_app, SND_RESOURCE | SND_ASYNC);
					break;
				}
			case MENU_PLAY_ID_TELEPORT:
				{
					PlaySound(MAKEINTRESOURCE(SOUND_ID_TELEPORT), hinstance_app, SND_RESOURCE | SND_ASYNC);
					break;
				}
			case MENU_PLAY_ID_WARP:
			{
				PlaySound(MAKEINTRESOURCE(SOUND_ID_WARP), hinstance_app, SND_RESOURCE | SND_ASYNC);
				break;
			}

			default:
				break;
			}

		break;
		}

	case WM_PAINT:
		{
			//simply validate the window
			//hdc = GetDC(hwnd);

			//HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			//HBRUSH red_brush = CreateSolidBrush(RGB(255, 0, 0));

			//HPEN old_pen = (HPEN)SelectObject(hdc, white_pen);
			//SelectObject(hdc, white_pen);
			//SelectObject(hdc, red_brush);

			//Rectangle(hdc, 10, 10, 20, 20);

			/*MoveToEx(hdc, 20, 10, NULL);
			LineTo(hdc, 30, 20);
			LineTo(hdc, 10, 20);
			LineTo(hdc, 20, 10);*/

			//SelectObject(hdc, old_pen);
			//DeleteObject(white_pen);
			//RECT rect = {10, 10, 100, 100};
			//FillRect(hdc, &rect, CreateSolidBrush(RGB(255, 0, 0)));
			//FrameRect(hdc, &rect, CreateSolidBrush(RGB(255, 0, 0)));
			//ReleaseDC(hwnd, hdc);
			/*for(int idx = 0; idx < 1000; idx++)
			{
				int x = rand()%400;
				int y = rand()%400;

				COLORREF color = RGB(rand()%255, rand()%255, rand()%255);
				SetPixel(hdc, x, y, color);
			}*/
			//ReleaseDC(hwnd, hdc);

			//GetClientRect(hwnd, &rect);
			//InvalidateRect(hwnd, NULL, TRUE);

			/*static int wm_paint_count = 0;*/

			hdc = BeginPaint(hwnd, &ps);

			/*SetTextColor(hdc, RGB(255, 255, 255));
			SetBkColor(hdc, RGB(0, 0, 0));
			SetBkMode(hdc, OPAQUE);

			sprintf(buffer, "WM_PAINT called %d times", ++wm_paint_count);
			TextOut(hdc, 0, 0, buffer, strlen(buffer));*/
			EndPaint(hwnd, &ps);
			break;
		}
	//case WM_ACTIVATE:
	//	{
	//		if(LOWORD(wparam) != WA_INACTIVE)
	//		{
	//			/*MessageBox(hwnd, "Active Window",
	//							"WM_ACTIVATE Message Processor", MB_OK | MB_ICONEXCLAMATION);*/
	//			//get a graphics context

	//		//draw the size of the window
	//			sprintf(buffer, "Active Window");
	//		}
	//		else
	//		{
	//			/*MessageBox(hwnd, "Inactive Window",
	//							"WM_ACTIVATE Message Processor", MB_OK | MB_ICONEXCLAMATION);*/
	//			sprintf(buffer, "Inactive Window");
	//		}
	//		//return (DefWindowProc(hwnd, msg, wparam, lparam));

	//		hdc = GetDC(hwnd);

	//		//set the forgeground color to white
	//		SetTextColor(hdc, RGB(255, 255, 255));

	//		//set the background color to black
	//		SetBkColor(hdc, RGB(0, 0, 0));

	//		//set the transparency mode to OPAQUE
	//		SetBkMode(hdc, OPAQUE);
	//		//TextOut(hdc, 0, 0, buffer, strlen(buffer));
	//		ReleaseDC(hwnd, hdc);
	//		break;
	//	}

	case WM_CLOSE:
		{
			int result = MessageBox(hwnd, "Are you sure you want to close this application?",
								"WM_CLOSE Message Processor", MB_YESNO | MB_ICONQUESTION);

			//does the user want to close?
			if(result == IDYES)
			{
				//call default handler
				return (DefWindowProc(hwnd, msg, wparam, lparam));
			}

			break;
		}

	//case WM_SIZE:
	//	{
	//		//extract size info
	//		int width = LOWORD(lparam);
	//		int height = HIWORD(lparam);

	//		//get a graphics context
	//		hdc = GetDC(hwnd);

	//		//set the forgeground color to white
	//		SetTextColor(hdc, RGB(255, 255, 255));

	//		//set the background color to black
	//		SetBkColor(hdc, RGB(0, 0, 0));

	//		//set the transparency mode to OPAQUE
	//		SetBkMode(hdc, OPAQUE);

	//		//draw the size of the window
	//		sprintf(buffer, "WM_SIZE Called - New Size = (%d, %d)", width, height);
	//		//TextOut(hdc, 0, 0, buffer, strlen(buffer));

	//		//release the dc back
	//		ReleaseDC(hwnd, hdc);

	//		break;
	//	}

	//case WM_MOVE:
	//	{
	//		//extract the position
	//		int xpos = LOWORD(lparam);
	//		int ypos = HIWORD(lparam);

	//		//get a graphics context
	//		hdc = GetDC(hwnd);

	//		//set the foreground color to white
	//		SetTextColor(hdc, RGB(255, 255, 255));

	//		//set the background color to black
	//		SetBkColor(hdc, RGB(0,0, 0));

	//		SetBkMode(hdc, OPAQUE);

	//		//draw the size of the window
	//		sprintf(buffer, "WM_MOVE Called - New Position = (%d, %d)", xpos, ypos);
	//		//TextOut(hdc, 0,0, buffer, strlen(buffer));

	//		ReleaseDC(hwnd, hdc);

	//		break;
	//	}

	//case WM_CHAR:
	//	{
	//		char ascii_code = wparam;
	//		unsigned int key_state = lparam;

	//		//get a graphics context
	//		hdc = GetDC(hwnd);

	//		//set the foreground color to white
	//		SetTextColor(hdc, RGB(255, 255, 255));

	//		//set the background color to black
	//		SetBkColor(hdc, RGB(0,0, 0));

	//		SetBkMode(hdc, OPAQUE);

	//		//draw the size of the window
	//		sprintf(buffer, "WM_CHAR:Character = %c", ascii_code);
	//		TextOut(hdc, 0,0, buffer, strlen(buffer));

	//		sprintf(buffer, "Key State = 0X%X", key_state);
	//		TextOut(hdc, 0,16, buffer, strlen(buffer));

	//		ReleaseDC(hwnd, hdc);

	//		break;

	//	}

	/*case WM_KEYDOWN:
		{
			int virtual_code = (int)wparam;
			int key_state = (int)lparam;

			switch(virtual_code)
			{
			case VK_RIGHT:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = right");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);

				break;
			case VK_LEFT:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = left");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);

				break;
			case VK_UP:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = up");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);
				break;
			case VK_DOWN:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = down");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);
				break;

			case VK_NUM_0:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = 0");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);
				break;
			case VK_CHAR_A:
				hdc = GetDC(hwnd);
				sprintf(buffer, "Key = a");
				TextOut(hdc, 0,0, buffer, strlen(buffer));
				ReleaseDC(hwnd, hdc);
				break;

			default:
				break;
			}

			break;
		}*/
		
	//case WM_MOUSEMOVE:
	//	{
	//		int mouse_x = (int)LOWORD(lparam);
	//		int mouse_y = (int)HIWORD(lparam);

	//		int buttons = (int)wparam;

	//		hdc = GetDC(hwnd);
	//		sprintf(buffer, "Mouse (%d, %d)", mouse_x, mouse_y);
	//		//TextOut(hdc, 0,0, buffer, strlen(buffer));
	//		ReleaseDC(hwnd, hdc);
	//		break;

	//	}

	//case WM_TIMER:
	//	{
	//		hdc = GetDC(hwnd);
	//		//set the foreground color to white
	//		SetTextColor(hdc, RGB(255, 255, 255));

	//		//set the background color to black
	//		SetBkColor(hdc, RGB(0,0, 0));

	//		SetBkMode(hdc, OPAQUE);

	//		switch(wparam)
	//		{
	//		case TIMER_ID_1SEC:
	//			sprintf(buffer, "Timer = 1s count = %d", count1++);
	//			TextOut(hdc, 0, 0, buffer, strlen(buffer));
	//			break;
	//		case TIMER_ID_3SEC:
	//			sprintf(buffer, "Timer = 3s count = %d", count2++);
	//			TextOut(hdc, 0, 50, buffer, strlen(buffer));
	//			break;
	//		default:
	//			break;
	//		}

	//		ReleaseDC(hwnd, hdc);
	//		break;
	//	}

	case WM_DESTROY:
		{
			//stop the sounds first
			PlaySound(NULL, hinstance_app, SND_PURGE);

			/*KillTimer(hwnd, TIMER_ID_1SEC);
			KillTimer(hwnd, TIMER_ID_3SEC);*/

			PostQuitMessage(0);
			break;
		}

	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, 
				   LPSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX winclass;
	HWND	hwnd;
	MSG	msg;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hinstance;
	winclass.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(ICON_T3DX));
	winclass.hCursor = LoadCursor(hinstance, MAKEINTRESOURCE(CURSOR_CROSSHAIR));
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
	//winclass.lpszMenuName = "MainMenu";
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(hinstance, MAKEINTRESOURCE(ICON_T3DX));

	hinstance_app = hinstance;

	//register the window class
	if(!RegisterClassEx(&winclass))	return 0;

	//create the first window
	if(!(hwnd = CreateWindowEx(NULL, WINDOW_CLASS_NAME, "TestWinClass",
							WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
							NULL, NULL, hinstance, NULL)))
	{
		return 0;
	}

	//SetMenu(hwnd, LoadMenu(hinstance, "SoundMenu"));

	main_window_handle = hwnd;

	//create the second window
	/*if(!(hwnd = CreateWindowEx(NULL, WINDOW_CLASS_NAME, "Window 2 Also Based on WINCLASS1",
							WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 400, 400,
							NULL, NULL, hinstance, NULL)))
	{
		return 0;
	}*/

	HDC hdc = GetDC(hwnd);
	srand(GetTickCount());

	int x1 = rand()%WINDOW_WIDTH;
	int y1 = rand()%WINDOW_HEIGHT;
	int x2 = rand()%WINDOW_WIDTH;
	int y2 = rand()%WINDOW_HEIGHT;

	int x1v = -4 + rand()%8;
	int y1v = -4 + rand()%8;
	int x2v = -4 + rand()%8;
	int y2v = -4 + rand()%8;
	int color_change_count = 0;
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(rand()%256, rand()%256, rand()%256));
	SelectObject(hdc, pen);

	//HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	//HPEN black_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	//HBRUSH green_brush = CreateSolidBrush(RGB(0, 255, 0));
	//HBRUSH black_brush = CreateSolidBrush(RGB(0, 0, 0));

	////starting position of ball
	//int ball_x = 200, ball_y = 200;

	//int xv = -4 + rand()%8;
	//int yv = -4 + rand()%8;

	while(TRUE)
	{
		DWORD start_time = GetTickCount();
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		//if(GetMessage(&msg,NULL, 0, 0))
		{
			if(msg.message == WM_QUIT)	break;

			//translate any accelerator keys
			TranslateMessage(&msg);

			//send the message to the window proc
			DispatchMessage(&msg);
		}
		if(++color_change_count >= 100)
		{
			color_change_count = 0;
			if(pen)	DeleteObject(pen);
			pen = CreatePen(PS_SOLID, 1, RGB(rand()%256, rand()%256, rand()%256));

			SelectObject(hdc, pen);
		}

		x1 += x1v;
		y1 += y1v;
		x2 += x2v;
		y2 += y2v;

		if(x1 < 0 || x1 >= WINDOW_WIDTH)
		{
			x1v =-x1v;
			x1 += x1v;
		}
		if(y1 < 0 || y1 >= WINDOW_HEIGHT)
		{
			y1v =-y1v;
			y1 += y1v;
		}
		if(x2 < 0 || x2 >= WINDOW_WIDTH)
		{
			x2v =-x2v;
			x2 += x2v;
		}
		if(y2 < 0 || y2 >= WINDOW_HEIGHT)
		{
			y2v =-y2v;
			y2 += y2v;
		}

		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
		while((GetTickCount() - start_time) < 33)
		{
		}

	//	//erase the last position of the ball
	//	SelectObject(hdc, black_pen);
	//	SelectObject(hdc, black_brush);

	//	Ellipse(hdc, ball_x, ball_y, ball_x + 32, ball_y + 32);

	//	//move the ball
	//	ball_x += xv;
	//	ball_y += yv;

	//	//test for collisions
	//	if(ball_x < 0 || ball_x > 400 - 32)
	//	{
	//		xv = -xv;
	//		ball_x += xv;
	//	}
	//	else if(ball_y < 0 || ball_y > 400 -32)
	//	{
	//		yv = -yv;
	//		ball_y += yv;
	//	}

	//	SelectObject(hdc, white_pen);
	//	SelectObject(hdc, green_brush);
	//	Ellipse(hdc, ball_x, ball_y, ball_x+32, ball_y+32);

	//	Sleep(10);
	}

	//DeleteObject(white_pen);
	//DeleteObject(black_pen);
	//DeleteObject(green_brush);
	//DeleteObject(black_brush);
	DeleteObject(pen);
	ReleaseDC(hwnd, hdc);

	return msg.wParam;
}
