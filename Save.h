#pragma once
#include"Math.h"
//#include"Math.cpp"


class SceneMgr;
class Game;

class Save: private Math {
public:
	Save(SceneMgr& scenemgr, Game& game);
	~Save();
	void Info_Save();
	void Info_Load();
private:
	Game& _game;
	SceneMgr& _scenemgr;
	//Math math;

};
//int mymoney = 1000;
