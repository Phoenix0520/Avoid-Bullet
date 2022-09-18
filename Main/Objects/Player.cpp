#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	moveSpeed = 10;
	scale = 45;
	position = { (LONG)Width / 2,  (LONG)Height - scale - 10 };
	ZeroMemory(&player, sizeof(RECT));
}

Player::~Player()
{
}

void Player::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
		position.x -= (position.x >= moveSpeed) ? moveSpeed : 0;
	else if (GetAsyncKeyState('D') & 0x8000)
		position.x += (position.x <= (LONG)Width - moveSpeed) ? moveSpeed : 0;

	player = RECT_INIT(position.x, position.y, scale);
}

void Player::Render()
{
	RECT_RENDER(player);
}
