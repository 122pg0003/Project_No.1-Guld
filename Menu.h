#pragma once
#include "TurnNumber.h"
#include "QuestContent.h"
#include"Quest.h"


class TurnNumber;
class SceneMgr;
class Game;

class Menu{
public:
	Menu(SceneMgr& scenemgr, Game& game);
	~Menu();
	void Menu_Input();
	void Menu_Update();
	void Menu_Render();
	void HomeMenu_Render();  

protected:
	Game& _game;
 //Quest quest;
	//QuestContent questcontent;
private:

	enum class  MENU_NUM {
		�N�G�X�g,         //�N�G�X�g
		�`����,           //�`����
		�M���h,           //�M���h
		�{��,             //�{��
		����,             //����
		����,             //����
		���̌�,           //���̌�
		���̃^�[��,        //���̃^�[��
		�N�G�X�g��,        //�N�G�X�g��
	};

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	TurnNumber _turnnumber;

	
	int _bg;
	int QGrHandle;
	int	MGrHandle;
	int	GGrHandle;
	int TGrHandle;
	int IGrHandle;
	int	NGrHandle;
	int QGGrHandle;  //�N�G�X�g��
	int NextGrHandle;  //���̌���
	int NextTurnGrHandle;
	int _mouse, _mousetrg;
};
