#include"Math.h"
#include"Dxlib.h"
#include"Game.h"
#include"SceneMgr.h"
//#include"Quest.h"
//#include



//�R���X�g���N�^
Math::Math(/*Quest& quest,SceneMgr& scenemgr,Game& game*/)
//	_quest(quest)
	/*_scenemgr(scenemgr)
	,_game(game)
	,_quest(quest)*/
{

	no = 0;
}


//�f�X�g���N�^
Math::~Math() {

}
int mymoney = 10000;
int reward = 3000;
int cost = 1000;

///�N�G�X�g����
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


/// ��V�̌v�Z
void Math::Math_Updatea(bool isSuccess, int reward, int cost){
  
	// �����������V����ق������z�������������ė^����
	if (Judgement())
	{
		 mymoney += (reward - cost);
	
	}
	// ���s������ق������z������������
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
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "������%d\n", no);

}

////�N�G�X�g����
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
//	//DrawFormatString(0, 0, GetColor(255, 255, 255), "�����_����%d\n", no);
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

