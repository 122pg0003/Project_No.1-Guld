#pragma once
#include"Adventurer_Status.h"

//#include"Quest.h"

class Quest;
class SceneMgr;
class Game;

class Math{
public:
	Math(/*Quest& quest, SceneMgr& scenemgr, Game& game*/ );     //コンストラクタ
	~Math();   //デストラクタ
	void Math_Update();
	void Math_Render();
	int _questresult = -1;


	//int Money_Update() { return no; }
    bool Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
		const int AddSuccessrate = 25;  //成功率、ステータスが一つ必要量になったら＋される

protected:
//SceneMgr& _scenemgr;
//	Game& _game;
//	Quest& _quest;

private:

	//Quest& _quest;
	int no;
	int SuccessRate;//クエストの成功率　各ステータスが必要量まであったら＋２５、最低０で最高１００

};
