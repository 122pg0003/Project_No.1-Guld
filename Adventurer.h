#pragma once
//#include"SceneMgr.h"
//#include"DxLib.h"
//#include"Mouse.h"
//#include"Game.h"

class SceneMgr;
class Game;

class Adventurer :public SceneMgr {
public:
	Adventurer(SceneMgr& scenemgr,Game& game);
	~Adventurer();
	void Adventurer_Input();
	void Adventurer_Update();
	
protected:
	Game& _game;
	//SceneMgr scenemgr;
private:
	SceneMgr& _scenemgr;
	int _cg;
	//int x1,y1,x2,y2;
};
