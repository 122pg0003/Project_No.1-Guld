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
	enum class MENU_NUM {
		ƒƒjƒ…[
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
};