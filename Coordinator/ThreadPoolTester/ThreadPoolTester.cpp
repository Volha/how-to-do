// ThreadPoolTester.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <commctrl.h>
#include <cmath>
#include "ThreadPoolTester.h"
#include <boost\thread.hpp>
#include "ThreadPool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
BOOL				AddTask(HWND, int);

namespace
{
	const int INT_DIV = 10000000;
	const int TASK_SIZE = 1000000000;
	const int FUNCTION_PARTS = 2;
	const int WM_TASK_FINISHED = ::RegisterWindowMessage(L"TaskFinishedMessage");
	
	class Handler
	{
	public:
		Handler(HWND mainWindow, HWND progressWindow)
			: m_mainWindow(mainWindow)
			, m_progressWindow(progressWindow)
			, m_progress(0)
		{
			
		}
		~Handler()
		{
			SendMessage(m_mainWindow, WM_TASK_FINISHED, reinterpret_cast<WPARAM>(m_progressWindow), 0);
		}
		void IncrementProgress()
		{
			boost::unique_lock<boost::mutex> lock(m_mutex);
			++m_progress;
			PostMessage(m_progressWindow, PBM_SETPOS, m_progress, 0);
		}
	private:
		HWND m_mainWindow;
		HWND m_progressWindow;
		int m_progress;
		boost::mutex m_mutex;
	};
	typedef std::shared_ptr<Handler> HandlerPtr;

	ThreadPool pool(4);

	void BackgroundTask(HandlerPtr handler, int start, int finish)
	{
		for(int i = start; i < finish; ++i)
		{
			double di = static_cast<double>(i);
			double d = std::sqrt(std::sqrt(di) + std::sqrt(di + 1));
			if ((i % INT_DIV) == 0 && handler)
			{
				handler->IncrementProgress();
			}
		}
	}
}


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_THREADPOOLTESTER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_THREADPOOLTESTER));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_THREADPOOLTESTER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_THREADPOOLTESTER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	if (message == WM_TASK_FINISHED)
	{
		HWND window = reinterpret_cast<HWND>(wParam);
		if (::IsWindow(window))
		{
			::DestroyWindow(window);
		}
		return 0;
	}


	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
	
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_FILE_ADD2TASKS:
			AddTask(hWnd, 2);
			break;
		case ID_FILE_ADD3TASKS:
			AddTask(hWnd, 3);
			break;
		case ID_FILE_ADD4TASKS:
			AddTask(hWnd, 4);
			break;
		case ID_FILE_ADD5TASKS:
			AddTask(hWnd, 5);
			break;
		case ID_FILE_ADD20TASKS:
			AddTask(hWnd, 20);
			break;
		case ID_FILE_ADD100TASKS:
			AddTask(hWnd, 100);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

BOOL AddTask(HWND hWnd, int functionParts)
{

	
	HWND progressWindow = CreateWindowEx(0, PROGRESS_CLASS, NULL,
									WS_CHILD | WS_VISIBLE,
									30, 30, 400, 30,
									hWnd, NULL, hInst, NULL);
	SendMessage(progressWindow, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
	
	HandlerPtr handler = std::make_shared<Handler>(hWnd, progressWindow);
	
	int subTaskStart = 0;
	int subTaskSize = TASK_SIZE / functionParts;
	
	for (size_t i = 0; i < functionParts; ++i)
	{
		pool.DoAsync([handler, subTaskStart, subTaskSize]()
			{
				BackgroundTask(handler, subTaskStart, subTaskStart + subTaskSize);
			}
		);
		subTaskStart += subTaskSize;
	}
	return TRUE;
}
