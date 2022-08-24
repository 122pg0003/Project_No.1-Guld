#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"Math.h"
#include "Adventurer_Status.h"
#include "TurnNumber.h"



//�R���X�g���N�^
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
	//,math(*this)
	//,_math(*this,_game,_scenemgr)
{
	_cg = LoadGraph("images/Adventurer.jpg");
	_cg1 = LoadGraph("images/�N�G�X�g���2.png");
	_BIGrHandle = LoadGraph("images/Base-Illust.png");


	//Q1GrHandle = LoadGraph("images/to-batu_s1.png");  //�N�G�X�g1�X���b�g
	//Q2GrHandle = LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g2�X���b�g
	//Q3GrHandle = LoadGraph("images/saishu_s1.png");  //�N�G�X�g3�X���b�g
	//Q4GrHandle = LoadGraph("images/others_s1.png");  //�N�G�X�g4�X���b�g
	//Q5GrHandle = LoadGraph("images/to-batu_s1.png");  //�N�G�X�g5�X���b�g
	//Q6GrHandle = LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g6�X���b�g


	QGrHandle[0] = LoadGraph("images/to-batu_s1.png");  //�N�G�X�g1�X���b�g�@����
	QGrHandle[1] = LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g2�X���b�g�@�@�h�q
	QGrHandle[2] =	LoadGraph("images/saishu_s1.png");  //�N�G�X�g3�X���b�g�@�̎�
	QGrHandle[3] =	LoadGraph("images/others_s1.png");  //�N�G�X�g4�X���b�g�@��
	QGrHandle[4] =	LoadGraph("images/to-batu_s1.png");  //�N�G�X�g5�X���b�g ����
	QGrHandle[5] =	LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g6�X���b�g   �h�q
	


	Q1 = LoadGraph("images/ch_001.mini.2.png");  //�`����1
	Q1_1 = LoadGraph("images/ch_001.mini1.png");
	Q1Start = LoadGraph("images/�o���{�^��.png");  //�o���{�^��
	Q2 = LoadGraph("images/ch_002.mini2.png");  //�`����2
	Q2_1 = LoadGraph("images/ch_002.mini1.png");
	Q3 = LoadGraph("images/ch_06.mini2.png");  //�`����3
	Q3_1 = LoadGraph("images/ch_06.mini1.png");
	menu = LoadGraph("images/Base-illust.png");  //�N�G�X�g1���g
	clear = LoadGraph("images/success.png");
	failure = LoadGraph("images/failure.png");
	Back = LoadGraph("images/back.png");
	End = FALSE;


	q = Q::Q�����l;
	TotalAttack = 0;
	TotalDefence = 0;
	TotalSkill = 0;
	TotalKnow = 0;
	AdventurerGood = 0;
	a = -1;


	Click1 = false;
	Click2 = false;
	Click3 = false;

	//random = 0;


	//questData1.SetQuestParam(5);
	//questData2.SetQuestParam(0);

}

//�f�X�g���N�^
Quest::~Quest() {

}



void QuestData::SetQuestParam(int questIndex) 
{
	//int questIndex;
	questcontent.QuestEtc(questIndex, ClearTotalAttack,
		 ClearTotalDefence,
		 ClearTotalSkill,
		 ClearTotalKnow);

}

///�X�e�[�^�X�̑����l�̒ǉ�
void Quest::Add_Quest_Adventurer_Status(int AdventurerNo) {
	AdventurerGood +=  AdventurerStatus.good[AdventurerNo];
	if (scene == Quest::MENU_NUM::�N�G�X�g1 && AdventurerNo == 1) {
		TotalAttack += AdventurerStatus.Attack[AdventurerNo] * 2;
		TotalDefence += AdventurerStatus.Defence[AdventurerNo] * 2;
		TotalSkill += AdventurerStatus.Skill[AdventurerNo] * 2;
		TotalKnow += AdventurerStatus.Know[AdventurerNo] * 2;
	}
	else {
		TotalAttack += AdventurerStatus.Attack[AdventurerNo];
		TotalDefence += AdventurerStatus.Defence[AdventurerNo];
		TotalSkill += AdventurerStatus.Skill[AdventurerNo];
		TotalKnow += AdventurerStatus.Know[AdventurerNo];
	}
}


