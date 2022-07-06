#pragma once

class SceneMgr;

class Menu{
public:
	Menu(SceneMgr& scenemgr);
	~Menu();
	void Menu_Input();
	void Menu_Update();
	void Menu_Render();

private:
	SceneMgr& _scenemgr;
};
