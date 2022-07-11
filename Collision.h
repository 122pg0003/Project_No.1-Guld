#pragma once
#include"Math.h"

class Game;

class AABB {
public:
	AABB(Game& game);
	~AABB();
	bool CheckHit();
	Vector2 min;
	Vector2 max;
protected:
	Game& _game;


	
};