#include "stdafx.h"
#include "MainGame.h"
#include "Objects/Player.h"
#include "Objects/Bullets.h"

MainGame::MainGame()
	: score(0)
	, level(1)
{
	srand((UINT)time(NULL));

	player = new Player();
	bullets = new Bullets();
}

MainGame::~MainGame()
{
	SafeDelete(player);
	SafeDelete(bullets);
}

void MainGame::Update()
{
	InvalidateRect(Hwnd, NULL, TRUE);
	
	if (dead)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			score = 0;
			dead = false;
		}
		return;
	}

	RECT temp;
	vector<RectDesc>::iterator it = bullets->GetBullets().begin();

	for (it; it != bullets->GetBullets().end(); it++)
	{
		if (it->rt.top > (LONG)Height)
			score++;
		else if( IntersectRect(&temp, &player->GetRect(), &it->rt))
		{
			dead = true;
			bullets->GetBullets().erase(bullets->GetBullets().begin(), bullets->GetBullets().end());
			break;
		}
	}

	level = score / 10 + 1;
	bullets->SetLevel(level);

	player->Update();
	bullets->Update();
}

void MainGame::Render()
{
	PAINTSTRUCT ps;

	Hdc = BeginPaint(Hwnd, &ps);
	{
		if (dead)
		{
			wstring str = L"Game Over!";
			TextOut(Hdc, 275, 190, str.c_str(), str.length());

			str = L"최종 점수 : " + to_wstring(score);
			TextOut(Hdc, 265, 210, str.c_str(), str.length());

			str = L"Press Space to Restart!";
			TextOut(Hdc, 240, 270, str.c_str(), str.length());
		}
		else
		{
			wstring str = L"점수 : " + to_wstring(score);
			TextOut(Hdc, 10, 10, str.c_str(), str.length());

			str = L"레벨 : " + to_wstring(level);
			TextOut(Hdc, 10, 30, str.c_str(), str.length());

			player->Render();
			bullets->Render();
		}
	}
	EndPaint(Hwnd, &ps);
}
