#pragma once
#include"Math.h"
#include "Adventurer_Status.h"
#include "TurnNumber.h"
#include "QuestContent.h"
#include"Graph.h"
#include<vector>

class SceneMgr;
class Game;


class QuestData {
public:
	

	int ClearTotalAttack;  //クエストの達成に必要なパーティーのAttackの総合値
	int ClearTotalDefence;  //クエストの達成に必要なパーティーのDefenceの総合値
	int ClearTotalSkill;  //クエストの達成に必要なパーティーのSkillの総合値
	int ClearTotalKnow;  //クエストの達成に必要なパーティーのKnowの総合値
	const int QuestClearAttacks[12] = { 100,50,100,100,50,0,150,50,50,150,50,250 };  //クエストごとのクリアに必要なAttack
	const int QuestClearDefence[12] = { 50,50,50,50,50,0,50,50,150,100,100,200 };  //クエストごとのクリアに必要なDefence
	const int QuestClearSkill[12] = { 100,100,100,100,50,0,100,100,50,100,50 };  //クエストごとのクリアに必要なSkill
	const int QuestClearKnow[12] = { 50,100,50,50,50,150,100,100,50,100,100,150 };  //クエストごとのクリアに必要なKnow
	const int Reward[12] = { 10,10,25,20,10,10,30,20,20,30,20,50 };  //クエストごとに得られる報酬
	const int Fame[12] = { 10,10,10,10,10,10,10,10,10,10,10,50 };  //クエストごとに得られる名声値


	void SetQuestParam(int questIndex);
	QuestContent questcontent;
};

class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //コンストラクタ
	~Quest();                              //デストラクタ
	void Quest_Input();                    //入力
	void Quest_Result();                   //クエスト結果
	void Quest_Update();                   //更新
	void Quest_Render();                   //描画
	void Add_Quest_Adventurer_Status(int AdventurerNo);      //ステータスの総合値の追加
	void Delete_Quest_Adventurer_Status(int AdventurerNo);   //ステータスの総合値の削除
	void Random_Quest();                        //クエストのランダム出現
	

	int TotalAttack;  //パーティーのAttackの総合値
	int TotalDefence;  //パーティーのDefenceの総合値
	int TotalSkill;  //パーティーのSkillの総合値
	int TotalKnow;  //パーティーのKnowの総合値
	int TotalCost;  //パーティーのコストの総合値
	int	AdventurerGood; //冒険者のクエストの得意不得意
	//void GetMoney(int& i);
	//int  _gmause;
	//int _gTrg;
	bool Click1;  //冒険者１の判定
	bool Click2;  //冒険者２の判定
	bool Click3;  //冒険者３の判定
	bool End;     //クエストの終了判定
	bool QuestStart;

	int _mouse, _mousetrg;

protected:
	Game& _game;
	SceneMgr& _scenemgr;
	Math math;
	QuestData questData1;
	QuestData questData2;
	QuestData questdata3;
	Adventurer_Status AdventurerStatus;
	TurnNumber turnnumber;
	Graph graph;
	//QuestContent questcontent;

private:

	void Menu_Back_Button();                    //メニューに戻る
	void Back_Button();                         //ひとつ前に戻る
	void RANDOM_Q(int random,
		int random1,
		int random2,
		int random3,
		int random4,
		int random5);
	int random;
	int random1;
	int random2;
	int random3;
	int random4;
	int random5;


	///クエスト選択画面
	 enum class MENU_NUM {
		  メニュー
		,クエスト1
		,クエスト2
		,クエスト3
		,クエスト4
		,クエスト5
		,クエスト6
		,クエスト7
		,クエスト8
		,クエスト9
		,クエスト10
		,クエスト11
		,QInside
		,QInside1
		,QInside2
		,クエスト開始
	};

	///クエストの中身
	enum class Q {
		Qメニュー
		,Q1
		,Q2
		,Q3
		,Qクエスト判定
		,Q初期値 = -1,
	};

	///クエストの画像ランダム
	enum class Quest_Graph {
		Q1GrHandle,
		Q2GrHandle,
		Q3GrHandle,
		Q4GrHandle,
		Q5GrHandle,
		Q6GrHandle

	};

	Q q;
	MENU_NUM scene{};
	Quest_Graph quest_graph{};



	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);

	int _cg;
	int _BIGrHandle;
	int Q1GrHandle;
	int Q2GrHandle;
	int Q3GrHandle;
	int Q4GrHandle;
	int Q5GrHandle;
	int Q6GrHandle;
	int i;
	int a;
	int b;
	
	int QGrHandle[6];
	int quest1_1;	
	int quest1_2;	
	int quest1_3;	
	int quest1_4;	
	int quest1_5;	
	int quest1_6;	
	int quest1_7;	
	int quest1_8;	
	int quest1_9;	
	int quest1_10;	

	int Q1;
	int Q1_1;
	int Q1Start;
	int Q2;
	int Q2_1;
	int Q3;
	int Q3_1;
	int menu;
	int clear;
	int failure;
	int Back;
	
};
