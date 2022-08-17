#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"Math.h"
#include "Adventurer_Status.h"
#include "TurnNumber.h"



//コンストラクタ
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
	//,math(*this)
	//,_math(*this,_game,_scenemgr)
{
	_cg = LoadGraph("images/Adventurer.jpg");
	_cg1 = LoadGraph("images/クエスト画面2.png");
	_BIGrHandle = LoadGraph("images/Base-Illust.png");


	Q1GrHandle = LoadGraph("images/to-batu_s1.png");  //クエスト1スロット
	Q2GrHandle = LoadGraph("images/bo-ei_s1.png");  //クエスト2スロット
	Q3GrHandle = LoadGraph("images/saishu_s1.png");  //クエスト3スロット
	Q4GrHandle = LoadGraph("images/others_s1.png");  //クエスト4スロット
	Q5GrHandle = LoadGraph("images/to-batu_s1.png");  //クエスト5スロット
	Q6GrHandle = LoadGraph("images/bo-ei_s1.png");  //クエスト6スロット


	//QGraHandle[0] = LoadGraph("images/to-batu_s1.png");  //クエスト1スロット
	//QGraHandle[1] = LoadGraph("images/bo-ei_s1.png");  //クエスト2スロット
	//QGraHandle[2] =	LoadGraph("images/saishu_s1.png");  //クエスト3スロット
	//QGraHandle[3] =	LoadGraph("images/others_s1.png");  //クエスト4スロット
	//QGraHandle[4] =	LoadGraph("images/to-batu_s1.png");  //クエスト5スロット
	//QGraHandle[5] =	LoadGraph("images/bo-ei_s1.png");  //クエスト6スロット
	


	Q1 = LoadGraph("images/ch_001.mini.2.png");  //冒険者1
	Q1_1 = LoadGraph("images/ch_001.mini1.png");
	Q1Start = LoadGraph("images/出撃ボタン.png");  //出撃ボタン
	Q2 = LoadGraph("images/ch_002.mini2.png");  //冒険者2
	Q2_1 = LoadGraph("images/ch_002.mini1.png");
	Q3 = LoadGraph("images/ch_06.mini2.png");  //冒険者3
	Q3_1 = LoadGraph("images/ch_06.mini1.png");
	menu = LoadGraph("images/Base-illust.png");  //クエスト1中身
	clear = LoadGraph("images/success.png");
	failure = LoadGraph("images/failure.png");
	Back = LoadGraph("images/back.png");
	End = FALSE;


	q = Q::Q初期値;
	TotalAttack = 0;
	TotalDefence = 0;
	TotalSkill = 0;
	TotalKnow = 0;


	Click1 = false;
	Click2 = false;
	Click3 = false;

	//random = 0;


	questData1.SetQuestParam(5);
	questData2.SetQuestParam(0);
}

//デストラクタ
Quest::~Quest() {

}

void QuestData::SetQuestParam(int questIndex) 
{
	ClearTotalAttack = QuestClearAttacks[questIndex];  //クエストの達成に必要なパーティーのAttackの総合値
	ClearTotalDefence = QuestClearDefence[questIndex];  //クエストの達成に必要なパーティーのDefenceの総合値
	ClearTotalSkill = QuestClearSkill[questIndex];  //クエストの達成に必要なパーティーのSkillの総合値
	ClearTotalKnow = QuestClearKnow[questIndex];  //クエストの達成に必要なパーティーのKnowの総合値
}

void Quest::Quest_Result() {  //クエストの結果を表示する
	
	
	if (End == TRUE) {
		math.Judgement(questData1.ClearTotalAttack, questData1.ClearTotalDefence, questData1.ClearTotalSkill, questData1.ClearTotalKnow, TotalAttack, TotalDefence, TotalSkill, TotalKnow);
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

//選択項目の領域指定
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::メニュー:

		max_x = 1900;
		min_x = 1750;
		max_y = 170;
		min_y = 20;

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
	case MENU_NUM::クエスト開始:
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

///クエストのランダム出現
void Quest::Random_Quest() {
	random = GetRand(5) + 1;
	 scene = static_cast<MENU_NUM>(random);

	//GetRand(Quest::MENU_NUM);


}



///メニューに戻る関数
void Quest::Menu_Back_Button() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((mouse_x < max_x) &&
			(mouse_x > min_x)) &&
		(mouse_y < max_y) &&
		(mouse_y > min_y)) {

		//scene = MENU_NUM::メニュー;
		q = Q::Q初期値;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		
	}
}

