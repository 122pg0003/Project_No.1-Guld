#pragma once
//#include"SceneMgr.h"
//#include"DxLib.h"
//#include"Mouse.h"
//#include"Game.h"

class SceneMgr;
class Game;

class Adventurer   {
public:
	Adventurer(SceneMgr& scenemgr,Game& game);
	~Adventurer();
	void Adventurer_Input();
	void Adventurer_Update();
	void Adventurer_Render();
	//int GetCursorIndex();

protected:
	Game& _game;
	//SceneMgr scenemgr;
private:

	enum class MENU_NUM {
		���j���[
		,�`����1
		,�`����2
		,�`����3
		,�`����4
		,�`����5
		,�`����6
		,�`����7
	};

	

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	int _cg;
	int _BIGrHandle;
	int Q1GrHandle;
	int Q2GrHandle;
	int Q3GrHandle;
	int Q4GrHandle;
	int Q5GrHandle;
	int Q6GrHandle;


	//int _cursorIndex;
	//int x1,y1,x2,y2;
};
