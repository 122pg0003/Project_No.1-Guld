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
		ƒƒjƒ…[
		,–`Œ¯Ò1
		,–`Œ¯Ò2
		,–`Œ¯Ò3
		,–`Œ¯Ò4
		,–`Œ¯Ò5
		,–`Œ¯Ò6
		,–`Œ¯Ò7
	};

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	int _cg;

	//int _cursorIndex;
	//int x1,y1,x2,y2;
};
