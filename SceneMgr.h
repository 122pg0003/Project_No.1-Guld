#pragma once
#include"Adventurer.h"
#include"Menu.h"
#include"Quest.h"
#include"Guild.h"
#include"Trede.h"
#include"Investment.h"
#include"NextMonth.h"
#include"Math.h"


class Game;

class SceneMgr{
public:
	enum class eScene {
		Menu,         //メニュー
		Quest,         //クエスト
		Adventurer,   //冒険者
		Guild,        //ギルド
		Trede,        //交易
		Investment,   //投資
		NextMonth,    //次の月
	};

	SceneMgr(Game& game);
	~SceneMgr();
	virtual void Scene_Input();
	virtual void Scene_Update();
	virtual void Scene_Render();
	virtual void SceneMgr_ChangeScene(eScene nextScene);
 
	eScene scene{ eScene::Menu };
protected:
	Game& _game;
	Menu  menu;
	Adventurer adventurer;
	Quest quest;
	Guild guild;
	Trede trede;
	Investment investment;
	NextMonth nextmonth;
	Math math;

private:
	int _bg;
};
