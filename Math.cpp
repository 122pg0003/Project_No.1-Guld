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
int reward = 10000;
int cost =1000;

///�N�G�X�g����
bool Math::Judgement() {
	DrawFormatString(1200, 0, GetColor(255, 255, 255), "�N�G�X�g����%d\n", no);

	



	no = rand() % 100 + 1;
	if (no <= 50) {

		//�N�G�X�g���s
		mymoney -= cost;


		return  0;
	}
	else {

		//�N�G�X�g����
		mymoney += (reward - cost);
		return  1;
	}
}


/// ��V�̌v�Z
void Math::Math_Updatea(bool isSuccess, int reward, int cost){
  
	// �����������V����ق������z�������������ė^����
	if (isSuccess)
	{
		 mymoney += (reward - cost);
	
	}
	// ���s������ق������z������������
	else
	{
		mymoney -= cost;
	}
	
}


void Math::Math_Update() {
	//auto A = Adventurer_Status::Find(Key1);
	//auto B = Adventurer_Status::Find(Key2);


	// A + B;

	//Math_Updatea(Judgement(), reward, cost);
	money = mymoney;
	//int i;
	//_quest.GetMoney(i);
	


}

void Math::Math_Render() {
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "������%d\n", money);
	
		Math_Update();
	
	DrawFormatString(1200, 0, GetColor(255, 255, 255), "�N�G�X�g����%d\n", no);

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

