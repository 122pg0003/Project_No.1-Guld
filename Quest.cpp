#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
//#include"Math.h"



//�R���X�g���N�^
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
  //,math(*this)
	//,_math(*this,_game,_scenemgr)
 {
	//_cg = LoadGraph("images/Adventurer.jpg");
	_cg1 = LoadGraph("images/�N�G�X�g���2.png");
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	Q1GrHandle = LoadGraph("images/Quest-1.png");  //�N�G�X�g1�X���b�g
	Q2GrHandle = LoadGraph("images/Quest-2.png");  //�N�G�X�g2�X���b�g
	Q3GrHandle = LoadGraph("images/Quest-3.png");  //�N�G�X�g3�X���b�g
	Q4GrHandle = LoadGraph("images/Quest-4.png");  //�N�G�X�g4�X���b�g
	Q5GrHandle = LoadGraph("images/Quest-5.png");  //�N�G�X�g5�X���b�g
	Q6GrHandle = LoadGraph("images/Quest-6.png");  //�N�G�X�g6�X���b�g
	Q1 = LoadGraph("images/�`����.jpg");  //�N�G�X�g1���g
	Q2 = LoadGraph("images/�`���҂Q.png");  //�N�G�X�g1���g
	Q3 = LoadGraph("images/�`����.jpg");  //�N�G�X�g1���g
	menu = LoadGraph("images/�N�G�X�g���1.png");  //�N�G�X�g1���g
	clear = LoadGraph("images/Clear.png");
	failure = LoadGraph("images/Failure.png");
}

//�f�X�g���N�^
Quest::~Quest() {

}

//�I�����ڂ̗̈�w��
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::���j���[:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;

	case MENU_NUM::�N�G�X�g1:

		max_x = 656;
		min_x = 396;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::�N�G�X�g2:

		max_x = 1090;
		min_x = 830;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::�N�G�X�g3:

		max_x = 1524;
		min_x = 1264;
		max_y = 580;
		min_y = 270;

		break;
	case MENU_NUM::�N�G�X�g4:

		max_x = 656;
		min_x = 396;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::�N�G�X�g5:

		max_x = 1090;
		min_x = 830;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::�N�G�X�g6:

		max_x = 1524;
		min_x = 1264;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::QInside:
		max_x = 1050; 
		min_x = 760;
		max_y = 270;
		min_y = 210;
			break;
	
	
	case MENU_NUM::QInside1:
		max_x = 1050;
		min_x = 760;
		max_y = 330;
		min_y = 270;
		break;

	case MENU_NUM::QInside2:
		max_x = 1050;
		min_x = 760;
		max_y = 390;
		min_y = 330;
		break;
	case MENU_NUM::�N�G�X�g�J�n:
		max_x = 1700;
		min_x = 1500;
		max_y = 1000;
		min_y = 900;
		break;
		}
	}

//void Quest::GetMoney(int& i) {
//	i = 100;
//}


//����
void Quest::Quest_Input() {
	int max_x, min_x, max_y, min_y, i;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	//auto trg = key_trg.second;
	GetMenuPosition(MENU_NUM::���j���[, max_x, min_x, max_y, min_y);
	//GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

	//���j���[�{�^��
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		( (mouse_x < max_x) &&
			(mouse_x > min_x)) &&
		  (mouse_y < max_y) &&
		  (mouse_y > min_y)) {

		scene = MENU_NUM::���j���[;
		q = Q::Q���j���[;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}
	
	switch (scene)
	{

	case Quest::MENU_NUM::���j���[:

		//�N�G�X�g1
		GetMenuPosition(MENU_NUM::�N�G�X�g1, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			DrawGraph(0, 0, _cg1, TRUE);
			scene = MENU_NUM::�N�G�X�g1;




		}

		//�N�G�X�g2
		GetMenuPosition(MENU_NUM::�N�G�X�g2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			scene = MENU_NUM::�N�G�X�g2;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		}

		//�N�G�X�g3
		GetMenuPosition(MENU_NUM::�N�G�X�g3, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		//�N�G�X�g4
		GetMenuPosition(MENU_NUM::�N�G�X�g4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		//�N�G�X�g5
		GetMenuPosition(MENU_NUM::�N�G�X�g5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		//�N�G�X�g6
		GetMenuPosition(MENU_NUM::�N�G�X�g6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
		}
		break;

		//�N�G�X�g�̒��g
	case MENU_NUM::�N�G�X�g1:
		GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside;
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
			q = Q::Q1;
			//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);



		}


		GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside1;
		 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
			q = Q::Q2;


		}

		GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside1;
		 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
			q = Q::Q3;
		}

		GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			q = Q::Q�N�G�X�g����;
			if (math.Judgement()) {
			//	GetMoney(i);
		
			}
			else {

			}
		}
		break;
	}
}



//�X�V
void Quest::Quest_Update() {

}



//�`��
void Quest::Quest_Render() {
	//int max_x, min_x, max_y, min_y;
	//GetMenuPosition(MENU_NUM::�N�G�X�g1, max_x, min_x, max_y, min_y);
	int no = 0;

	switch (scene)
	{
	case MENU_NUM::���j���[:
		DrawGraph(0, 0, menu, TRUE);
		//DrawGraph(400, 200, _cg, TRUE);
		DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);  //�߂�{�^��
		DrawGraph(396, 270, Q1GrHandle, TRUE);  //�摜�T�C�Y�@��260�@����310�@�ȉ�����
		DrawGraph(830, 270, Q2GrHandle, TRUE);
		DrawGraph(1264, 270, Q3GrHandle, TRUE);
		DrawGraph(396, 640, Q4GrHandle, TRUE);
		DrawGraph(830, 640, Q5GrHandle, TRUE);
		DrawGraph(1264, 640, Q6GrHandle, TRUE);
		break;

	case MENU_NUM::�N�G�X�g1:
		//DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);
		break;

	case MENU_NUM::�N�G�X�g2:
		DrawBox(1000, 45, 1850, 90, GetColor(255, 0, 0), TRUE);

		break;

	case MENU_NUM::�N�G�X�g3:
		break;

	case MENU_NUM::�N�G�X�g4:
		break;

	case MENU_NUM::�N�G�X�g5:
		break;

	case MENU_NUM::�N�G�X�g6:
		break;

	case MENU_NUM::QInside:
		DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		//DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	case MENU_NUM::QInside1:
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	}



	switch (q)
	{
	case Q::Q1:
		DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		break;
	case Q::Q2:
		DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;
	case Q::Q3:
		DrawExtendGraph(1470, 210, 1670, 360, Q3, TRUE);
		break;
	case Q::Q�N�G�X�g����:

		int max_x, min_x, max_y, min_y,no;
		int mouse_x = _game.GetMouseX();
		int mouse_y = _game.GetMouseY();
		GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);

		if(((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)&&
			(math.Judgement())){
			DrawGraph(0, 0, clear, TRUE);
			WaitKey();
			//math.Math_Update(no); 
				//no = 100;
				//return;
			
		}

		else {
			DrawGraph(0, 0, failure, TRUE);
			WaitKey();
		}
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "�����_����%d\n", no);
		
		break;

	}
}
