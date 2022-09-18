#pragma once

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Update();
	void Render();

private:
	class Player* player;
	class Bullets* bullets;

	int score;
	int level;

	bool dead = false;

};