#pragma once
#include"Adventurer.h"
#include"Menu.h"
//#include"Game.h"


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
		Game
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

private:
	int _bg;
};
