#pragma once

class Game;
class SceneMgr;
class Ending {
public:
	Ending(Game& game);
	~Ending();
	void Update();
	void Render();

	int EDGrHandle1{ -1 };
	int EDGrHandle2{ -1 };
	int EDGrHandle3{ -1 };
	int EDGrHandle4{ -1 };

	int CreditGrHandle1{ -1 };
	int CreditGrHandle2{ -1 };
	int CreditGrHandle3{ -1 };
	int CreditGrHandle4{ -1 };
	int CreditGrHandle5{ -1 };
	int CreditGrHandle6{ -1 };


	int EDcount;

private:
	Game& _game;
	//SceneMgr& _scenemgr;
};
