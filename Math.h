#pragma once
//#include"Quest.h"

class Quest;
class SceneMgr;
class Game;

class Math{
public:
	Math(Quest& quest,SceneMgr& scenemgr,Game& game);     //コンストラクタ
	~Math();   //デストラクタ
	void Math_Update(int& no);
	//int Money_Update() { return no; }
  bool Judgement();

protected:
	SceneMgr& _scenemgr;
	Game& _game;
	Quest& _quest;

private:
	//Quest quest;
	int no;
};
