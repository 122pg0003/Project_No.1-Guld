#pragma once
#include"SceneMgr.h"
#include"Game.h"

class Scenemgr;
class Game;

class Math{
public:
	Math(Scenemgr& scenemgr, Game& game);     //�R���X�g���N�^
	~Math();   //�f�X�g���N�^
	void Math_Update();
	void Math_Render();
	void Guild_B();
	void Success(int& SuccessRate, int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
	int SuccessRate;//�N�G�X�g�̐������@�e�X�e�[�^�X���K�v�ʂ܂ł�������{�Q�T�A�Œ�O�ōō��P�O�O
	int _questresult = -1;
 int mymoney;
	int reward;
	int cost;

	


	//int Money_Update() { return no; }
    bool Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
		const int AddSuccessrate = 25;  //�������A�X�e�[�^�X����K�v�ʂɂȂ�����{�����

protected:
	Scenemgr& _scenemgr;
	Game& _game;
//	Quest& _quest;

private:

	//Quest& _quest;
	int no;

};
