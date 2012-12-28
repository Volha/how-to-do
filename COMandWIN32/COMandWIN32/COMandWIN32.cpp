// COMandWIN32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "COMandWIN32.h"
#include <vector>
#include <atlcomcli.h>
#include <commctrl.h>
#include <InitGuid.h>
#include "../../WhatIsCOM/AddOperation/IPluginOp.h"
#include <string>
#include "../../WhatIsCOM/AddOperation/IMyEvent.h"

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
BOOL				DoOperat(HWND,const IID& riid );
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
	LoadString(hInstance, IDC_COMANDWIN32, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COMANDWIN32));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_COMANDWIN32));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_COMANDWIN32);
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
		case ID_FILE_ADDOPERATION:
			DoOperat(hWnd, CLSID_AddOp);
			break;
			
		case ID_FILE_SUBOPERQATION:
			DoOperat(hWnd, CLSID_SubOp);
			break;

		case ID_FILE_DIVOPERATION:
			DoOperat(hWnd, CLSID_DivOp);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
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
	case WM_CREATE:
		{
		HWND hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", 
		WS_CHILD | WS_VISIBLE | ES_NUMBER, 
		100, 100, 30, 30, hWnd, (HMENU)IDC_MAIN_EDIT1, GetModuleHandle(NULL), NULL);
		hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", 
		WS_CHILD | WS_VISIBLE | ES_NUMBER, 
		200, 100, 30, 30, hWnd, (HMENU)IDC_MAIN_EDIT2, GetModuleHandle(NULL), NULL);
		
		}
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
		if ( LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


class EventSink : public IMyEvents
{
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject)
	{
		if ((riid == IID_IMyEvents) || (riid == IID_IUnknown))
		{
			*ppvObject = reinterpret_cast<IMyEvents*>(this);
			AddRef();
			return S_OK;
		}
		return E_NOINTERFACE;
	}
	virtual ULONG STDMETHODCALLTYPE AddRef( void)
	{
		return 1;
	}
	virtual ULONG STDMETHODCALLTYPE Release( void)
	{
		return 0;
	}
	virtual HRESULT OnError(DWORD error)
	{
		MessageBoxA(
					NULL,
					"Division into zeroo",
					"Result",
					MB_OK | 
					MB_DEFBUTTON1 |
					MB_ICONERROR | 
					MB_DEFAULT_DESKTOP_ONLY);
		return S_OK;
	}
public:
	virtual ~EventSink(){};
};

BOOL DoOperat(HWND hWnd,const IID& riid)
{
	CoInitialize(NULL);
	{
		EventSink eventSink;
		DWORD cookie = 0;
		CComPtr<IPluginOp> pCF;
		HRESULT hr = CoCreateInstance(riid, NULL, CLSCTX_INPROC, IID_IPluginOp,(void**) &pCF); 
		if (SUCCEEDED(hr))
		{ 
			int param1 = GetDlgItemInt(hWnd, IDC_MAIN_EDIT1, NULL, TRUE);
			int param2 = GetDlgItemInt(hWnd, IDC_MAIN_EDIT2, NULL, TRUE);

				CComPtr<IConnectionPoint> cp;
				CComQIPtr<IConnectionPointContainer> cpCont(pCF);
				if (cpCont)
				{
					hr = cpCont->FindConnectionPoint(IID_IMyEvents, &cp);
					if (SUCCEEDED(hr))
					{
						hr = cp->Advise(&eventSink, &cookie);
					}
				}
				long double result  = pCF->DoOperation(param1, param2);
				std::string str = std::to_string(result);
				MessageBoxA(
					NULL,
					(LPCSTR)&str,
					"Result",
					MB_OK | 
					MB_DEFBUTTON1 |
					MB_ICONERROR | 
					MB_DEFAULT_DESKTOP_ONLY);
				cp->Unadvise(cookie);
			}
			
		}
	CoUninitialize();
	return TRUE;
}

