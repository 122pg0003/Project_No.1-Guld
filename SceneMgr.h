#pragma once
#include"Adventurer.h"
#include"Menu.h"
//#include"Game.h"


class Game;

class SceneMgr{
public:
	enum class eScene {
		Menu,         //ƒƒjƒ…[
		Adventurer,   //–`Œ¯Ò
		Guild,        //ƒMƒ‹ƒh
		Trede,        //ŒğˆÕ
		Investment,   //“Š‘
		NextMonth,    //Ÿ‚ÌŒ
		Game
	};

	SceneMgr(Game& game);
	~SceneMgr();
	virtual void Scene_Input();
	virtual void Scene_Update();
	virtual void Scene_Render();
	virtual void SceneMgr_ChangeScene(eScene nextScene);
 
	eScene scene{ eScene::Game };
protected:
	Game& _game;
	Menu  menu;
	Adventurer adventurer;

private:
	int _bg;
};
