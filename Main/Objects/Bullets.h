#pragma once
#include "GameObject.h"

struct RectDesc
{
	RECT rt;
	LONG speed;
};

class Bullets : public GameObject
{
public:
	Bullets();
	~Bullets();

	void Update() override;
	void Render() override;

	vector<RectDesc>& GetBullets() { return bullets;  }
	void SetLevel(int level) { this->level = level; }

private:
	vector<RectDesc> bullets;
	UINT delay;

	
	int level;
};