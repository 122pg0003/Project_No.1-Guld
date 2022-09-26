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

//コンストラクタ
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
{

	_BIGrHandle = LoadGraph("images/Base-Illust.png");

	///クエストのスロット
	QGrHandle[0] = LoadGraph("images/to-batu_s1.png");  //クエスト1スロット　討伐
	QGrHandle[1] = LoadGraph("images/saishu_s1.png");  //クエスト2スロット　　採取
	QGrHandle[2] =	LoadGraph("images/bo-ei_s1.png");  //クエスト3スロット　防衛
	QGrHandle[3] =	LoadGraph("images/others_s1.png");  //クエスト4スロット　他
	QGrHandle[4] =	LoadGraph("images/to-batu_s1.png");  //クエスト5スロット 討伐
	QGrHandle[5] =	LoadGraph("images/bo-ei_s1.png");  //クエスト6スロット   防衛
	


	Q1     = LoadGraph("images/ch_001.mini.2 (1).png");  //冒険者1
	Q1_1 = LoadGraph("images/ch_001.mini1 (2).png");

	Q2     = LoadGraph("images/ch_002.mini2.png");  //冒険者2
	Q2_1 = LoadGraph("images/ch_02.mini1.png");

	Q3     = LoadGraph("images/ch_06.mini3.png");  //冒険者3
	Q3_1 = LoadGraph("images/ch_06.mini1 (1).png");

	Q4     = LoadGraph("images/ch_09_mini03.png");//冒険者4
	Q4_1 = LoadGraph("images/ch_09_mini01.png");

	Q5 = LoadGraph("images/ch_03_mini03.png");//冒険者4
	Q5_1     = LoadGraph("images/ch_03_mini01.png");//冒険者5

	Q6 = LoadGraph("images/ch_005_mini03.png");//冒険者4
	Q6_1     = LoadGraph("images/ch_005_mini01.png");//冒険者6

	Q7 = LoadGraph("images/ch_08_mini3.png");//冒険者4
	Q7_1 = LoadGraph("images/ch_08_mini1.png");//冒険者6


	QuestStart = LoadGraph("images/出撃ボタン.png");  //出撃ボタン
	menu = LoadGraph("images/window.png");  //クエスト1中身
	clear = LoadGraph("images/result.png");
	failure = LoadGraph("images/result02.png");
	Back = LoadGraph("images/back.png");
	End = FALSE;


	q = Q::Q初期値;
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


//デストラクタ
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

///ステータスの総合値の追加
void Quest::Add_Quest_Adventurer_Status(int AdventurerNo) {
	if (scene == Quest::MENU_NUM::クエスト1 && AdventurerNo == 1 &&
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


///ステータスの総合値の削除
void Quest::Delete_Quest_Adventurer_Status(int AdventurerNo) {
	if (scene == Quest::MENU_NUM::クエスト1 && AdventurerNo == 1 &&
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





void Quest::Quest_Result() {  //クエストの結果を表示する
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

//選択項目の領域指定
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::メニュー:

		max_x = 1900;
		min_x = 1750;
		max_y = 1050;
		min_y = 190;

		break;

	case MENU_NUM::クエスト1:

		max_x = 656;
		min_x = 396;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::クエスト2:

		max_x = 1090;
		min_x = 830;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::クエスト3:

		max_x = 1524;
		min_x = 1264;
		max_y = 580;
		min_y = 270;

		break;
	case MENU_NUM::クエスト4:

		max_x = 656;
		min_x = 396;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::クエスト5:

		max_x = 1090;
		min_x = 830;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::クエスト6:

		max_x = 1524;
		min_x = 1264;
		max_y = 950;
		min_y = 640;

		break;
		///冒険者1
	case MENU_NUM::QuestAdventurer1:
		max_x = 897;
		min_x = 760;
		max_y = 298;
		min_y = 210;
		break;

		///冒険者2
	case MENU_NUM::QuestAdventurer2:
		max_x = 1034;
		min_x = 897;
		max_y = 298;
		min_y = 210;
		break;

		///冒険者3
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

	case MENU_NUM::クエスト開始:
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

///クエストのランダム出現
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



//入力
void Quest::Quest_Input() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);
		//a = -1;
	
	switch (q)
	{
	
	case Quest::Q::Q初期値:
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

	case Quest::MENU_NUM::メニュー:
	//Random_Quest();
		if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			
			scene = MENU_NUM::メニュー;
			q = Q::Q初期値;
			
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			
		}

		//クエスト1
		GetMenuPosition(MENU_NUM::クエスト1, max_x, min_x, max_y, min_y);
		
		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//RANDOM_Q(random,random1,random2,random3,random4,random5);
			scene = MENU_NUM::クエスト1;
			//scene = static_cast<MENU_NUM>(random);
			questData1.SetQuestParam(random);
			//Random_Quest();
			


		}

		//クエスト2
		GetMenuPosition(MENU_NUM::クエスト2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//Random_Quest();
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = MENU_NUM::クエスト2;
			questData1.SetQuestParam(random1);
			//scene = MENU_NUM::クエスト2;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		}

		//クエスト3
		GetMenuPosition(MENU_NUM::クエスト3, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = MENU_NUM::クエスト3;
			questData1.SetQuestParam(random2);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		//クエスト4
		GetMenuPosition(MENU_NUM::クエスト4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = MENU_NUM::クエスト4;
			questData1.SetQuestParam(random3);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		//クエスト5
		GetMenuPosition(MENU_NUM::クエスト5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = MENU_NUM::クエスト5;
			questData1.SetQuestParam(random4);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		//クエスト6
		GetMenuPosition(MENU_NUM::クエスト6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			RANDOM_Q(random, random1, random2, random3, random4, random5);
			scene = MENU_NUM::クエスト6;
			questData1.SetQuestParam(random5);
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
		}
		break;

		//クエストの中身
	case MENU_NUM::クエスト1:

		//Back_Button();


	if ((_mousetrg != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
	
			scene = MENU_NUM::メニュー;
			q = Q::Q初期値;
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
			//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
			//星１冒険者１
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
			//星１冒険者２
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
			//星2冒険者３
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
			//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
			//星１冒険者１
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


		GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



		//int Mause = _gmause;
		//_gmause = GetMouseInput();
		//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//math.Judgement();
			q = Q::Qクエスト判定;
			//Quest_Result();
			//	q = Q::Qメニュー;
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

		case MENU_NUM::クエスト2:

			//Back_Button();


			if ((_mousetrg != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {

				scene = MENU_NUM::メニュー;
				q = Q::Q初期値;
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
				//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
				//星１冒険者１
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
				//星１冒険者２
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
				//星2冒険者３
				if (Click3 == false) {
					Click3 = true;
					Add_Quest_Adventurer_Status(2);
				}

				else if (Click3 == true) {
					Click3 = false;
					Delete_Quest_Adventurer_Status(2);
				}
			}

			GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



			//int Mause = _gmause;
			//_gmause = GetMouseInput();
			//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

			if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
				((mouse_x < max_x) &&
					(mouse_x > min_x)) &&
				(mouse_y < max_y) &&
				(mouse_y > min_y)) {
				//math.Judgement();
				q = Q::Qクエスト判定;
				//	q = Q::Qメニュー;
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

			case MENU_NUM::クエスト3:

				//Back_Button();


				if ((_mousetrg != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {

					scene = MENU_NUM::メニュー;
					q = Q::Q初期値;
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
					//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
					//星１冒険者１
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
					//星１冒険者２
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
					//星2冒険者３
					if (Click3 == false) {
						Click3 = true;
						Add_Quest_Adventurer_Status(2);
					}

					else if (Click3 == true) {
						Click3 = false;
						Delete_Quest_Adventurer_Status(2);
					}
				}

				GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



				//int Mause = _gmause;
				//_gmause = GetMouseInput();
				//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

				if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
					((mouse_x < max_x) &&
						(mouse_x > min_x)) &&
					(mouse_y < max_y) &&
					(mouse_y > min_y)) {
					//math.Judgement();
					q = Q::Qクエスト判定;
					//	q = Q::Qメニュー;
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
				case MENU_NUM::クエスト4:

					//Back_Button();


					if ((_mousetrg != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {

						scene = MENU_NUM::メニュー;
						q = Q::Q初期値;
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
						//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
						//星１冒険者１
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
						//星１冒険者２
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
						//星2冒険者３
						if (Click3 == false) {
							Click3 = true;
							Add_Quest_Adventurer_Status(2);
						}

						else if (Click3 == true) {
							Click3 = false;
							Delete_Quest_Adventurer_Status(2);
						}
					}

					GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



					//int Mause = _gmause;
					//_gmause = GetMouseInput();
					//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

					if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
						((mouse_x < max_x) &&
							(mouse_x > min_x)) &&
						(mouse_y < max_y) &&
						(mouse_y > min_y)) {
						//math.Judgement();
						q = Q::Qクエスト判定;
						//	q = Q::Qメニュー;
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
					case MENU_NUM::クエスト5:

						//Back_Button();


						if ((_mousetrg != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {

							scene = MENU_NUM::メニュー;
							q = Q::Q初期値;
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
							//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
							//星１冒険者１
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
							//星１冒険者２
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
							//星2冒険者３
							if (Click3 == false) {
								Click3 = true;
								Add_Quest_Adventurer_Status(2);
							}

							else if (Click3 == true) {
								Click3 = false;
								Delete_Quest_Adventurer_Status(2);
							}
						}

						GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



						//int Mause = _gmause;
						//_gmause = GetMouseInput();
						//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

						if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
							((mouse_x < max_x) &&
								(mouse_x > min_x)) &&
							(mouse_y < max_y) &&
							(mouse_y > min_y)) {
							//math.Judgement();
							q = Q::Qクエスト判定;
							//	q = Q::Qメニュー;
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
						case MENU_NUM::クエスト6:

							//Back_Button();


							if ((_mousetrg != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {

								scene = MENU_NUM::メニュー;
								q = Q::Q初期値;
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
								//クリックされたらステータスに数値をプラス、もう一度押されたらマイナスする
								//星１冒険者１
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
								//星１冒険者２
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
								//星2冒険者３
								if (Click3 == false) {
									Click3 = true;
									Add_Quest_Adventurer_Status(2);
								}

								else if (Click3 == true) {
									Click3 = false;
									Delete_Quest_Adventurer_Status(2);
								}
							}

							GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);



							//int Mause = _gmause;
							//_gmause = GetMouseInput();
							//_gTrg = (_gmause ^ Mause) & _gmause;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）

							if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
								((mouse_x < max_x) &&
									(mouse_x > min_x)) &&
								(mouse_y < max_y) &&
								(mouse_y > min_y)) {
								//math.Judgement();
								q = Q::Qクエスト判定;
								//	q = Q::Qメニュー;
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



//更新
void Quest::Quest_Update() {

}



//描画
void Quest::Quest_Render() {
	//_game.GetRandom();
	//_game.GetRandom1();
	//_game.GetRandom2();
	//_game.GetRandom3();
	//_game.GetRandom4();
	//_game.GetRandom5();


	switch (scene)
	{
	case MENU_NUM::メニュー:
		DrawGraph(135, 185, menu, TRUE);
		graph.Quest_Slot_Level1(random);
		graph.Quest_Slot_Level1_2(random1);
		graph.Quest_Slot_Level1_3(random2);
		graph.Quest_Slot_Level1_4(random3);
		graph.Quest_Slot_Level1_5(random4);
		graph.Quest_Slot_Level1_6(random5);
		DrawGraph(1750, 900, Back, TRUE);
		break;

	case MENU_NUM::クエスト1:
		graph.GraphQuest_Level1(random);  //クエストの中身
		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);
		
		DrawString(100, 100, "クエスト1", TRUE);
		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);
		//DrawFormatString(1000, 980, GetColor(0, 0, 0), "得意不得意%d", questData1.ClearTotalKnow);

		break;

	case MENU_NUM::クエスト2:
		graph.GraphQuest_Level1(random1);
		

		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト2", TRUE);

		break;

	case MENU_NUM::クエスト3:
		graph.GraphQuest_Level1(random2);

		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/

		DrawString(100, 100, "クエスト3", TRUE);
		break;

	case MENU_NUM::クエスト4:
		graph.GraphQuest_Level1(random3);

		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト4", TRUE);

		break;

	case MENU_NUM::クエスト5:
		graph.GraphQuest_Level1(random4);

		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト5", TRUE);

		break;

	case MENU_NUM::クエスト6:
		graph.GraphQuest_Level1(random5);

		DrawGraph(763, 208, Q1_1, TRUE);    //冒険者1
		DrawGraph(900, 208, Q2_1, TRUE);   //冒険者2
		DrawGraph(763, 318, Q5_1, TRUE);   //冒険者3
		DrawGraph(900, 318, Q3_1, TRUE);   //冒険者4
		DrawGraph(763, 428, Q6_1, TRUE);   //冒険者5
		DrawGraph(900, 428, Q7_1, TRUE);   //冒険者6
		DrawGraph(763, 538, Q4_1, TRUE);   //冒険者7
		DrawGraph(1500, 700, QuestStart, TRUE);//クエスト出撃
		DrawGraph(1750, 900, Back, TRUE);

		DrawFormatString(1200, 675, GetColor(0, 0, 0), "攻撃力%d", questData1.ClearTotalAttack);
		DrawFormatString(1200, 730, GetColor(0, 0, 0), "防御力%d", questData1.ClearTotalDefence);
		DrawFormatString(1200, 785, GetColor(0, 0, 0), "スキル%d", questData1.ClearTotalSkill);
		DrawFormatString(1200, 840, GetColor(0, 0, 0), "賢さ%d", questData1.ClearTotalKnow);

		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト6", TRUE);

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
	if (q != Q::Q初期値)
	{



		int FontHandle = CreateFontToHandle(NULL, 40, 3);
		DrawFormatStringToHandle(780, 680, GetColor(0, 0, 0), FontHandle, "メンバーの総合値");
		DrawFormatStringToHandle(880, 720, GetColor(0, 0, 0), FontHandle, "攻%d", TotalAttack);
		DrawFormatStringToHandle(880, 770, GetColor(0, 0, 0), FontHandle, "守%d", TotalDefence);
		DrawFormatStringToHandle(880, 820, GetColor(0, 0, 0), FontHandle, "技%d", TotalSkill);
		DrawFormatStringToHandle(880, 870, GetColor(0, 0, 0), FontHandle, "知%d", TotalKnow);
		//DrawFormatStringToHandle(1000, 920, GetColor(0, 0, 0), FontHandle, "得意%d", AdventurerGood);
		//DrawFormatString(1000, 680, GetColor(0, 0, 0), "成功率%d", math.SuccessRate);
		DeleteFontToHandle(FontHandle);

		/*if (TotalAttack >= questData1.ClearTotalAttack)
			math.SuccessRate += 25;*/
	}

	switch (q)
	{
	case Q::Qメニュー:
		DrawGraph(1750, 20, Back, TRUE);
		Click1 = false;  //ココからbreakまでの処理は再度クエストを選択した際に冒険者がいない状態にするもの
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

	case Q::Qクエスト判定: 
		//DrawGraph(100, 100, clear, TRUE);
		//math._questresult = rand() % 2;
		//questData1.SetQuestParam( rand() % 12);
		//turnnumber.Start = TRUE;
		End = TRUE;
		//WaitKey();
		scene = MENU_NUM::メニュー;
		Quest_Result();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		q = Q::Q初期値;
		break;
	   
	}
}
