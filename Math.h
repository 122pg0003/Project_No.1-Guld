#pragma once
#include"Adventurer_Status.h"

//#include"Quest.h"

class Quest;
class SceneMgr;
class Game;

class Math{
public:
	Math(/*Quest& quest, SceneMgr& scenemgr, Game& game*/ );     //�R���X�g���N�^
	~Math();   //�f�X�g���N�^
	void Math_Update();
	void Math_Render();
	int _questresult = -1;


	//int Money_Update() { return no; }
    bool Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
		const int AddSuccessrate = 25;  //�������A�X�e�[�^�X����K�v�ʂɂȂ�����{�����

protected:
//SceneMgr& _scenemgr;
//	Game& _game;
//	Quest& _quest;

private:

	//Quest& _quest;
	int no;
	int SuccessRate;//�N�G�X�g�̐������@�e�X�e�[�^�X���K�v�ʂ܂ł�������{�Q�T�A�Œ�O�ōō��P�O�O

};
