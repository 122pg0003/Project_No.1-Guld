#include"Math.h"
#include"Dxlib.h"
#include"Game.h"
#include"SceneMgr.h"
#include"Quest.h"
//#include



//�R���X�g���N�^
Math::Math(Quest& quest,SceneMgr& scenemgr,Game& game):
	_quest(quest)
	,_scenemgr(scenemgr)
	,_game(game)

{
	
	no = 0;
}


//�f�X�g���N�^
Math::~Math() {

}


void Math::Math_Update(int& no) {
	no = 0;
	//int i;
	//_quest.GetMoney(i);
	no++;

	
}


//�N�G�X�g����
bool Math::Judgement() {
	no = rand() % 100 + 1;
	return   no <= 50;
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "�����_����%d\n", no);


	/*no = rand() % 100 + 1;
	if (no <= 50) {
		graph->DrawC();
	}
	else {
		graph->DrawF();
	}
	ScreenFlip();*/

}

