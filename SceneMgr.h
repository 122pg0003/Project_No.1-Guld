#pragma once

#include"Menu.h"
#include"Adventurer.h"

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

	SceneMgr();
	~SceneMgr();
	void Scene_Input();
	void Scene_Update();
	void Scene_Render();
	 void SceneMgr_ChangeScene(eScene nextScene);

	eScene scene{ eScene::Menu };
protected:
	Menu  menu;
	Adventurer adventurer;
};
