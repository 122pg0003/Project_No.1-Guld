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
	int ClearTotalAttack;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Attack�̑����l
	int ClearTotalDefence;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Defence�̑����l
	int ClearTotalSkill;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Skill�̑����l
	int ClearTotalKnow;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Know�̑����l
	int QuestTurn;  //�N�G�X�g�ɂ�����^�[��
	int QuestNo;  //�N�G�X�g�����ʂ���ԍ��B�����Ƃɕ�����Ɗy�����H
	int necessaryturn[12] = {1,1,1,1,1,1,1,1,1,1,1,2};  //�N�G�X�g���ƂɕK�v�ȃ^�[����
	const int QuestClearAttacks[12] = { 100,50,100,100,50,0,150,50,50,150,50,250 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Attack
	const int QuestClearDefence[12] = { 50,50,50,50,50,0,50,50,150,100,100,200 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Defence
	const int QuestClearSkill[12] = { 100,100,100,100,50,0,100,100,50,100,50 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Skill
	const int QuestClearKnow[12] = { 50,100,50,50,50,150,100,100,50,100,100,150 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Know
	const int Reward[12] = { 10,10,25,20,10,10,30,20,20,30,20,50 };  //�N�G�X�g���Ƃɓ������V
	const int Fame[12] = { 10,10,10,10,10,10,10,10,10,10,10,50 };  //�N�G�X�g���Ƃɓ����閼���l
	bool QuestFlag[12] = { false, false, false, false, false, false, false, false, false, false, false, false };  //�N�G�X�g�����̔���
	const int QuestNumber[12] = {0,1,2,3,4,5,6,7,8,9,10,11 };  //�N�G�X�g���ƂɊ���U����ԍ�
	int no;
	int QuestIconGrHandle[12] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	void QuestEtc(int questIndex,
		int& ClearTotalAttack,
		int& ClearTotalDefence,
		int& ClearTotalSkill,
		int& ClearTotalKnow );
  
	const int QuestClearAttacks1[9] = { 100,50,50,0,150,50,50,150,50 };  //��1�N�G�X�g���Ƃ̃N���A�ɕK�v��Attack
	const int QuestClearDefence1[9] = { 50,50,50,0,50,50,150,100,100 };  //��1�N�G�X�g���Ƃ̃N���A�ɕK�v��Defence
	const int QuestClearSkill1[9] = { 100,50,50,0,100,100,50,100,50 };  //��1�N�G�X�g���Ƃ̃N���A�ɕK�v��Skill
	const int QuestClearKnow1[9] = { 50,100,50,150,100,100,50,100,100 };  //��1�N�G�X�g���Ƃ̃N���A�ɕK�v��Know
	const int Reward1[9] = { 25,20,10,10,30,20,20,30,20 };  //��1�N�G�X�g���Ƃɓ������V
	const int Fame1[9] = { 10,10,10,10,10,10,10,10,10 };  //��1�N�G�X�g���Ƃɓ����閼���l
	const int necessaryturn1[9] = { 1,1,1,1,1,1,1,1,1 };  //��1�N�G�X�g���ƂɕK�v�ȃ^�[����

protected:
};

