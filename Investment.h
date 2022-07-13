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
	enum class MENU_NUM {
		ƒƒjƒ…[
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
};