#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
//#include"Math.h"



//コンストラクタ
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game)
  //,math(*this)
	//,_math(*this,_game,_scenemgr)
 {
	//_cg = LoadGraph("images/Adventurer.jpg");
	_cg1 = LoadGraph("images/クエスト画面2.png");
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	Q1GrHandle = LoadGraph("images/Quest-1.png");  //クエスト1スロット
	Q2GrHandle = LoadGraph("images/Quest-2.png");  //クエスト2スロット
	Q3GrHandle = LoadGraph("images/Quest-3.png");  //クエスト3スロット
	Q4GrHandle = LoadGraph("images/Quest-4.png");  //クエスト4スロット
	Q5GrHandle = LoadGraph("images/Quest-5.png");  //クエスト5スロット
	Q6GrHandle = LoadGraph("images/Quest-6.png");  //クエスト6スロット
	Q1 = LoadGraph("images/冒険者.jpg");  //クエスト1中身
	Q2 = LoadGraph("images/冒険者２.png");  //クエスト1中身
	Q3 = LoadGraph("images/冒険者.jpg");  //クエスト1中身
	menu = LoadGraph("images/クエスト画面1.png");  //クエスト1中身
	clear = LoadGraph("images/Clear.png");
	failure = LoadGraph("images/Failure.png");
}

//デストラクタ
Quest::~Quest() {

}

//選択項目の領域指定
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::メニュー:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

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
	case MENU_NUM::クエスト開始:
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


//入力
void Quest::Quest_Input() {
	int max_x, min_x, max_y, min_y, i;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	//auto trg = key_trg.second;
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);
	//GetMenuPosition(MENU_NUM::QInside, max_x, min_x, max_y, min_y);

	//メニューボタン
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		( (mouse_x < max_x) &&
			(mouse_x > min_x)) &&
		  (mouse_y < max_y) &&
		  (mouse_y > min_y)) {

		scene = MENU_NUM::メニュー;
		q = Q::Qメニュー;
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}
	
	switch (scene)
	{

	case Quest::MENU_NUM::メニュー:

		//クエスト1
		GetMenuPosition(MENU_NUM::クエスト1, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			DrawGraph(0, 0, _cg1, TRUE);
			scene = MENU_NUM::クエスト1;




		}

		//クエスト2
		GetMenuPosition(MENU_NUM::クエスト2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			scene = MENU_NUM::クエスト2;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		}

		//クエスト3
		GetMenuPosition(MENU_NUM::クエスト3, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		//クエスト4
		GetMenuPosition(MENU_NUM::クエスト4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		//クエスト5
		GetMenuPosition(MENU_NUM::クエスト5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		//クエスト6
		GetMenuPosition(MENU_NUM::クエスト6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {

			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
		}
		break;

		//クエストの中身
	case MENU_NUM::クエスト1:
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

		GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((mouse_x < max_x) &&
				(mouse_x > min_x)) &&
			(mouse_y < max_y) &&
			(mouse_y > min_y)) {
			q = Q::Qクエスト判定;
			if (math.Judgement()) {
			//	GetMoney(i);
		
			}
			else {

			}
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
	int no = 0;

	switch (scene)
	{
	case MENU_NUM::メニュー:
		DrawGraph(0, 0, menu, TRUE);
		//DrawGraph(400, 200, _cg, TRUE);
		DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);  //戻るボタン
		DrawGraph(396, 270, Q1GrHandle, TRUE);  //画像サイズ　幅260　高さ310　以下同じ
		DrawGraph(830, 270, Q2GrHandle, TRUE);
		DrawGraph(1264, 270, Q3GrHandle, TRUE);
		DrawGraph(396, 640, Q4GrHandle, TRUE);
		DrawGraph(830, 640, Q5GrHandle, TRUE);
		DrawGraph(1264, 640, Q6GrHandle, TRUE);
		break;

	case MENU_NUM::クエスト1:
		//DrawGraph(0, 0, _cg1, TRUE);
		DrawBox(760, 210, 1050, 270, GetColor(255, 0, 0), TRUE);
		DrawBox(760, 270, 1050, 330, GetColor(0, 255, 0), TRUE);
		DrawBox(760, 330, 1050, 390, GetColor(0, 0, 255), TRUE);
		DrawBox(1500, 900, 1700, 1000, GetColor(0, 0, 255), TRUE);
		break;

	case MENU_NUM::クエスト2:
		DrawBox(1000, 45, 1850, 90, GetColor(255, 0, 0), TRUE);

		break;

	case MENU_NUM::クエスト3:
		break;

	case MENU_NUM::クエスト4:
		break;

	case MENU_NUM::クエスト5:
		break;

	case MENU_NUM::クエスト6:
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
	case Q::Qクエスト判定:

		int max_x, min_x, max_y, min_y,no;
		int mouse_x = _game.GetMouseX();
		int mouse_y = _game.GetMouseY();
		GetMenuPosition(MENU_NUM::クエスト開始, max_x, min_x, max_y, min_y);

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
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "ランダム数%d\n", no);
		
		break;

	}
}
