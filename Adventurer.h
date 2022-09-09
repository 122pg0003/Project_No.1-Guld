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
		Return,
		���j���[,
		Adventurer1,
		Adventurer2,
		Adventurer3,
		Adventurer4,
		Adventurer5,
		Adventurer6,
		Null = -1  //���I��
	};

	MENU_NUM pattern;
	MENU_NUM oldpattern;
	MENU_NUM nowSelectedPattern;

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	int menu;
	int Back;
	int ScreenNo;
	int Adventurer1; ///�`����1
	int Adventurer2; ///�`����2
	int Adventurer3; ///�`����3
	int Adventurer4; ///�`����4
	int Adventurer5; ///�`����5
	int Adventurer6; ///�`����6
	int Adventurer7; ///�`����7
	int Adventurer8; ///�`����8
	int Adventurer1_1;
	int Adventurer2_1;
	int Adventurer3_1;
	int Adventurer4_1;
	int Adventurer5_1;
	int Adventurer6_1;
	int Adventurer1_2;
	int Adventurer2_2;
	int Adventurer3_2;
	int Adventurer4_2;
	int Adventurer5_2;
	int Adventurer6_2;


	//int _cursorIndex;
	//int x1,y1,x2,y2;
};
