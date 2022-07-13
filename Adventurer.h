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
	//int GetCursorIndex();

protected:
	Game& _game;
	//SceneMgr scenemgr;
private:

	enum class MENU_NUM {
		 –`Œ¯ŽÒ1
		,–`Œ¯ŽÒ2
		,–`Œ¯ŽÒ3
		,–`Œ¯ŽÒ4
		,–`Œ¯ŽÒ5
		,–`Œ¯ŽÒ6
		,–`Œ¯ŽÒ7
	};

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	int _cg;
	//int _cursorIndex;
	//int x1,y1,x2,y2;
};
