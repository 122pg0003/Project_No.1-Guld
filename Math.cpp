#include"Math.h"
#include"Dxlib.h"
#include"SceneMgr.h"
#include"Game.h"



//�R���X�g���N�^
Math::Math(Scenemgr& scenemgr, Game& game):
	_scenemgr(scenemgr),
	_game(game)
{


	SuccessRate = 0;
	no = 0;
	
	
	mymoney = 10000;
	 reward = 10000;
	 cost = 1000;


}


//�f�X�g���N�^
Math::~Math() {

}

//nt mymoney = 10000;
//int reward = 10000;
//int cost =1000;

void Math::Success(int& SuccessRate, int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow) {
	
	if (TotalAttack >= ClearTotalAttack) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalDefence >= ClearTotalDefence) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalSkill >= ClearTotalSkill) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalKnow >= ClearTotalKnow) {
		SuccessRate += AddSuccessrate;
	}

}
///�N�G�X�g����
bool Math::Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow) {
	//���������p�[�e�B�[�̃g�[�^���X�e�[�^�X�Ō��߂Ă���
	//Success( SuccessRate, ClearTotalAttack,  ClearTotalDefence,  ClearTotalSkill,  ClearTotalKnow,  TotalAttack,  TotalDefence,  TotalSkill,  TotalKnow);



	if (TotalAttack >= ClearTotalAttack) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalDefence >= ClearTotalDefence) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalSkill >= ClearTotalSkill) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalKnow >= ClearTotalKnow) {
		SuccessRate += AddSuccessrate;
	}

	no = rand() %  SuccessRate + 45 ;
	
	
	
	if (no > SuccessRate) {
		//�N�G�X�g���s
		mymoney -= cost;
		SuccessRate = 0;

		_questresult = 0;
	}
	else {
		//�N�G�X�g����
		mymoney += (reward - cost);
		SuccessRate = 0;
		_questresult = 1;
	}

	return 0;

}


void Math::Math_Update() {

}



void Math::Math_Render() {

	//DrawFormatString(1000, 45, GetColor(255, 255, 255), "%d\n", mymoney);
	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%d \n", mymoney);
	
}


void Math::Guild_B() {
	mymoney -= 1000;
}



