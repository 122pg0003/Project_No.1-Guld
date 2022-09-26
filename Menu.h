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
   Quest quest;
	//QuestContent questcontent;
private:

	enum class  MENU_NUM {
		Quest,         //�N�G�X�g
		�`����,           //�`����
		�M���h,           //�M���h
		�{��,             //�{��
		����,             //����
		����,             //����
		���̌�,           //���̌�
		���̃^�[��,        //���̃^�[��
		�N�G�X�g��,        //�N�G�X�g��
		Save,
		Null = -1  //���I��
	};

	MENU_NUM pattern;
	MENU_NUM oldpattern;
	MENU_NUM nowSelectedPattern;


	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	SceneMgr& _scenemgr;
	TurnNumber _turnnumber;
	
	int z;
	int _bg;
	int QGrHandle;
	int	MGrHandle;
	int	GGrHandle;
	int TGrHandle;
	int IGrHandle;
	int	NGrHandle;
	int QGGrHandle;  //�N�G�X�g��
	int Quest;
	int Adventurer;
	int Guild;
	int NextGrHandle;  //���̌���
	int NextTurnGrHandle;
	int _mouse, _mousetrg;
	bool quest_flag = true;
};
