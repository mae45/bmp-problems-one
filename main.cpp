//============================================================================
// Name        : bmpProblemsOne.cpp
// Author      : Mae45
// Version     : V01
// Description : Git Hub Submission for input 1/2/2018
//============================================================================

/**
 * The Dimensions of his images was
 * 259 by 259 Yellow and black
 * and
 * 353 by 132 Some pic that works
 * and they were in the same file as his main.cpp
 * file so we will do what he did first creating some
 * images and saving the to the mains folder /.
 */

#include <windows.h> 
#include <stdlib.h> 

using namespace std;

// ID's defined to use with Switch and case ta add functionality
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define FILE_MENU_HELP 5
#define GENERATE_BUTTON 4

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void AddControls(HWND);
void loadImages();

HMENU hMenu;

HWND hName, hAge, hOut, hLogo;

HBITMAP hLogoImage, hGenerateImage;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow )
{

	
    WNDCLASSW wc = {0}; 
	MSG msg {0};

	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc =  WindowProcedure;  

	if(!RegisterClassW(&wc)) 
	{ 
		return -1;
	}

	CreateWindowExW(0, L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);



	while( GetMessageW(&msg, 0, 0, 0) ) 
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return 0;

}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{

	case WM_COMMAND:
		switch(wp)
		{

		case GENERATE_BUTTON:  

			char name[30], age[10], out[50];
			GetWindowText(hName, name, 30);
			GetWindowText(hAge, age, 10);

			strcpy(out, name);
			strcat(out, " is ");
			strcat(out, age);
			strcat(out, " years old.");

			SetWindowText(hOut, out);
			break;
		case FILE_MENU_NEW:
			MessageBeep(MB_ICONINFORMATION);
			break;
		case FILE_MENU_OPEN:

			break;
		case FILE_MENU_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_CREATE:
		loadImages();   
		AddMenus(hWnd);
		AddControls(hWnd);   
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
	return 0;
}

void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();

	AppendMenu(hSubMenu, MF_STRING, 0, "SubMenu Item");


	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, "New");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Open SubMenu");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_STRING, FILE_MENU_HELP, "Help");

	SetMenu(hWnd, hMenu);

}


void AddControls(HWND hWnd)
{

	CreateWindowExW(0, L"static", L"Name :", WS_VISIBLE | WS_CHILD, 100, 50, 98, 38, hWnd, NULL, NULL, NULL);
	hName = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 50, 98, 38, hWnd, NULL, NULL, NULL);

	CreateWindowExW(0, L"static", L"Age :", WS_VISIBLE | WS_CHILD, 100, 90, 98, 38, hWnd, NULL, NULL, NULL);
	hAge = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 90, 98, 38, hWnd, NULL, NULL, NULL);

	CreateWindowExW(0, L"Button", L"Generate",  WS_VISIBLE | WS_CHILD, 150, 140, 98, 38, hWnd, (HMENU)GENERATE_BUTTON, NULL, NULL);

	hOut = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 200, 300, 200, hWnd, NULL, NULL, NULL);
	hLogo = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 60, 100, 100, hWnd, NULL, NULL, NULL);

	SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);

}

void loadImages()
{

	hLogoImage = (HBITMAP)LoadImageW(NULL, L"logoImage.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}


