#pragma once
#include"Adventurer.h"
#include"Menu.h"
#include"Quest.h"
#include"Guild.h"
#include"Trede.h"
#include"Investment.h"
#include"NextMonth.h"
#include"Math.h"
#include "TurnNumber.h"
#include"Title.h"
#include"Save.h"


class Game;


class SceneMgr: public Math {
public:
	enum class eScene {
		//Title,           //�^�C�g��
		Menu,         //���j���[
		Quest,         //�N�G�X�g
		QuestEnd,      //�N�G�X�g����
		Adventurer,   //�`����
		Guild,        //�M���h
		Trede,        //����
		Investment,   //����
		NextMonth,    //���̌�
		Save,
		None = -1,
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
	Quest quest;
	Guild guild;
	Trede trede;
	Investment investment;
	NextMonth nextmonth;
	//Math math;
	TurnNumber turnnumber;
	Save save;

private:
	int _bg;
	int _bg1;
	int _bg2;
};
