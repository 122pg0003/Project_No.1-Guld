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
		ƒƒjƒ…[,
		ğê,
		h,
		Œšİ,
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _BIGrHandle{ -1 };
	int _BuildingSlotGrHandle{ -1 };
	int _BuildingGrHandle{ -1 };
	int _ButtonGrHandle{ -1 };
};