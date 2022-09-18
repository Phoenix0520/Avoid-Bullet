#include "stdafx.h"
#include "Scene/MainGame.h"

HWND Hwnd = NULL;
HDC Hdc = NULL;
MainGame* game = NULL;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain
(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR cmdParam,
	int show
)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = Title.c_str();
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);

	game = new MainGame();

	HWND hwnd = CreateWindow
	(
		Title.c_str(), L"Avoid Bullet",
		WS_OVERLAPPEDWINDOW,
		100, 20, Width, Height,
		NULL, NULL, hInstance, NULL
	);

	Hwnd = hwnd;
	ShowWindow(hwnd, show);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Update();
			//Render();
		}
	}
	
	SafeDelete(game);
	DestroyWindow(hwnd);
	UnregisterClass(Title.c_str(), hInstance);

	return msg.wParam;
}

enum EDirection { Left, Right, Up, Down };
EDirection dir;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			SetTimer(hwnd, 1, 10, NULL);
		}
		break;

		case WM_TIMER:
		{
			game->Update();
		}
		break;
		
		case WM_PAINT:
		{
			game->Render();
		}
		break;

		case WM_CLOSE : case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;

		default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}
