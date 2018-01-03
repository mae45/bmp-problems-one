//============================================================================
// Name        : flashCard4WorkingWithImages.cpp
// Author      : Ebonygeek45
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/**
 * @comments The api supports the .ico and .bmp
 * format. .ico is for icons
 * TODO: I am sure it supports .jpg too but that
 * is something i will have to experiment since
 * it wasn't mentioned.
 *
 * The Dimensions of his images was
 * 259 by 259 Yellow and black
 * and
 * 353 by 132 Some pic that works
 * and they were in the same file as his main.cpp
 * file so we will do what he did first creating some
 * images and saving the to the mains folder /.
 */

#include <windows.h> // Should be the first header period
#include <stdlib.h> // added here for setting up hOut in the switch and case. We need some things from this std library

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

/**
 *
 *  @Notes   Handles created globally
 *  for edit controls. Static don't need the
 *  handlers themselves, jut the edits they may be
 *  using or working with
 *
 */
HWND hName, hAge, hOut, hLogo;

/// Need handlers for images Again declared globally
HBITMAP hLogoImage, hGenerateImage;


/* @ Great example of global and staying in scope
 *
 * 1. The handle is declared here in global
 * 2. It is then assigned or defined the createWindow function.
 * 		in a form wrapping the functions in a globally declared variable
 * 		which was created as that functions edit handle
 * 		as seen below
 * 3. Now the function wrapped in it's handler variable can be used
 * in other functions.
 *
 * This should be doable for other functions to be wrapped
 * in a globally declared variable to be used within other functions.
 *
 * Just keep in mind that all your params would have to be completed.
 * This is not going to work if you try to somehow pass variables
 * to it.
 * This is to be done in the function it starts in not
 * in the function you will be adding it to.
 *
 *
 */

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow )
{

	// Structs initialized to 0 for all their members
    WNDCLASSW wc = {0}; // this need to stay at W for now, It will be expande to ExW which means you can use them
	MSG msg {0};

/*
	//MessageBox(NULL, "Hello New windows world!!", "My First GUI", MB_OKCANCEL);
	// MessageBox(HWND, LPCSTR, LPCSTR, UINT);
*/



	wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc =  WindowProcedure;   // Declare and Define constant for WindowProcedure

	if(!RegisterClassW(&wc)) // this need to stay at W for now
	{ //  RegisterClassW(const WNDCLASSW*)

		return -1;

	}

	CreateWindowExW(0, L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);



	while( GetMessageW(&msg, 0, 0, 0) ) // This is a type bool in params so using 0 instead of null should be fine
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
		   /** Your logic goes in this switch. Setting
		    up the control is done in the function.
		    Depending on what it is it would be either
		    just declared in global as in the edits or
		    declared and defined in global as in
		    the buttons. I am guessing the the wp is
		    for windows procedure. It is a unsigned
		        integer which may make it good for working
		        in this switch and case.
		    */
		case GENERATE_BUTTON:  // The button itself is cast by id in the AddControls function for it's CreateWindow function
			/**
			 * @Syntax
			 * <Type> <name1>[size of array], <name2>[size of array], <name3>[size of array];
			 * @Example
			 * char name[30], age[10], out[50];
			 * @Remark you can use char types arrays,
			 * This may make it somewhat easier.
			 * Again, nothing fancy here.
			 * Keep in mind that the inside of the square
			 * brackets can be said to be the buffer of
			 * the array. The number you add inside sets
			 * the size of the buffer.
			 */
			char name[30], age[10], out[50];
			GetWindowText(hName, name, 30);
			GetWindowText(hAge, age, 10);
			/**
			 * From the stdlib
			 * strcpy(destination into which you want to copy, source);
			 * It ony take char types.
			 * is used to copy as string into another.
			 * strcat() is concantanation or adding onto
			 * So if you want to add name into the out box
			 * to show the user his results and then format
			 * it with some concantanation you would do it like below.
			 */
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
		loadImages();      // Load Images need to be done firstso it's need to be over AddMenus and AddControls
		AddMenus(hWnd);
		AddControls(hWnd);   // controls are child to the parent window. Controls can be a number of things including another window.
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
	return 0;
}
// To add Menus
void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
// Using A at the suffix or end of AppendMenu or other things is a different type of encoding that could cause problems
// Sub menus
	AppendMenu(hSubMenu, MF_STRING, 0, "SubMenu Item");

