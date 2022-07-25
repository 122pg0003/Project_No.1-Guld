#include"Math.h"
#include"Dxlib.h"
#include"Game.h"
#include"SceneMgr.h"
//#include"Quest.h"
//#include



//コンストラクタ
Math::Math(/*Quest& quest,SceneMgr& scenemgr,Game& game*/)
//	_quest(quest)
	/*_scenemgr(scenemgr)
	,_game(game)
	,_quest(quest)*/
{

	no = 0;
}


//デストラクタ
Math::~Math() {

}
int mymoney = 10000;
int reward = 3000;
int cost = 1000;

///クエスト判定
bool Math::Judgement() {
	no = rand() % 100 + 1;
	if (no <= 50) {
int reward = 3000;
int cost = 1000;

		return  0;
	}
	else {
		int cost = 1000;
		return 1;
	}
}


/// 報酬の計算
void Math::Math_Updatea(bool isSuccess, int reward, int cost){
  
	// 成功したら報酬から雇った金額だけ差し引いて与える
	if (Judgement())
	{
		 mymoney += (reward - cost);
	
	}
	// 失敗したら雇った金額だけ差し引く
	else
	{
		mymoney -= cost;
	}
	
}


void Math::Math_Update(int& no) {


	Math_Updatea(Judgement(),reward,cost);
	no = mymoney;
	//int i;
	//_quest.GetMoney(i);
	


}

void Math::Math_Render() {
	Math_Update(no);
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "所持金%d\n", no);

}

////クエスト判定
//bool Math::Judgement() {
//	no = rand() % 100 + 1;
//	if (no <= 50) {
//
//		return  TRUE;
//	}
//	else {
//
//		return FALSE;
//	}
//	//return   no <= 50;
//	//DrawFormatString(0, 0, GetColor(255, 255, 255), "ランダム数%d\n", no);
//
//
//	/*no = rand() % 100 + 1;
//	if (no <= 50) {
//		graph->DrawC();
//	}
//	else {
//		graph->DrawF();
//	}
//	ScreenFlip();*/
//
//}

