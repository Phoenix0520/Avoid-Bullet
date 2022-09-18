#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

extern HWND Hwnd;
extern HDC Hdc;

const UINT Width = 640;
const UINT Height = 480;

const wstring Title = L"Avoid Bullet Game";

#define RECT_INIT(x, y, s) { x - s / 2, y - s / 2, x + s / 2, y + s / 2 }
#define RECT_RENDER(box) Rectangle(Hdc, box.left, box.top, box.right, box.bottom)

#define SafeDelete(p) { if(p) { delete (p); (p) = NULL;  }}
