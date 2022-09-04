#include"Math.h"
#include"Dxlib.h"



//コンストラクタ
Math::Math()
{

	SuccessRate = 0;
	no = 0;
	
	 //mymoney = 10000;
	 //reward = 10000;
	 //cost = 1000;


}


//デストラクタ
Math::~Math() {

}
int mymoney = 10000;
int reward = 10000;
int cost =1000;

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
///クエスト判定
bool Math::Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow) {
	//成功率をパーティーのトータルステータスで決めている
	//ClearTotalAttack = 
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
	//no = rand() % 100 + 1;
	//DrawFormatString(1200, 0, GetColor(255, 255, 255), "クエスト判定%d\n", no);
	//DrawFormatString(1200, 20, GetColor(255, 255, 255), "成功率%d\n", SuccessRate);
	
	
	if (no > SuccessRate) {
		//クエスト失敗
		mymoney -= cost;
		SuccessRate = 0;

		_questresult = 0;
	}
	else {
		//クエスト成功
		mymoney += (reward - cost);
		SuccessRate = 0;
		_questresult = 1;
	}
	return 0;
}

void Math::Math_Update() {

}

void Math::Guild_B() {
	mymoney -= 1000;
}

void Math::Math_Render() {

	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%d\n", mymoney);
}