///一つ前に戻る
void Quest::Back_Button() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((mouse_x < max_x) &&
			(mouse_x > min_x)) &&
		(mouse_y < max_y) &&
		(mouse_y > min_y)) {

		scene = MENU_NUM::メニュー;
		q = Q::Q初期値;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		WaitKey();
	}
}

//入力
void Quest::Quest_Input() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	//auto trg = key_trg.second;
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);
	//GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

	//メニューボタン
	/*if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((mouse_x < max_x) &&
			(mouse_x > min_x)) &&
		(mouse_y < max_y) &&
		(mouse_y > min_y)) {

		scene = MENU_NUM::メニュー;
		q = Q::Q初期値;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		WaitKey();
	}*/

	switch (scene)
	{

	case Quest::MENU_NUM::メニュー:
		//Random_Quest();
		//Menu_Back_Button();
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
		//Random_Quest();
		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			//DrawGraph(0, 0, _cg1, TRUE);
		    //scene;
			Random_Quest();
			//q = Q::Qメニュー;
			//scene = MENU_NUM::クエスト1;



		}

		//クエスト2
		GetMenuPosition(MENU_NUM::クエスト2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			Random_Quest();
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
			Random_Quest();
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		//クエスト4
		GetMenuPosition(MENU_NUM::クエスト4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			Random_Quest();
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		//クエスト5
		GetMenuPosition(MENU_NUM::クエスト5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			Random_Quest();
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		//クエスト6
		GetMenuPosition(MENU_NUM::クエスト6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			Random_Quest();
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


		GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

				TotalAttack += AdventurerStatus.Attack[0];
				TotalDefence += AdventurerStatus.Defence[0];
				TotalSkill += AdventurerStatus.Skill[0];
				TotalKnow += AdventurerStatus.Know[0];
				//TotalCost += AdventurerCost[0];
			}

			else if (Click1 == true) {
				Click1 = false;
				TotalAttack -= AdventurerStatus.Attack[0];
				TotalDefence -= AdventurerStatus.Defence[0];
				TotalSkill -= AdventurerStatus.Skill[0];
				TotalKnow -= AdventurerStatus.Know[0];
				//TotalCost -= AdventurerCost[0];
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
			//星１冒険者２
			if (Click2 == false) {
				Click2 = true;
				TotalAttack += AdventurerStatus.Attack[1];
				TotalDefence += AdventurerStatus.Defence[1];
				TotalSkill += AdventurerStatus.Skill[1];
				TotalKnow += AdventurerStatus.Know[1];
			}

			else if (Click2 == true) {
				Click2 = false;
				TotalAttack -= AdventurerStatus.Attack[1];
				TotalDefence -= AdventurerStatus.Defence[1];
				TotalSkill -= AdventurerStatus.Skill[1];
				TotalKnow -= AdventurerStatus.Know[1];
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
			//星2冒険者３
			if (Click3 == false) {
				Click3 = true;
				TotalAttack += AdventurerStatus.Attack[2];
				TotalDefence += AdventurerStatus.Defence[2];
				TotalSkill += AdventurerStatus.Skill[2];
				TotalKnow += AdventurerStatus.Know[2];
			}

			else if (Click3 == true) {
				Click3 = false;
				TotalAttack -= AdventurerStatus.Attack[2];
				TotalDefence -= AdventurerStatus.Defence[2];
				TotalSkill -= AdventurerStatus.Skill[2];
				TotalKnow -= AdventurerStatus.Know[2];
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


			GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

					TotalAttack += AdventurerStatus.Attack[0];
					TotalDefence += AdventurerStatus.Defence[0];
					TotalSkill += AdventurerStatus.Skill[0];
					TotalKnow += AdventurerStatus.Know[0];
					//TotalCost += AdventurerCost[0];
				}

				else if (Click1 == true) {
					Click1 = false;
					TotalAttack -= AdventurerStatus.Attack[0];
					TotalDefence -= AdventurerStatus.Defence[0];
					TotalSkill -= AdventurerStatus.Skill[0];
					TotalKnow -= AdventurerStatus.Know[0];
					//TotalCost -= AdventurerCost[0];
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
				//星１冒険者２
				if (Click2 == false) {
					Click2 = true;
					TotalAttack += AdventurerStatus.Attack[1];
					TotalDefence += AdventurerStatus.Defence[1];
					TotalSkill += AdventurerStatus.Skill[1];
					TotalKnow += AdventurerStatus.Know[1];
				}

				else if (Click2 == true) {
					Click2 = false;
					TotalAttack -= AdventurerStatus.Attack[1];
					TotalDefence -= AdventurerStatus.Defence[1];
					TotalSkill -= AdventurerStatus.Skill[1];
					TotalKnow -= AdventurerStatus.Know[1];
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
				//星2冒険者３
				if (Click3 == false) {
					Click3 = true;
					TotalAttack += AdventurerStatus.Attack[2];
					TotalDefence += AdventurerStatus.Defence[2];
					TotalSkill += AdventurerStatus.Skill[2];
					TotalKnow += AdventurerStatus.Know[2];
				}

				else if (Click3 == true) {
					Click3 = false;
					TotalAttack -= AdventurerStatus.Attack[2];
					TotalDefence -= AdventurerStatus.Defence[2];
					TotalSkill -= AdventurerStatus.Skill[2];
					TotalKnow -= AdventurerStatus.Know[2];
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


				GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

						TotalAttack += AdventurerStatus.Attack[0];
						TotalDefence += AdventurerStatus.Defence[0];
						TotalSkill += AdventurerStatus.Skill[0];
						TotalKnow += AdventurerStatus.Know[0];
						//TotalCost += AdventurerCost[0];
					}

					else if (Click1 == true) {
						Click1 = false;
						TotalAttack -= AdventurerStatus.Attack[0];
						TotalDefence -= AdventurerStatus.Defence[0];
						TotalSkill -= AdventurerStatus.Skill[0];
						TotalKnow -= AdventurerStatus.Know[0];
						//TotalCost -= AdventurerCost[0];
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
					//星１冒険者２
					if (Click2 == false) {
						Click2 = true;
						TotalAttack += AdventurerStatus.Attack[1];
						TotalDefence += AdventurerStatus.Defence[1];
						TotalSkill += AdventurerStatus.Skill[1];
						TotalKnow += AdventurerStatus.Know[1];
					}

					else if (Click2 == true) {
						Click2 = false;
						TotalAttack -= AdventurerStatus.Attack[1];
						TotalDefence -= AdventurerStatus.Defence[1];
						TotalSkill -= AdventurerStatus.Skill[1];
						TotalKnow -= AdventurerStatus.Know[1];
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
					//星2冒険者３
					if (Click3 == false) {
						Click3 = true;
						TotalAttack += AdventurerStatus.Attack[2];
						TotalDefence += AdventurerStatus.Defence[2];
						TotalSkill += AdventurerStatus.Skill[2];
						TotalKnow += AdventurerStatus.Know[2];
					}

					else if (Click3 == true) {
						Click3 = false;
						TotalAttack -= AdventurerStatus.Attack[2];
						TotalDefence -= AdventurerStatus.Defence[2];
						TotalSkill -= AdventurerStatus.Skill[2];
						TotalKnow -= AdventurerStatus.Know[2];
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


					GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

							TotalAttack += AdventurerStatus.Attack[0];
							TotalDefence += AdventurerStatus.Defence[0];
							TotalSkill += AdventurerStatus.Skill[0];
							TotalKnow += AdventurerStatus.Know[0];
							//TotalCost += AdventurerCost[0];
						}

						else if (Click1 == true) {
							Click1 = false;
							TotalAttack -= AdventurerStatus.Attack[0];
							TotalDefence -= AdventurerStatus.Defence[0];
							TotalSkill -= AdventurerStatus.Skill[0];
							TotalKnow -= AdventurerStatus.Know[0];
							//TotalCost -= AdventurerCost[0];
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
						//星１冒険者２
						if (Click2 == false) {
							Click2 = true;
							TotalAttack += AdventurerStatus.Attack[1];
							TotalDefence += AdventurerStatus.Defence[1];
							TotalSkill += AdventurerStatus.Skill[1];
							TotalKnow += AdventurerStatus.Know[1];
						}

						else if (Click2 == true) {
							Click2 = false;
							TotalAttack -= AdventurerStatus.Attack[1];
							TotalDefence -= AdventurerStatus.Defence[1];
							TotalSkill -= AdventurerStatus.Skill[1];
							TotalKnow -= AdventurerStatus.Know[1];
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
						//星2冒険者３
						if (Click3 == false) {
							Click3 = true;
							TotalAttack += AdventurerStatus.Attack[2];
							TotalDefence += AdventurerStatus.Defence[2];
							TotalSkill += AdventurerStatus.Skill[2];
							TotalKnow += AdventurerStatus.Know[2];
						}

						else if (Click3 == true) {
							Click3 = false;
							TotalAttack -= AdventurerStatus.Attack[2];
							TotalDefence -= AdventurerStatus.Defence[2];
							TotalSkill -= AdventurerStatus.Skill[2];
							TotalKnow -= AdventurerStatus.Know[2];
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


						GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

								TotalAttack += AdventurerStatus.Attack[0];
								TotalDefence += AdventurerStatus.Defence[0];
								TotalSkill += AdventurerStatus.Skill[0];
								TotalKnow += AdventurerStatus.Know[0];
								//TotalCost += AdventurerCost[0];
							}

							else if (Click1 == true) {
								Click1 = false;
								TotalAttack -= AdventurerStatus.Attack[0];
								TotalDefence -= AdventurerStatus.Defence[0];
								TotalSkill -= AdventurerStatus.Skill[0];
								TotalKnow -= AdventurerStatus.Know[0];
								//TotalCost -= AdventurerCost[0];
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
							//星１冒険者２
							if (Click2 == false) {
								Click2 = true;
								TotalAttack += AdventurerStatus.Attack[1];
								TotalDefence += AdventurerStatus.Defence[1];
								TotalSkill += AdventurerStatus.Skill[1];
								TotalKnow += AdventurerStatus.Know[1];
							}

							else if (Click2 == true) {
								Click2 = false;
								TotalAttack -= AdventurerStatus.Attack[1];
								TotalDefence -= AdventurerStatus.Defence[1];
								TotalSkill -= AdventurerStatus.Skill[1];
								TotalKnow -= AdventurerStatus.Know[1];
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
							//星2冒険者３
							if (Click3 == false) {
								Click3 = true;
								TotalAttack += AdventurerStatus.Attack[2];
								TotalDefence += AdventurerStatus.Defence[2];
								TotalSkill += AdventurerStatus.Skill[2];
								TotalKnow += AdventurerStatus.Know[2];
							}

							else if (Click3 == true) {
								Click3 = false;
								TotalAttack -= AdventurerStatus.Attack[2];
								TotalDefence -= AdventurerStatus.Defence[2];
								TotalSkill -= AdventurerStatus.Skill[2];
								TotalKnow -= AdventurerStatus.Know[2];
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


							GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

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

									TotalAttack += AdventurerStatus.Attack[0];
									TotalDefence += AdventurerStatus.Defence[0];
									TotalSkill += AdventurerStatus.Skill[0];
									TotalKnow += AdventurerStatus.Know[0];
									//TotalCost += AdventurerCost[0];
								}

								else if (Click1 == true) {
									Click1 = false;
									TotalAttack -= AdventurerStatus.Attack[0];
									TotalDefence -= AdventurerStatus.Defence[0];
									TotalSkill -= AdventurerStatus.Skill[0];
									TotalKnow -= AdventurerStatus.Know[0];
									//TotalCost -= AdventurerCost[0];
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
								//星１冒険者２
								if (Click2 == false) {
									Click2 = true;
									TotalAttack += AdventurerStatus.Attack[1];
									TotalDefence += AdventurerStatus.Defence[1];
									TotalSkill += AdventurerStatus.Skill[1];
									TotalKnow += AdventurerStatus.Know[1];
								}

								else if (Click2 == true) {
									Click2 = false;
									TotalAttack -= AdventurerStatus.Attack[1];
									TotalDefence -= AdventurerStatus.Defence[1];
									TotalSkill -= AdventurerStatus.Skill[1];
									TotalKnow -= AdventurerStatus.Know[1];
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
								//星2冒険者３
								if (Click3 == false) {
									Click3 = true;
									TotalAttack += AdventurerStatus.Attack[2];
									TotalDefence += AdventurerStatus.Defence[2];
									TotalSkill += AdventurerStatus.Skill[2];
									TotalKnow += AdventurerStatus.Know[2];
								}

								else if (Click3 == true) {
									Click3 = false;
									TotalAttack -= AdventurerStatus.Attack[2];
									TotalDefence -= AdventurerStatus.Defence[2];
									TotalSkill -= AdventurerStatus.Skill[2];
									TotalKnow -= AdventurerStatus.Know[2];
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
	//int max_x, min_x, max_y, min_y;
	//GetMenuPosition(MENU_NUM::クエスト1, max_x, min_x, max_y, min_y);
	//int no = 0;
		//int i = GetRand(6);
	switch (scene)
	{
	case MENU_NUM::メニュー:
	  
		//DrawGraph(0, 0, _bg, TRUE);//常に背景が表示されるようにしたい

		DrawGraph(135, 185, menu, TRUE);
		//DrawGraph(400, 200, _cg, TRUE);
		//DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);  //戻るボタン
		DrawGraph(396, 270, Q1GrHandle, TRUE);  //クエストスロット1   画像サイズ　幅260　高さ310　以下同じ
		DrawGraph(830, 270, Q2GrHandle, TRUE);  //クエストスロット2
		DrawGraph(1264,270, Q3GrHandle, TRUE);	//クエストスロット3
		DrawGraph(396, 640, Q4GrHandle, TRUE);	//クエストスロット4
		DrawGraph(830, 640, Q5GrHandle, TRUE);	//クエストスロット5
		DrawGraph(1264,640, Q6GrHandle, TRUE);	//クエストスロット6

		//DrawGraph(396, 270, QGraHandle[i], TRUE);  //クエストスロット1   画像サイズ　幅260　高さ310　以下同じ
		//DrawGraph(830, 270, QGraHandle[i], TRUE);  //クエストスロット2
		//DrawGraph(1264,270, QGraHandle[i], TRUE);	//クエストスロット3
		//DrawGraph(396, 640, QGraHandle[i], TRUE);	//クエストスロット4
		//DrawGraph(830, 640, QGraHandle[i], TRUE);	//クエストスロット5
		//DrawGraph(1264,640, QGraHandle[i], TRUE);	//クエストスロット6


		DrawGraph(1750, 20, Back, TRUE);
		break;

	case MENU_NUM::クエスト1:
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		//DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		//DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		//DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		//DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE); //クエスト出撃
		DrawString(100, 100, "クエスト1", TRUE);
		break;

	case MENU_NUM::クエスト2:
		//DrawBox(1000, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト2", TRUE);

		break;

	case MENU_NUM::クエスト3:
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/

		DrawString(100, 100, "クエスト3", TRUE);
		break;

	case MENU_NUM::クエスト4:
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト4", TRUE);

		break;

	case MENU_NUM::クエスト5:
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト5", TRUE);

		break;

	case MENU_NUM::クエスト6:
		DrawGraph(0, 0, _cg1, TRUE); //背景
		DrawGraph(760, 210, Q1_1, TRUE);    //冒険者1
		DrawGraph(760, 298, Q2_1, TRUE);   //冒険者2
		DrawGraph(760, 386, Q3_1, TRUE);   //冒険者3
		DrawGraph(1500, 700, Q1Start, TRUE);//クエスト出撃
		/*DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);*/
		DrawString(100, 100, "クエスト6", TRUE);

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
	if (q != Q::Q初期値)
	{
		int FontHandle = CreateFontToHandle(NULL, 40, 3);
		DrawFormatStringToHandle(880, 680, GetColor(0, 0, 0), FontHandle, "攻%d", TotalAttack);
		DrawFormatStringToHandle(880, 760, GetColor(0, 0, 0), FontHandle, "守%d", TotalDefence);
		DrawFormatStringToHandle(880, 840, GetColor(0, 0, 0), FontHandle, "技%d", TotalSkill);
		DrawFormatStringToHandle(880, 920, GetColor(0, 0, 0), FontHandle, "知%d", TotalKnow);
		DeleteFontToHandle(FontHandle);
	}

	switch (q)
	{
	case Q::Qメニュー:
		DrawGraph(1750, 20, Back, TRUE);
		Click1 = false;  //ココからbreakまでの処理は再度クエストを選択した際に冒険者がいない状態にするもの
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
	case Q::Qクエスト判定: 
		//DrawGraph(100, 100, clear, TRUE);
		//math._questresult = rand() % 2;
		//questData1.SetQuestParam( rand() % 12);
		//turnnumber.Start = TRUE;
		End = TRUE;
		//WaitKey();
		scene = MENU_NUM::メニュー;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		q = Q::Q初期値;
		break;
	   
	}
}
