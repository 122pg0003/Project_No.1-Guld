#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
//#include"Math.h"
#include "Adventurer_Status.h"
#include "TurnNumber.h"
#include"Graph.h"
#include <memory>
#include <vector>

int random;
int random1;
int random2;
int random3;
int random4;
int random5;

//�R���X�g���N�^
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
{

	_BIGrHandle = LoadGraph("images/Base-Illust.png");

	///�N�G�X�g�̃X���b�g
	QGrHandle[0] = LoadGraph("images/to-batu_s1.png");  //�N�G�X�g1�X���b�g�@����
	QGrHandle[1] = LoadGraph("images/saishu_s1.png");  //�N�G�X�g2�X���b�g�@�@�̎�
	QGrHandle[2] =	LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g3�X���b�g�@�h�q
	QGrHandle[3] =	LoadGraph("images/others_s1.png");  //�N�G�X�g4�X���b�g�@��
	QGrHandle[4] =	LoadGraph("images/to-batu_s1.png");  //�N�G�X�g5�X���b�g ����
	QGrHandle[5] =	LoadGraph("images/bo-ei_s1.png");  //�N�G�X�g6�X���b�g   �h�q
	


	Q1     = LoadGraph("images/ch_001.mini.2 (1).png");  //�`����1
	Q1_1 = LoadGraph("images/ch_001.mini1 (2).png");

	Q2     = LoadGraph("images/ch_002.mini2.png");  //�`����2
	Q2_1 = LoadGraph("images/ch_02.mini1.png");

	Q3     = LoadGraph("images/ch_06.mini3.png");  //�`����3
	Q3_1 = LoadGraph("images/ch_06.mini1 (1).png");

	Q4     = LoadGraph("images/ch_09_mini03.png");//�`����4
	Q4_1 = LoadGraph("images/ch_09_mini01.png");

	Q5 = LoadGraph("images/ch_03_mini03.png");//�`����4
	Q5_1     = LoadGraph("images/ch_03_mini01.png");//�`����5

	Q6 = LoadGraph("images/ch_005_mini03.png");//�`����4
	Q6_1     = LoadGraph("images/ch_005_mini01.png");//�`����6

	Q7 = LoadGraph("images/ch_08_mini3.png");//�`����4
	Q7_1 = LoadGraph("images/ch_08_mini1.png");//�`����6


	QuestStart = LoadGraph("images/�o���{�^��.png");  //�o���{�^��
	menu = LoadGraph("images/window.png");  //�N�G�X�g1���g
	clear = LoadGraph("images/result.png");
	failure = LoadGraph("images/result02.png");
	Back = LoadGraph("images/back.png");
	End = FALSE;


	q = Q::Q�����l;
	TotalAttack = 0;
	TotalDefence = 0;
	TotalSkill = 0;
	TotalKnow = 0;
	AdventurerGood = 0;
	a = -1;
	b = -1;


	Click1 = false;
	Click2 = false;
	Click3 = false;
	Click4 = false;

	random = 0;
	random1 = 0;
	random2 = 0;
	random3 = 0;
	random4 = 0;
	random5 = 0;
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
	if (scene == Quest::MENU_NUM::�N�G�X�g1 && AdventurerNo == 1 &&
		random == 1 || random == 3 ) {
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
	if (scene == Quest::MENU_NUM::�N�G�X�g1 && AdventurerNo == 1 &&
		random == 1 || random == 3) {
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
		Judgement(questData1.ClearTotalAttack,
			questData1.ClearTotalDefence,
			questData1.ClearTotalSkill,
			questData1.ClearTotalKnow,
			TotalAttack, TotalDefence, TotalSkill, TotalKnow);
		if (_questresult == 1) {
			ClearDrawScreen();
			DrawGraph(0, 0, clear, TRUE);
			ScreenFlip();
			WaitKey();
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		}
		else if(_questresult == 0) {
			ClearDrawScreen();
			DrawGraph(0, 0, failure, TRUE);
			ScreenFlip();
			WaitKey();
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		}
		_questresult = -1;
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
		max_y = 1050;
		min_y = 190;

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
		///�`����1
	case MENU_NUM::QuestAdventurer1:
		max_x = 897;
		min_x = 760;
		max_y = 298;
		min_y = 210;
		break;

		///�`����2
	case MENU_NUM::QuestAdventurer2:
		max_x = 1034;
		min_x = 897;
		max_y = 298;
		min_y = 210;
		break;

		///�`����3
	case MENU_NUM::QuestAdventurer3:
		max_x = 897;
		min_x = 760;
		max_y = 474;
		min_y = 330;
		break;

	case MENU_NUM::QuestAdventurer4:
		max_x = 1034;
		min_x = 897;
		max_y = 474;
		min_y = 330;
		break;

	case MENU_NUM::�N�G�X�g�J�n:
		max_x = 1823;
		min_x = 1573;
		max_y = 928;
		min_y = 678;
		break;
	}
}

//void Quest::GetMoney(int& i) {
//	i = 100;
//}

///�N�G�X�g�̃����_���o��
void Quest::Random_Quest() {
	int tmp[7], i, j, flag;
	

	for (i = 1; i <= 6; i++) {
		flag = TRUE;
		while (flag) {
			flag = FALSE;

			if (_game.GetQuest() <= 0) {
				tmp[i] = rand() % 10 + 1;
			}
			if (_game.GetQuest() >=100) {
				tmp[i] = rand() % 10 + 11;
			}

			for (j = 1; j < i; j++) {
				if (tmp[j] == tmp[i]) {
					flag = TRUE;
					break;
				}
			}
		}
	}
	random = tmp[1];
	random1 = tmp[2];
	random2 = tmp[3];
	random3 = tmp[4];
	random4 = tmp[5];
	random5 = tmp[6];
	//random6 = tmp[6];

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

		Click1 = false;
		Click2 = false;
		Click3 = false;
		Click4 = false;
		break;
	
	}


	switch (scene)
	{

	case Quest::MENU_NUM::���j���[:
	//Random_Quest();
		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			
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
			//RANDOM_Q(random,random1,random2,random3,random4,random5);
			scene = MENU_NUM::�N�G�X�g1;
			//scene = static_cast<MENU_NUM>(random);
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
			scene = MENU_NUM::�N�G�X�g2;
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
			scene = MENU_NUM::�N�G�X�g3;
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
			scene = MENU_NUM::�N�G�X�g4;
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
			scene = MENU_NUM::�N�G�X�g5;
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
			scene = MENU_NUM::�N�G�X�g6;
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


		GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


		GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

		GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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

		GetMenuPosition(MENU_NUM::QuestAdventurer4, max_x, min_x, max_y, min_y);

		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//scene = MENU_NUM::QInside;
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
			q = Q::Q4;
			//�N���b�N���ꂽ��X�e�[�^�X�ɐ��l���v���X�A������x�����ꂽ��}�C�i�X����
			//���P�`���҂P
			if (Click4 == false) {
				Click4 = true;

				Add_Quest_Adventurer_Status(2);
			}

			else if (Click4 == true) {
				Click4 = false;
				Delete_Quest_Adventurer_Status(2);
			}
			//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
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
			//Quest_Result();
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


			GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


			GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

			GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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


				GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


				GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

				GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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


					GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


					GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

					GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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


						GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


						GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

						GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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


							GetMenuPosition(MENU_NUM::QuestAdventurer1, max_x, min_x, max_y, min_y);

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


							GetMenuPosition(MENU_NUM::QuestAdventurer2, max_x, min_x, max_y, min_y);

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

							GetMenuPosition(MENU_NUM::QuestAdventurer3, max_x, min_x, max_y, min_y);

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
	//_game.GetRandom();
	//_game.GetRandom1();
	//_game.GetRandom2();
	//_game.GetRandom3();
	//_game.GetRandom4();
	//_game.GetRandom5();


	switch (scene)
	{
	case MENU_NUM::���j���[:
		DrawGraph(135, 185, menu, TRUE);
		graph.Quest_Slot_Level1(random);
		graph.Quest_Slot_Level1_2(random1);
		graph.Quest_Slot_Level1_3(random2);
		graph.Quest_Slot_Level1_4(random3);
		graph.Quest_Slot_Level1_5(random4);
		graph.Quest_Slot_Level1_6(random5);
		DrawGraph(1750, 900, Back, TRUE);
		break;

	case MENU_NUM::�N�G�X�g1:
		graph.GraphQuest_Level1(random);  //�N�G�X�g�̒��g
		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);
		
		DrawString(100, 100, "�N�G�X�g1", TRUE);
		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);
		//DrawFormatString(1000, 980, GetColor(0, 0, 0), "���ӕs����%d", questData1.ClearTotalKnow);

		break;

	case MENU_NUM::�N�G�X�g2:
		graph.GraphQuest_Level1(random1);
		

		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g2", TRUE);

		break;

	case MENU_NUM::�N�G�X�g3:
		graph.GraphQuest_Level1(random2);

		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/

		DrawString(100, 100, "�N�G�X�g3", TRUE);
		break;

	case MENU_NUM::�N�G�X�g4:
		graph.GraphQuest_Level1(random3);

		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g4", TRUE);

		break;

	case MENU_NUM::�N�G�X�g5:
		graph.GraphQuest_Level1(random4);

		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g5", TRUE);

		break;

	case MENU_NUM::�N�G�X�g6:
		graph.GraphQuest_Level1(random5);

		DrawGraph(763, 208, Q1_1, TRUE);    //�`����1
		DrawGraph(900, 208, Q2_1, TRUE);   //�`����2
		DrawGraph(763, 318, Q5_1, TRUE);   //�`����3
		DrawGraph(900, 318, Q3_1, TRUE);   //�`����4
		DrawGraph(763, 428, Q6_1, TRUE);   //�`����5
		DrawGraph(900, 428, Q7_1, TRUE);   //�`����6
		DrawGraph(763, 538, Q4_1, TRUE);   //�`����7
		DrawGraph(1500, 700, QuestStart, TRUE);//�N�G�X�g�o��
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "�U����%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "�h���%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "�X�L��%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "����%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "�N�G�X�g6", TRUE);

		break;

	case MENU_NUM::QuestAdventurer1:
		
		//DrawGraph(1070, 210, Q1Start, TRUE);
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
		//DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	case MENU_NUM::QuestAdventurer2:
		//DrawExtendGraph(1070, 210, 1270, 360, Q1, TRUE);
	//	DrawExtendGraph(1270, 210, 1470, 360, Q2, TRUE);
		break;

	}
	if (q != Q::Q�����l)
	{



		int FontHandle = CreateFontToHandle(NULL, 40, 3);
		DrawFormatStringToHandle(780, 680, GetColor(0, 0, 0), FontHandle, "�����o�[�̑����l");
		DrawFormatStringToHandle(880, 720, GetColor(0, 0, 0), FontHandle, "�U%d", TotalAttack);
		DrawFormatStringToHandle(880, 770, GetColor(0, 0, 0), FontHandle, "��%d", TotalDefence);
		DrawFormatStringToHandle(880, 820, GetColor(0, 0, 0), FontHandle, "�Z%d", TotalSkill);
		DrawFormatStringToHandle(880, 870, GetColor(0, 0, 0), FontHandle, "�m%d", TotalKnow);
		//DrawFormatStringToHandle(1000, 920, GetColor(0, 0, 0), FontHandle, "����%d", AdventurerGood);
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
		Click4 = false;

		TotalAttack = 0;
		TotalDefence = 0;
		TotalSkill = 0;
		TotalKnow = 0;

		break;
	case Q::Q1:
	{
		if (Click2 == true) {
		DrawGraph(1270, 210,Q2, TRUE);
    }
		if (Click3 == true) {
			DrawGraph(1470, 210,Q3, TRUE);
		}
		if (Click1 == true) {
			DrawGraph(1070, 210,Q1, TRUE);
		}
		if (Click4 == true) {
			DrawGraph(1470, 210,Q4, TRUE);
		}
		else {

			break;
		}
	}

	case Q::Q2:

	{
		if (Click3 == true) {
			DrawGraph(1470, 210,Q3, TRUE);
		}
		if (Click1 == true) {
			DrawGraph(1070, 210,Q1, TRUE);
		}
		if (Click2 == true) {
			DrawGraph(1270, 210,Q2, TRUE);
		}
		if (Click4 == true) {
		DrawGraph(1470, 210,Q4, TRUE);
		}
		else {

	break;
		}
	}

	case Q::Q3:
	{
		if (Click1 == true) {
			DrawGraph(1070, 210,Q1, TRUE);
		}
		if (Click2 == true) {
			DrawGraph(1270, 210,Q2, TRUE);
		}
		if (Click3 == true) {
			DrawGraph(1470, 210,Q3, TRUE);

		}
		if (Click4 == true) {
			DrawGraph(1470, 210,Q4, TRUE);

		}
		else {

			break;
		}
	}

	case Q::Q4:
	{
		if (Click1 == true) {
			DrawGraph(1070, 210,Q1, TRUE);
		}
		if (Click2 == true) {
			DrawGraph(1270, 210,Q2, TRUE);
		}
		if (Click4 == true) {
			DrawGraph(1470, 210,Q4, TRUE);

		}
		if (Click3 == true) {
			DrawGraph(1470, 210,Q3, TRUE);

		}
		else {

			break;
		}
	}

	case Q::Q�N�G�X�g����: 
		//DrawGraph(100, 100, clear, TRUE);
		//math._questresult = rand() % 2;
		//questData1.SetQuestParam( rand() % 12);
		//turnnumber.Start = TRUE;
		End = TRUE;
		//WaitKey();
		scene = MENU_NUM::���j���[;
		Quest_Result();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		q = Q::Q�����l;
		break;
	   
	}
}
