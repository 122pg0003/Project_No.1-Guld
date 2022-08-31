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
		クエスト,         //クエスト
		冒険者,           //冒険者
		ギルド,           //ギルド
		施設,             //施設
		交易,             //交易
		投資,             //投資
		次の月,           //次の月
		次のターン,        //次のターン
		クエスト中,        //クエスト中
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
	int QGGrHandle;  //クエスト中
	int NextGrHandle;  //次の月へ
	int NextTurnGrHandle;
	int _mouse, _mousetrg;
};
