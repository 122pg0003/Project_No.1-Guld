#pragma once

class SceneMgr;
class Game;

class Menu{
public:
	Menu(SceneMgr& scenemgr, Game& game);
	~Menu();
	void Menu_Input();
	void Menu_Update();
	void Menu_Render();

protected:
	Game& _game;
private:
	SceneMgr& _scenemgr;
	int _cg;
};