///�X�e�[�^�X�̑����l�̍폜
void Quest::Delete_Quest_Adventurer_Status(int AdventurerNo) {
	if (scene == Quest::MENU_NUM::�N�G�X�g1 && AdventurerNo == 1) {
		TotalAttack -= AdventurerStatus.Attack[AdventurerNo] * 2;
		TotalDefence -= AdventurerStatus.Defence[AdventurerNo] * 2;
		TotalSkill -= AdventurerStatus.Skill[AdventurerNo] * 2;
		TotalKnow -= AdventurerStatus.Know[AdventurerNo] * 2;
		AdventurerGood -= AdventurerStatus.good[AdventurerNo];
	}
	else {
		TotalAttack -= AdventurerStatus.Attack[AdventurerNo];
		TotalDefence -= AdventurerStatus.Defence[AdventurerNo];
		TotalSkill -= AdventurerStatus.Skill[AdventurerNo];
		TotalKnow -= AdventurerStatus.Know[AdventurerNo];
		AdventurerGood -= AdventurerStatus.good[AdventurerNo];
	}
}





void Quest::Quest_Result() {  //�N�G�X�g�̌��ʂ�\������
	questData1.SetQuestParam(random);
	if (End == TRUE) {
		math.Judgement(questData1.ClearTotalAttack,
			questData1.ClearTotalDefence,
			questData1.ClearTotalSkill,
			questData1.ClearTotalKnow,
			TotalAttack, TotalDefence, TotalSkill, TotalKnow);
		if (math._questresult == 1) {
			ClearDrawScreen();
			DrawGraph(600, 390, clear, TRUE);
			ScreenFlip();
			WaitKey();
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		}
		else if(math._questresult == 0) {
			ClearDrawScreen();
			DrawGraph(600, 390, failure, TRUE);
			ScreenFlip();
			WaitKey();
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		}
		math._questresult = -1;
		End = FALSE;
	}
	else {
		WaitKey();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}
}

//�I�����ڂ̗̈�w��
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::���j���[:

		max_x = 1900;
		min_x = 1750;
		max_y = 170;
		min_y = 20;

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
		max_x = 1040;
		min_x = 760;
		max_y = 298;
		min_y = 210;
		break;


	case MENU_NUM::QInside1:
		max_x = 1040;
		min_x = 760;
		max_y = 386;
		min_y = 270;
		break;

	case MENU_NUM::QInside2:
		max_x = 1040;
		min_x = 760;
		max_y = 474;
		min_y = 330;
		break;
	case MENU_NUM::�N�G�X�g�J�n:
		max_x = 1980;
		min_x = 1500;
		max_y = 1060;
		min_y = 700;
		break;
	}
}

//void Quest::GetMoney(int& i) {
//	i = 100;
//}

///�N�G�X�g�̃����_���o��
void Quest::Random_Quest() {
		//random = 1;
		//scene = static_cast<MENU_NUM>(random);
	if (a == -1) {
		random =  GetRand(4) + 1;
		i = random;					 
		random1 = GetRand(4) + 1;
		b = random1;				 
		random2 = GetRand(4) + 1;
		c = random2;				 
		random3 = GetRand(4) + 1;
		d = random3;				 
		random4 = GetRand(4) + 1;
		e = random4;				 
		random5 = GetRand(4) + 1;
		g = random5;

		
		a = 0;
	}
	//random = static_cast<int>(quest_graph);
	//quest_graph = static_cast<Quest_Graph>(random);
	  //a = static_cast<int>(quest_graph);
	 
}

void Quest::RANDOM_Q(int random ,
	int random1,
	int random2,
	int random3,
	int random4,
	int random5) {
	scene = static_cast<MENU_NUM>(random);
	scene = static_cast<MENU_NUM>(random1);
	scene = static_cast<MENU_NUM>(random2);
	scene = static_cast<MENU_NUM>(random3);
	scene = static_cast<MENU_NUM>(random4);
	scene = static_cast<MENU_NUM>(random5);

}



