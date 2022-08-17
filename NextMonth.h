#pragma once

class SceneMgr;
class Game;

class NextMonth {
public:
	NextMonth(SceneMgr& scenemgr, Game& gsme);
	~NextMonth();
	void NextMonth_Input();
	void NextMonth_Update();
	void NextMonth_Render();

protected:
	Game& _game;

private:
	SceneMgr& _scenemgr;
};