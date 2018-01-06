
/**
    Name    :  bmp-problems-one
    Author  :  Mae45
    Version :  Two
    Comments:  The first edition was pretty messed up and full or errors.
               It somehow merged two different files or something.
               This one is the way it was supposed to be in the first place
    Date    :  1/6/2017
*/

#include <windows.h>

using namespace std;

LPCWSTR egClassName = L"myWindowClass";

HWND hLogo;
HBITMAP hLogoImage, hGenerateImage;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void loadPictures();
void parentControls(HWND);
void testPictures();

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow )
{

	HWND hWnd;

	WNDCLASSW wc = {0};


	wc.style 			= 0;
	wc.lpszMenuName 	= NULL;
	wc.lpszClassName	= egClassName;
	wc.lpfnWndProc		= WindowProcedure;
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wc.hInstance		= hInst;
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.cbWndExtra		= 0;
	wc.cbClsExtra		= 0;


	if(!RegisterClassW(&wc))
	{
		const char Error01[] = "Register Issue To Check On : ";   /// Notice this seems to be the way to add strings through the programming. Can you say ah hah moment
		const char Error01_Caption[] = "Error 01";

		MessageBoxEx(0, Error01, Error01_Caption, MB_OK | MB_ICONERROR, 0);   /// To stay consistent with the L"" use the W or ExW Prefix on MessageBox or any other functions giving errors abot string type formats

		// return -1;
		///   per David Heffernan : You don't check return values for errors
	}

	LPCWSTR parentWinTitle = L"My Window";

	hWnd = CreateWindowW(egClassName, parentWinTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	if(hWnd == NULL)
	{

		const wchar_t Error02[] = L"Window Creation Issue To Check On : ";
		const wchar_t Error02_Caption[] = L"Window Creation Issue To Check On : ";
		MessageBoxW(0, Error02, Error02_Caption, MB_OK | MB_ICONERROR);

	}
	ShowWindow(hWnd, ncmdshow);
	UpdateWindow(hWnd);


	MSG msg {0};

	while( GetMessage(&msg, 0, 0, 0) )
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);

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

		}
	break;

	case WM_CREATE:                 /// Order of functions correction per Barmak Shemirani
        loadPictures();             /// Here it is very important to call loadPictures() first.
		parentControls(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, msg, wp, lp);

	}
	return 0;
}

void loadPictures()
{
    LPCWSTR lIbmp = L"logoImage.bmp";   /// adjust your folder. Works better with full path
    hLogoImage = (HBITMAP)LoadImageW(NULL, lIbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

}

void parentControls(HWND hWnd)
{

    LPCWSTR bmpLogo = L"Static";

    hLogo = CreateWindowW(bmpLogo, NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 100, 70, 100, 100, hWnd, NULL, NULL, NULL);
    SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
    /// Here you are sending the message. This function and any menus should be called after load picture.
}

/// Bitmap pic should be saved to 24-bit format