//����
void Quest::Quest_Input() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	GetMenuPosition(MENU_NUM::���j���[, max_x, min_x, max_y, min_y);
		//a = -1;
	
	switch (q)
	{
	
	case Quest::Q::Q�����l:
		TotalAttack = 0;
		TotalDefence = 0;
		TotalSkill = 0;
		TotalKnow = 0;
		AdventurerGood = 0;
		break;
	
	}
	switch (scene)
	{

	case Quest::MENU_NUM::���j���[:
	Random_Quest();
		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			a = -1;
			scene = MENU_NUM::���j���[;
			q = Q::Q�����l;
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			
		}

		//�N�G�X�g1
		GetMenuPosition(MENU_NUM::�N�G�X�g1, max_x, min_x, max_y, min_y);
		
		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random,random1,random2,random3,random4,random5);
			scene = static_cast<MENU_NUM>(random);
			questData1.SetQuestParam(random);
			//Random_Quest();
			


		}

		//�N�G�X�g2
		GetMenuPosition(MENU_NUM::�N�G�X�g2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//Random_Quest();
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = static_cast<MENU_NUM>(random1);
			questData1.SetQuestParam(random1);
			//scene = MENU_NUM::�N�G�X�g2;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		}

		//�N�G�X�g3
		GetMenuPosition(MENU_NUM::�N�G�X�g3, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = static_cast<MENU_NUM>(random2);
			questData1.SetQuestParam(random2);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		//�N�G�X�g4
		GetMenuPosition(MENU_NUM::�N�G�X�g4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = static_cast<MENU_NUM>(random3);
			questData1.SetQuestParam(random3);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		//�N�G�X�g5
		GetMenuPosition(MENU_NUM::�N�G�X�g5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = static_cast<MENU_NUM>(random4);
			questData1.SetQuestParam(random4);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		//�N�G�X�g6
		GetMenuPosition(MENU_NUM::�N�G�X�g6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = static_cast<MENU_NUM>(random5);
			questData1.SetQuestParam(random5);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
		}
		break;

		//�N�G�X�g�̒��g
	case MENU_NUM::�N�G�X�g1:

		//Back_Button();


		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			scene = MENU_NUM::���j���[;
			q = Q::Q�����l;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			
		}


		GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside;
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
			q = Q::Q1;
			//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
			//���P�`���҂P
			if (Click1 == false) {
				Click1 = true;

				Add_Quest_Adventurer_Status(0);
			}

			else if (Click1 == true) {
				Click1 = false;
				Delete_Quest_Adventurer_Status(0);
			}
			//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		}


		GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside1;
		 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
			q = Q::Q2;
			//���P�`���҂Q
			if (Click2 == false) {
				Click2 = true;
				Add_Quest_Adventurer_Status(1);
				
			}

			else if (Click2 == true) {
				Click2 = false;
					Delete_Quest_Adventurer_Status(1);
				
			}

		}

		GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside1;
		 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
			q = Q::Q3;
			//��2�`���҂R
			if (Click3 == false) {
				Click3 = true;
				Add_Quest_Adventurer_Status(2);
			}

			else if (Click3 == true) {
				Click3 = false;
				Delete_Quest_Adventurer_Status(2);
			}
		}

		GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



		//int Mause = _gmause;
		//_gmause = GetMouseInput();
		//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//math.Judgement();
			q = Q::Q�N�G�X�g����;
			//	q = Q::Q���j���[;
				//if (math.Judgement()) {
				////	GetMoney(i);

				//	WaitKey();
				//}
				//else {

				//}
			//Click1 = false;
			//Click2 = false;
			//Click3 = false;
			
		}
		break;
		case MENU_NUM::�N�G�X�g2:

			//Back_Button();


			if ((_mousetrg != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {

				scene = MENU_NUM::���j���[;
				q = Q::Q�����l;
				//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			
			}


			GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

			if ((_mousetrg != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {
				//scene = MENU_NUM::QInside;
			//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
				q = Q::Q1;
				//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
				//���P�`���҂P
				if (Click1 == false) {
					Click1 = true;
					Add_Quest_Adventurer_Status(0);
				}

				else if (Click1 == true) {
					Click1 = false;
					Delete_Quest_Adventurer_Status(0);
				}
				//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
			}


			GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

			if ((_mousetrg != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {
				//scene = MENU_NUM::QInside1;
			 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
				q = Q::Q2;
				//���P�`���҂Q
				if (Click2 == false) {
					Click2 = true;
					Add_Quest_Adventurer_Status(1);
				}

				else if (Click2 == true) {
					Click2 = false;
					Delete_Quest_Adventurer_Status(1);
				}

			}

			GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

			if ((_mousetrg != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {
				//scene = MENU_NUM::QInside1;
			 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
				q = Q::Q3;
				//��2�`���҂R
				if (Click3 == false) {
					Click3 = true;
					Add_Quest_Adventurer_Status(2);
				}

				else if (Click3 == true) {
					Click3 = false;
					Delete_Quest_Adventurer_Status(2);
				}
			}

			GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



			//int Mause = _gmause;
			//_gmause = GetMouseInput();
			//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

			if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {
				//math.Judgement();
				q = Q::Q�N�G�X�g����;
				//	q = Q::Q���j���[;
					//if (math.Judgement()) {
					////	GetMoney(i);

					//	WaitKey();
					//}
					//else {

					//}
				//Click1 = false;
				//Click2 = false;
				//Click3 = false;

			}
			break;

			case MENU_NUM::�N�G�X�g3:

				//Back_Button();


				if ((_mousetrg != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {

					scene = MENU_NUM::���j���[;
					q = Q::Q�����l;
					//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		
				}


				GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

				if ((_mousetrg != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {
					//scene = MENU_NUM::QInside;
				//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
					q = Q::Q1;
					//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
					//���P�`���҂P
					if (Click1 == false) {
						Click1 = true;

						Add_Quest_Adventurer_Status(0);
					}

					else if (Click1 == true) {
						Click1 = false;
						Delete_Quest_Adventurer_Status(0);
					}
					//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
				}


				GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

				if ((_mousetrg != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {
					//scene = MENU_NUM::QInside1;
				 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
					q = Q::Q2;
					//���P�`���҂Q
					if (Click2 == false) {
						Click2 = true;
						Add_Quest_Adventurer_Status(1);
					}

					else if (Click2 == true) {
						Click2 = false;
						Delete_Quest_Adventurer_Status(1);
					}

				}

				GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

				if ((_mousetrg != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {
					//scene = MENU_NUM::QInside1;
				 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
					q = Q::Q3;
					//��2�`���҂R
					if (Click3 == false) {
						Click3 = true;
						Add_Quest_Adventurer_Status(2);
					}

					else if (Click3 == true) {
						Click3 = false;
						Delete_Quest_Adventurer_Status(2);
					}
				}

				GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



				//int Mause = _gmause;
				//_gmause = GetMouseInput();
				//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

				if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {
					//math.Judgement();
					q = Q::Q�N�G�X�g����;
					//	q = Q::Q���j���[;
						//if (math.Judgement()) {
						////	GetMoney(i);

						//	WaitKey();
						//}
						//else {

						//}
					//Click1 = false;
					//Click2 = false;
					//Click3 = false;

				}
				break;
				case MENU_NUM::�N�G�X�g4:

					//Back_Button();


					if ((_mousetrg != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {

						scene = MENU_NUM::���j���[;
						q = Q::Q�����l;
						//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
					
					}


					GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

					if ((_mousetrg != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {
						//scene = MENU_NUM::QInside;
					//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
						q = Q::Q1;
						//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
						//���P�`���҂P
						if (Click1 == false) {
							Click1 = true;

							Add_Quest_Adventurer_Status(0);
						}

						else if (Click1 == true) {
							Click1 = false;
							Delete_Quest_Adventurer_Status(0);
						}
						//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
					}


					GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

					if ((_mousetrg != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {
						//scene = MENU_NUM::QInside1;
					 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
						q = Q::Q2;
						//���P�`���҂Q
						if (Click2 == false) {
							Click2 = true;
							Add_Quest_Adventurer_Status(1);
						}

						else if (Click2 == true) {
							Click2 = false;
							Delete_Quest_Adventurer_Status(1);
						}

					}

					GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

					if ((_mousetrg != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {
						//scene = MENU_NUM::QInside1;
					 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
						q = Q::Q3;
						//��2�`���҂R
						if (Click3 == false) {
							Click3 = true;
							Add_Quest_Adventurer_Status(2);
						}

						else if (Click3 == true) {
							Click3 = false;
							Delete_Quest_Adventurer_Status(2);
						}
					}

					GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



					//int Mause = _gmause;
					//_gmause = GetMouseInput();
					//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

					if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {
						//math.Judgement();
						q = Q::Q�N�G�X�g����;
						//	q = Q::Q���j���[;
							//if (math.Judgement()) {
							////	GetMoney(i);

							//	WaitKey();
							//}
							//else {

							//}
						//Click1 = false;
						//Click2 = false;
						//Click3 = false;

					}
					break;
					case MENU_NUM::�N�G�X�g5:

						//Back_Button();


						if ((_mousetrg != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {

							scene = MENU_NUM::���j���[;
							q = Q::Q�����l;
							//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
							
						}


						GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

						if ((_mousetrg != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {
							//scene = MENU_NUM::QInside;
						//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
							q = Q::Q1;
							//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
							//���P�`���҂P
							if (Click1 == false) {
								Click1 = true;

								Add_Quest_Adventurer_Status(0);
							}

							else if (Click1 == true) {
								Click1 = false;
								Delete_Quest_Adventurer_Status(0);
							}
							//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
						}


						GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

						if ((_mousetrg != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {
							//scene = MENU_NUM::QInside1;
						 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
							q = Q::Q2;
							//���P�`���҂Q
							if (Click2 == false) {
								Click2 = true;
								Add_Quest_Adventurer_Status(1);
							}

							else if (Click2 == true) {
								Click2 = false;
								Delete_Quest_Adventurer_Status(1);
							}

						}

						GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

						if ((_mousetrg != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {
							//scene = MENU_NUM::QInside1;
						 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
							q = Q::Q3;
							//��2�`���҂R
							if (Click3 == false) {
								Click3 = true;
								Add_Quest_Adventurer_Status(2);
							}

							else if (Click3 == true) {
								Click3 = false;
								Delete_Quest_Adventurer_Status(2);
							}
						}

						GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



						//int Mause = _gmause;
						//_gmause = GetMouseInput();
						//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

						if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {
							//math.Judgement();
							q = Q::Q�N�G�X�g����;
							//	q = Q::Q���j���[;
								//if (math.Judgement()) {
								////	GetMoney(i);

								//	WaitKey();
								//}
								//else {

								//}
							//Click1 = false;
							//Click2 = false;
							//Click3 = false;

						}
						break;
						case MENU_NUM::�N�G�X�g6:

							//Back_Button();


							if ((_mousetrg != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {

								scene = MENU_NUM::���j���[;
								q = Q::Q�����l;
								//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
							
							}


							GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

							if ((_mousetrg != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {
								//scene = MENU_NUM::QInside;
							//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
								q = Q::Q1;
								//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
								//���P�`���҂P
								if (Click1 == false) {
									Click1 = true;

									Add_Quest_Adventurer_Status(0);
								}

								else if (Click1 == true) {
									Click1 = false;
									Delete_Quest_Adventurer_Status(0);
								}
								//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
							}


							GetMenuPosition(MENU_NUM::QInside1, max_x, min_x, max_y, min_y);

							if ((_mousetrg != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {
								//scene = MENU_NUM::QInside1;
							 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
								q = Q::Q2;
								//���P�`���҂Q
								if (Click2 == false) {
									Click2 = true;
									Add_Quest_Adventurer_Status(1);
								}

								else if (Click2 == true) {
									Click2 = false;
									Delete_Quest_Adventurer_Status(1);
								}

							}

							GetMenuPosition(MENU_NUM::QInside2, max_x, min_x, max_y, min_y);

							if ((_mousetrg != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {
								//scene = MENU_NUM::QInside1;
							 //DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
								q = Q::Q3;
								//��2�`���҂R
								if (Click3 == false) {
									Click3 = true;
									Add_Quest_Adventurer_Status(2);
								}

								else if (Click3 == true) {
									Click3 = false;
									Delete_Quest_Adventurer_Status(2);
								}
							}

							GetMenuPosition(MENU_NUM::�N�G�X�g�J�n, max_x, min_x, max_y, min_y);



							//int Mause = _gmause;
							//_gmause = GetMouseInput();
							//_gTrg = (_gmause ^ Mause) & _gmause;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j

							if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {
								//math.Judgement();
								q = Q::Q�N�G�X�g����;
								//	q = Q::Q���j���[;
									//if (math.Judgement()) {
									////	GetMoney(i);

									//	WaitKey();
									//}
									//else {

									//}
								//Click1 = false;
								//Click2 = false;
								//Click3 = false;

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
	//int no = 0;
		//int i = GetRand(6);
	switch (scene)
	{
	case MENU_NUM::���j���[:
	  
		//DrawGraph(0, 0, _bg, TRUE);//��ɔw�i���\�������悤�ɂ�����

		DrawGraph(135, 185, menu, TRUE);
		//DrawGraph(400, 200, _cg, TRUE);
		//DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);  //�߂�{�^��

		//DrawGraph(396, 270, Q1GrHandle, TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		//DrawGraph(830, 270, Q2GrHandle, TRUE);  //�N�G�X�g�X���b�g2
		//DrawGraph(1264,270, Q3GrHandle, TRUE);	//�N�G�X�g�X���b�g3
		//DrawGraph(396, 640, Q4GrHandle, TRUE);	//�N�G�X�g�X���b�g4
		//DrawGraph(830, 640, Q5GrHandle, TRUE);	//�N�G�X�g�X���b�g5
		//DrawGraph(1264,640, Q6GrHandle, TRUE);	//�N�G�X�g�X���b�g6
		if (i == 0) {

		DrawGraph(396, 270, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (i == 1) {
			DrawGraph(396, 270, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (i == 2) {
		DrawGraph(396,270, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (i == 3) {
		DrawGraph(396, 270, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (i == 4) {
		DrawGraph(396, 270, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (i == 5) {
		DrawGraph(396, 270, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}

		if (b == 0) {

			DrawGraph(830, 270, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (b == 1) {
			DrawGraph(830, 270, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (b == 2) {
			DrawGraph(830, 270, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (b == 3) {
			DrawGraph(830, 270, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (b == 4) {
			DrawGraph(830, 270, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (b == 5) {
			DrawGraph(830, 270, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}

		if (c == 0) {

			DrawGraph(1264, 270, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (c == 1) {
			DrawGraph(1264, 270, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (c == 2) {
			DrawGraph(1264, 270, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (c == 3) {
			DrawGraph(1264, 270, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (c == 4) {
			DrawGraph(1264, 270, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (c == 5) {
			DrawGraph(1264, 270, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}


		if (d == 0) {
			DrawGraph(396, 640, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (d == 1) {
			DrawGraph(396, 640, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (d == 2) {
			DrawGraph(396, 640, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (d == 3) {
			DrawGraph(396, 640, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (d == 4) {
			DrawGraph(396, 640, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (d == 5) {
			DrawGraph(396, 640, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}


		if (e == 0) {
			DrawGraph(830, 640, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (e == 1) {
			DrawGraph(830, 640, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (e == 2) {
			DrawGraph(830, 640, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (e == 3) {
			DrawGraph(830, 640, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (e == 4) {
			DrawGraph(830, 640, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (e == 5) {
			DrawGraph(830, 640, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}


		if (g == 0) {
			DrawGraph(1264, 640, QGrHandle[0], TRUE);  //�N�G�X�g�X���b�g1   �摜�T�C�Y�@��260�@����310�@�ȉ�����
		}
		if (g == 1) {
			DrawGraph(1264, 640, QGrHandle[1], TRUE);  //�N�G�X�g�X���b�g2
		}
		if (g == 2) {
			DrawGraph(1264, 640, QGrHandle[2], TRUE);	//�N�G�X�g�X���b�g3
		}
		if (g == 3) {
			DrawGraph(1264, 640, QGrHandle[3], TRUE);	//�N�G�X�g�X���b�g4
		}
		if (g == 4) {
			DrawGraph(1264, 640, QGrHandle[4], TRUE);	//�N�G�X�g�X���b�g5
		}
		if (g == 5) {
			DrawGraph(1264, 640, QGrHandle[5], TRUE);	//�N�G�X�g�X���b�g6
		}


		DrawGraph(1750, 20, Back, TRUE);
		break;

	case MENU_NUM::�N�G�X�g1:
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		//DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		//DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		//DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		//DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE); //�N�G�X�g�o��
		DrawString(100, 100, "�N�G�X�g1", TRUE);
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);
		//DrawFormatString(1000, 980, GetColor(0, 0, 0), "���ӕs����%d", questData1.ClearTotalKnow);

		break;

	case MENU_NUM::�N�G�X�g2:
		//DrawBox(1000, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g2", TRUE);

		break;

	case MENU_NUM::�N�G�X�g3:
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/

		DrawString(100, 100, "�N�G�X�g3", TRUE);
		break;

	case MENU_NUM::�N�G�X�g4:
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g4", TRUE);

		break;

	case MENU_NUM::�N�G�X�g5:
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g5", TRUE);

		break;

	case MENU_NUM::�N�G�X�g6:
		DrawGraph(0, 0, _cg1, TRUE); //�w�i
		DrawGraph(760, 210, Q1_1, TRUE);    //�`����1
		DrawGraph(760, 298, Q2_1, TRUE);   //�`����2
		DrawGraph(760, 386, Q3_1, TRUE);   //�`����3
		DrawGraph(1500, 700, Q1Start, TRUE);//�N�G�X�g�o��
		DrawFormatString(1000, 680, GetColor(0, 0, 0), "�A�^�b�N%d", questData1.ClearTotalAttack);
		DrawFormatString(1000, 780, GetColor(0, 0, 0), "�f�B�t�F���X%d", questData1.ClearTotalDefence);
		DrawFormatString(1000, 880, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1000, 980, GetColor(0, 0, 0), "�m��%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g6", TRUE);

		break;

	case MENU_NUM::QInside:
		
		//DrawGraph(1070, 210, Q1Start, TRUE);
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		//DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	case MENU_NUM::QInside1:
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
	//	DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	}
	if (q != Q::Q�����l)
	{



		int FontHandle = CreateFontToHandle(NULL, 40, 3);
		DrawFormatStringToHandle(880, 680, GetColor(0, 0, 0), FontHandle, "�U%d", TotalAttack);
		DrawFormatStringToHandle(880, 760, GetColor(0, 0, 0), FontHandle, "��%d", TotalDefence);
		DrawFormatStringToHandle(880, 840, GetColor(0, 0, 0), FontHandle, "�Z%d", TotalSkill);
		DrawFormatStringToHandle(880, 920, GetColor(0, 0, 0), FontHandle, "�m%d", TotalKnow);
		DrawFormatStringToHandle(1000, 920, GetColor(0, 0, 0), FontHandle, "����%d", AdventurerGood);
		//DrawFormatString(1000, 680, GetColor(0, 0, 0), "������%d", math.SuccessRate);
		DeleteFontToHandle(FontHandle);

		/*if (TotalAttack >= questData1.ClearTotalAttack)
			math.SuccessRate += 25;*/
	}

	switch (q)
	{
	case Q::Q���j���[:
		DrawGraph(1750, 20, Back, TRUE);
		Click1 = false;  //�R�R����break�܂ł̏����͍ēx�N�G�X�g��I�������ۂɖ`���҂����Ȃ���Ԃɂ������
		Click2 = false;
		Click3 = false;
		TotalAttack = 0;
		TotalDefence = 0;
		TotalSkill = 0;
		TotalKnow = 0;

		break;
	case Q::Q1:
	{
		if (Click2 == true) {
			DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		}
		if (Click3 == true) {
			DrawExtendGraph(1470, 210, 1670, 360, Q3, TRUE);
		}
		if (Click1 == true) {
			DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);

			break;
		}
		else {

			break;
		}
	}
	case Q::Q2:

	{
		if (Click3 == true) {
			DrawExtendGraph(1470, 210, 1670, 360, Q3, TRUE);
		}
		if (Click1 == true) {
			DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		}
		if (Click2 == true) {
			DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);

		}
		else {

		}
	}break;
	case Q::Q3:
	{
		if (Click1 == true) {
			DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		}
		if (Click2 == true) {
			DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		}
		if (Click3 == true) {
			DrawExtendGraph(1470, 210, 1670, 360, Q3, TRUE);

		}
		else {

		}
		break;
	}
	case Q::Q�N�G�X�g����: 
		//DrawGraph(100, 100, clear, TRUE);
		//math._questresult = rand() % 2;
		//questData1.SetQuestParam( rand() % 12);
		//turnnumber.Start = TRUE;
		End = TRUE;
		//WaitKey();
		scene = MENU_NUM::���j���[;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		q = Q::Q�����l;
		break;
	   
	}
}
