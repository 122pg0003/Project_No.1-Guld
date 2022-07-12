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

	enum class  MENU_NUM {
		�N�G�X�g,
		//Quest,         //�N�G�X�g
		Adventurer,   //�`����
		Guild,        //�M���h
		Trede,        //����
		Investment,   //����
		NextMonth,    //���̌�
		Game
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	//int _cg;
	int QGrHandle;
	int	MGrHandle;
	int	GGrHandle;
	int TGrHandle;
	int IGrHandle;
	int	NGrHandle;

};
