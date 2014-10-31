#include "def.h"


HWND main_window_handle = NULL;
HINSTANCE hinstance_app = NULL;
HDC global_dc = NULL;

STAR stars[NUM_STARS];

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

void Erase_Stars(void);
void Draw_Stars(void);
void Move_Stars(void);
void Init_Stars(void);

int Game_Main(void * parms = NULL);
int Game_Init(void *parms = NULL);
int Game_Shutdown(void *parms = NULL);


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX winclass;
	HWND hwnd;
	MSG msg;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;

	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hinstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//hinstance_app = hinstance;
	if(!RegisterClassEx(&winclass))	return 0;

	if(!(hwnd = CreateWindowEx(NULL, WINDOW_CLASS_NAME, 
					"T3D Game Console Version 1.0", 
					WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					0, 0, 400, 300, NULL, NULL, hinstance, NULL)))
	{
		return 0;
	}

	main_window_handle = hwnd;

	Game_Init();

	while(TRUE)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)	break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Game_Main();
	}

	Game_Shutdown();

	return(msg.wParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;
	case WM_SIZE:
		{
			/*ReleaseDC(main_window_handle, global_dc);
			global_dc = GetDC(main_window_handle);*/
			Init_Stars();
		}
		break;
	case WM_CLOSE:
		break;
	case WM_DESTROY:
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int Game_Main(void * parms)
{
	DWORD start_time = GetTickCount();
	Erase_Stars();
	Move_Stars();
	Draw_Stars();

	Sleep(1000 - (GetTickCount()-start_time));
	/*while(GetTickCount()-start_time  < 1000)
	{
	}*/
	if(KEYDOWN(VK_ESCAPE))	SendMessage(main_window_handle, WM_CLOSE, 0, 0);

	return 1;
}

int Game_Init(void *parms)
{
	global_dc = GetDC(main_window_handle);
	Init_Stars();

	return 1;
}

int Game_Shutdown(void *parms)
{
	ReleaseDC(main_window_handle, global_dc);
	return 1;
}

void Init_Stars(void)
{
	RECT clientRect = {0, 0, 0, 0};
	GetClientRect(main_window_handle, &clientRect);
	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.top - clientRect.bottom;

	for(int index=0; index < NUM_STARS; index++)
	{
		stars[index].x = rand()%clientWidth; //WINDOW_WIDTH;
		stars[index].y = rand()%clientHeight; //WINDOW_HEIGHT;

		stars[index].vel = 1 + rand()%16;
		int intensity = 15 * (17 - stars[index].vel);
		stars[index].col = RGB(intensity, intensity, intensity);
	}
}

void Erase_Stars(void)
{
	for(int index=0; index < NUM_STARS; index++)
	{
		SetPixel(global_dc, stars[index].x, stars[index].y, RGB(0, 0, 0));
	}
}

void Draw_Stars()
{
	for(int index=0; index < NUM_STARS; index++)
	{
		SetPixel(global_dc, stars[index].x, stars[index].y, stars[index].col);
	}
}

void Move_Stars(void)
{
	RECT clientRect = {0, 0, 0, 0};
	GetClientRect(main_window_handle, &clientRect);
	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.top - clientRect.bottom;

	for(int index=0; index < NUM_STARS; index++)
	{
		stars[index].x += stars[index].vel;

		if(stars[index].x >= clientWidth)	stars[index].x -= clientWidth;
	}
}