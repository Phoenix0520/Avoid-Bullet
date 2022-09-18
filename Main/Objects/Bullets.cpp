#include "stdafx.h"
#include "Bullets.h"

Bullets::Bullets()
	: delay(50)
	, level(12)
{
}

Bullets::~Bullets()
{
}

void Bullets::Update()
{
	if (delay >= 50)
	{
		RectDesc desc;
		desc.rt.left = rand() % (Width - 15);
		desc.rt.right = desc.rt.left + 30;
		desc.rt.top = -30;
		desc.rt.bottom = 0;
		desc.speed = rand() % 5 + 5;

		bullets.push_back(desc);

		delay = rand() % 50;
	}
	else
		delay += level;

	vector<RectDesc>::iterator it = bullets.begin();
	for (it; it != bullets.end(); it++)
	{
		it->rt.top += it->speed;
		it->rt.bottom += it->speed;

		if (it->rt.top > (LONG)Height + 5)
		{
			bullets.erase(it);
			break;
		}
	}
}

void Bullets::Render()
{
	for (const auto& bullet : bullets)
		RECT_RENDER(bullet.rt);
}
