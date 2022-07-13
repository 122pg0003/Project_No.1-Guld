#pragma once

class SceneMgr;
class Game;

class Guild {
public:
	Guild(SceneMgr& scenemgr, Game& game);
	~Guild();
	void Guild_Input();
	void Guild_Update();
	void Guild_Render();

protected:
	Game& _game;
	SceneMgr& _scenemgr;

private:
};