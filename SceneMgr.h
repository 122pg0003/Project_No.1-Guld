#pragma once
#include"Adventurer.h"
#include"Menu.h"
//#include"Game.h"


class Game;

class SceneMgr{
public:
	enum class eScene {
		Menu,        //���j���[
		Adventurer,  //�`����
		Guild,       //�M���h
		Trede,       //����
		Investment,  //����
		NextMonth    //���̌�
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