// Popups
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, "New");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Open SubMenu");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
	AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
// main menus
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_STRING, FILE_MENU_HELP, "Help");

// SetMenu(HWND, HMENU);
	SetMenu(hWnd, hMenu);

}

// To add controls to the program
void AddControls(HWND hWnd)
{

	/**
	 *
	 * @comments
	 * Here in this function is where you program the
	 * windows components that are called controls ie labels, buttons, textboxes
	 *
	 * Some will need a handler (such as to handle when changes or user input is added)
	 * and others will need to be defined to be used in the switch and case, such as a button
	 * being pressed.
	 * The statics and edits need a handler that is globally declared.
	 * The handlers will be defined by the CreateWindow fuctions.
	 * That way you can used the now defined handler by name to add to other functions
	 * in the program because now you should be able to use them anywhere in a function.
	 *
	 * The Button is added using declared and defined in global and that is used to program the Button
	 */

	CreateWindowExW(0, L"static", L"Name :", WS_VISIBLE | WS_CHILD, 100, 50, 98, 38, hWnd, NULL, NULL, NULL);
	hName = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 50, 98, 38, hWnd, NULL, NULL, NULL);

	CreateWindowExW(0, L"static", L"Age :", WS_VISIBLE | WS_CHILD, 100, 90, 98, 38, hWnd, NULL, NULL, NULL);
	hAge = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 90, 98, 38, hWnd, NULL, NULL, NULL);

	CreateWindowExW(0, L"Button", L"Generate",  WS_VISIBLE | WS_CHILD, 150, 140, 98, 38, hWnd, (HMENU)GENERATE_BUTTON, NULL, NULL);
// By casting the button in hmenu above that takes care of the id being entered, now all you have to do is add logic in the switch and case.
	hOut = CreateWindowExW(0, L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 200, 300, 200, hWnd, NULL, NULL, NULL);
	hLogo = CreateWindowExW(0, L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 350, 60, 100, 100, hWnd, NULL, NULL, NULL);
	/// send to send message to control to set it's image
	SendMessageW(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);

}

