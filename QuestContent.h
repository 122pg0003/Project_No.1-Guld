#pragma once
#include <vector>

class Game;
class Quest;
class TurnNumber;
class Adventurer_Status;
class QuestContent {
public:
	QuestContent();
	~QuestContent();
	int ClearTotalAttack;  //クエストの達成に必要なパーティーのAttackの総合値
	int ClearTotalDefence;  //クエストの達成に必要なパーティーのDefenceの総合値
	int ClearTotalSkill;  //クエストの達成に必要なパーティーのSkillの総合値
	int ClearTotalKnow;  //クエストの達成に必要なパーティーのKnowの総合値
	int QuestTurn;  //クエストにかかるターン
	int QuestNo;  //クエストを識別する番号。星ごとに分けると楽かも？
	int necessaryturn[12] = {1,1,1,1,1,1,1,1,1,1,1,2};  //クエストごとに必要なターン数
	const int QuestClearAttacks[12] = { 100,50,100,100,50,0,150,50,50,150,50,250 };  //クエストごとのクリアに必要なAttack
	const int QuestClearDefence[12] = { 50,50,50,50,50,0,50,50,150,100,100,200 };  //クエストごとのクリアに必要なDefence
	const int QuestClearSkill[12] = { 100,100,100,100,50,0,100,100,50,100,50 };  //クエストごとのクリアに必要なSkill
	const int QuestClearKnow[12] = { 50,100,50,50,50,150,100,100,50,100,100,150 };  //クエストごとのクリアに必要なKnow
	const int Reward[12] = { 10,10,25,20,10,10,30,20,20,30,20,50 };  //クエストごとに得られる報酬
	const int Fame[12] = { 10,10,10,10,10,10,10,10,10,10,10,50 };  //クエストごとに得られる名声値
	bool QuestFlag[12] = { false, false, false, false, false, false, false, false, false, false, false, false };  //クエスト中かの判定
	const int QuestNumber[12] = {0,1,2,3,4,5,6,7,8,9,10,11 };  //クエストごとに割り振られる番号
	int no;
	int QuestIconGrHandle[12] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	void QuestEtc(int questIndex,
		int& ClearTotalAttack,
		int& ClearTotalDefence,
		int& ClearTotalSkill,
		int& ClearTotalKnow );
  
	const int QuestClearAttacks1[9] = { 100,50,50,0,150,50,50,150,50 };  //★1クエストごとのクリアに必要なAttack
	const int QuestClearDefence1[9] = { 50,50,50,0,50,50,150,100,100 };  //★1クエストごとのクリアに必要なDefence
	const int QuestClearSkill1[9] = { 100,50,50,0,100,100,50,100,50 };  //★1クエストごとのクリアに必要なSkill
	const int QuestClearKnow1[9] = { 50,100,50,150,100,100,50,100,100 };  //★1クエストごとのクリアに必要なKnow
	const int Reward1[9] = { 25,20,10,10,30,20,20,30,20 };  //★1クエストごとに得られる報酬
	const int Fame1[9] = { 10,10,10,10,10,10,10,10,10 };  //★1クエストごとに得られる名声値
	const int necessaryturn1[9] = { 1,1,1,1,1,1,1,1,1 };  //★1クエストごとに必要なターン数

protected:
};

