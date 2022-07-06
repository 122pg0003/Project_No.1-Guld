#pragma once

#include"Menu.h"
#include"Adventurer.h"

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
