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
	

	int ClearTotalAttack;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Attack�̑����l
	int ClearTotalDefence;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Defence�̑����l
	int ClearTotalSkill;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Skill�̑����l
	int ClearTotalKnow;  //�N�G�X�g�̒B���ɕK�v�ȃp�[�e�B�[��Know�̑����l
	const int QuestClearAttacks[12] = { 100,50,100,100,50,0,150,50,50,150,50,250 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Attack
	const int QuestClearDefence[12] = { 50,50,50,50,50,0,50,50,150,100,100,200 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Defence
	const int QuestClearSkill[12] = { 100,100,100,100,50,0,100,100,50,100,50 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Skill
	const int QuestClearKnow[12] = { 50,100,50,50,50,150,100,100,50,100,100,150 };  //�N�G�X�g���Ƃ̃N���A�ɕK�v��Know
	const int Reward[12] = { 10,10,25,20,10,10,30,20,20,30,20,50 };  //�N�G�X�g���Ƃɓ������V
	const int Fame[12] = { 10,10,10,10,10,10,10,10,10,10,10,50 };  //�N�G�X�g���Ƃɓ����閼���l


	void SetQuestParam(int questIndex);
	QuestContent questcontent;
};

class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //�R���X�g���N�^
	~Quest();                              //�f�X�g���N�^
	void Quest_Input();                    //����
	void Quest_Result();                   //�N�G�X�g����
	void Quest_Update();                   //�X�V
	void Quest_Render();                   //�`��
	void Add_Quest_Adventurer_Status(int AdventurerNo);      //�X�e�[�^�X�̑����l�̒ǉ�
	void Delete_Quest_Adventurer_Status(int AdventurerNo);   //�X�e�[�^�X�̑����l�̍폜
	void Random_Quest();                        //�N�G�X�g�̃����_���o��
	

	int TotalAttack;  //�p�[�e�B�[��Attack�̑����l
	int TotalDefence;  //�p�[�e�B�[��Defence�̑����l
	int TotalSkill;  //�p�[�e�B�[��Skill�̑����l
	int TotalKnow;  //�p�[�e�B�[��Know�̑����l
	int TotalCost;  //�p�[�e�B�[�̃R�X�g�̑����l
	int	AdventurerGood; //�`���҂̃N�G�X�g�̓��ӕs����
	//void GetMoney(int& i);
	//int  _gmause;
	//int _gTrg;
	bool Click1;  //�`���҂P�̔���
	bool Click2;  //�`���҂Q�̔���
	bool Click3;  //�`���҂R�̔���
	bool End;     //�N�G�X�g�̏I������
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

	void Menu_Back_Button();                    //���j���[�ɖ߂�
	void Back_Button();                         //�ЂƂO�ɖ߂�
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


	///�N�G�X�g�I�����
	 enum class MENU_NUM {
		  ���j���[
		,�N�G�X�g1
		,�N�G�X�g2
		,�N�G�X�g3
		,�N�G�X�g4
		,�N�G�X�g5
		,�N�G�X�g6
		,�N�G�X�g7
		,�N�G�X�g8
		,�N�G�X�g9
		,�N�G�X�g10
		,�N�G�X�g11
		,QInside
		,QInside1
		,QInside2
		,�N�G�X�g�J�n
	};

	///�N�G�X�g�̒��g
	enum class Q {
		Q���j���[
		,Q1
		,Q2
		,Q3
		,Q�N�G�X�g����
		,Q�����l = -1,
	};

	///�N�G�X�g�̉摜�����_��
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
