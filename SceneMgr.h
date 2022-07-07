#pragma once
#include"Adventurer.h"
#include"Menu.h"
//#include"Game.h"


class Game;

class SceneMgr{
public:
	enum class eScene {
		Menu,        //ƒƒjƒ…[
		Adventurer,  //–`Œ¯Ò
		Guild,       //ƒMƒ‹ƒh
		Trede,       //ŒğˆÕ
		Investment,  //“Š‘
		NextMonth    //Ÿ‚ÌŒ
	};

	SceneMgr(Game& game);
	~SceneMgr();
	void Scene_Input();
	void Scene_Update();
	void Scene_Render();
	 void SceneMgr_ChangeScene(eScene nextScene);

	eScene scene{ eScene::Menu };
protected:
	Game& _game;
	Menu  menu;
	Adventurer adventurer;

};
