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
	enum class MENU_NUM {
		ƒƒjƒ…[
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
};