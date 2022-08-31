#pragma once
#include"Math.h"


class SceneMgr;
class Game;

class Save {
public:
	Save(SceneMgr& scenemgr, Game& game);
	~Save();
	void Info_Save();
	void Info_Load();
private:
	Game& _game;
	SceneMgr& _scenemgr;
	Math math;

};
