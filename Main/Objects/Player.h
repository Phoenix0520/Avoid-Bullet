#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update() override;
	void Render() override;

	RECT GetRect() { return player; }

private:
	RECT player;
	POINT position;
	LONG scale;
	LONG moveSpeed;

	
};