void loadImages()
{
	/**
	 * loadImageW need to be type casted
	 * ie (HBITMAP)loadImageW();
	 * Once the handle is setup her you also have to create another handle for it to be used is AddControls
	 * More than likely it is because the id is going to be used in control to assign the image.
	 */

	hLogoImage = (HBITMAP)LoadImageW(NULL, L"logoImage.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

}

/**
 * What is casting?
 *
 * Casting is a conversion process wherein data can be changed from one type
 * to another. C++ has two types of conversions:
 *
 *
 *
 *
 */


/**
Notes that was for add controls. May still be of help.



	**
	// This first control seems to be a label
	// So Labels are static  control and not meant to allow user input.

	 CreateWindowW(L"static", L"Enter text here: ", WS_VISIBLE | WS_CHILD,
							200, 100, 100, 50, hWnd, NULL, NULL, NULL );
							// Most of the controls will have the last 3 as NULL


	 CreateWindowW(L"static", L"Enter text here: ", WS_VISIBLE | WS_CHILD | WS_BORDER,
							200, 100, 100, 50, hWnd, NULL, NULL, NULL );
							// Most of the controls will have the last 3 as NULL

	 CreateWindowW(L"static", L"Enter text here: ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_RIGHT,
							200, 100, 100, 50, hWnd, NULL, NULL, NULL );
	 *


 ** @ notes						// Most of the controls will have the last 3 as NULL
	 // Now we are going to add a edit control in the form of a text box to allow user input.
	 // WS_VISIBLE and WS_CHILD is in all the controls and mostly the last three is null
	 // Class for the first param ie static from above or Edit from here lpClassName
	 // @2nd param is some default text lpWindowName but text added here will act as default text. 3rd param is the WS style take note of above rule 2 required more
	 // can be use just separate with | dwstyle @4th param position from the x axis @5th param position from the y
	 // axis, @6th param width of item, @7th param height of item, @8th param parent window handle if
	 // needed, @9th param hMenu handle if needed,  hinstance if needed, , @11th lp Param if needed.
	 // Keep in mind that the last 3 may mostly always be null.
	 // CreateWindowW(L"Edit", L"... ", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 200, 152, 100, 50, hWnd, NULL, NULL, NULL);

	 // HEdit was created for the edit field we set up here . We declared the handle in global. We will define or assign it here in the functions.
	 // We define/assign it to the CreateWindowW for Edit.
	*


** @notes Great notes on declaring global and wrapping definition in variable to use within other functions.
	 *
	 // Must stress that by doing this it is now in the global scope by being declared there.
	 // So it's definition or assignment can now be used every where.
	 /// This is something you need to try to understand well.
	 /// 1 it was declared in global 2. we bring it down here and assign it as shown above
	 /// This brings it into scope so that it can play well with other functions and you can use
	 /// it anywhere everything is stored in hEdit. Use this every time you need to . Keep in
	 // mind it is the handler you assigned.


	// CreateWindowW(L"Button", L"Change Title", WS_VISIBLE | WS_CHILD, 200, 204, 100, 50, hWnd, NULL, NULL, NULL);
	// CreateWindowExW(0, L"Button", L"Change Title", WS_VISIBLE | WS_CHILD, 200, 204, 100, 50, hWnd, NULL, NULL, NULL);
		  *
	 **  Attempting to change to ExW because W don't seem to have support and don't even come up as a keyword.
	  * Taking a look at the params Below shows the difference between CreateWindowW and CreateWindowExW
	  *    It seems to be pretty much the same except ExW has one extra at the front DWord type that could
	  *    throw you off if using W. When you hover over something in params for w you get
	  *    this box that gives you the below information.
	  * Original
	 CreateWindowW(L"Button", L"Change Title", WS_VISIBLE | WS_CHILD, 200, 204, 100, 50, hWnd, NULL, NULL, NULL);
	 Fully Expanded
	 CreateWindowExW (0, L"Button", L"Change Title", 0x10000000 | 0x40000000, 200, 204, 100, 50, hWnd, 0, 0, 0)
Adding it like this dows work very nicely and at least you have the syntax help unlike when trying wing W that give you only the alphabet.

// So for this I am going to try to change this one ove to ExW since it has so much better support with it
 *
 * Now for the param 10, It is for the hMenu hadle just like the parent window handle the is for param 9.
 * What we did was casted it so we could use param 10 for Change_title to use it's logic in the switch and case.
 * In the params we knew that param was of the type HMENU We wrapped that in it's own params ie (HMENU) Then
 * added our define for CHANGE_TITLE this allows us to use the logic that was already set up ffor it in
 * the switch form the previous vide. But in the case of doing your own buttons you would still cast it this way
 * then set up your define like in global. Then set up your logic for the button in the switch and case.
 *
 * This is the information that comes up when hovering over the cast created in param 10
 *
 * (HMENU)CHANGE_TITLE
 * DECLARE_HANDLE(HMENU);
 * Interesting. This is the same thing it says when you hover over the HMENU type itself.
 * Perhaps doing it this way ia s way to reuse a param.
 * I just say to follow this pattern whn doing the cast and you should be fine.
 *
 * Also, the same way I discovered how to update CreateWindow I did the same thing for
 * AppendMenu, it did not have keyword highlighting either. When you hover over it
 * it says expanded to ApppendMenuA. When I changed it to that the nice keyword came up and
 * the syntax in the params.  I figure going with what it says it is expanded to is the
 * way it is hinting for you to get with it..

*


*/



