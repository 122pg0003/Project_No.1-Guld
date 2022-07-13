#pragma once


class SceneMgr;
class Game;

class Trede {
public:
	Trede(SceneMgr& scenemgr,Game& game);
	~Trede();
	void Trede_Input();
	void Trede_Update();
	void Trede_Render();

protected:
	Game& _game;

private:
	SceneMgr& _scenemgr;
};