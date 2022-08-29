#pragma once


class SceneMgr;
class Game;

class Title{
public:
	Title(SceneMgr& scenemgr,Game& game);
	~Title();
	void Title_Update();
	void Title_Render();
private:
	Game& _game;
	SceneMgr& _scenemgr;
	int _cg;
};
