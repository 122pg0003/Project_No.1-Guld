#pragma once


class SceneMgr;
class Game;

class Investment {
public:
	Investment(SceneMgr& scenemgr,Game& gsme);
	~Investment();
	void Investment_Input();
	void Investment_Update();
	void Investment_Render();

protected:
	Game& _game;

private:
	SceneMgr& _scenemgr;
};