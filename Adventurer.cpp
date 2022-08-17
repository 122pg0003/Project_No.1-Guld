#include"Adventurer.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"





Adventurer::Adventurer(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_cg = LoadGraph("images/Scene_Game.png");
	/*  x1 = 1000 ;
		y1 = 600 ;
		x2 = 100;
		y2 = 100 ;*/
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	Q1GrHandle = LoadGraph("images/Quest-1.png");  //クエスト1スロット
	Q2GrHandle = LoadGraph("images/Quest-2.png");  //クエスト2スロット
	Q3GrHandle = LoadGraph("images/Quest-3.png");  //クエスト3スロット
	Q4GrHandle = LoadGraph("images/Quest-4.png");  //クエスト4スロット
	Q5GrHandle = LoadGraph("images/Quest-5.png");  //クエスト5スロット
	Q6GrHandle = LoadGraph("images/Quest-6.png");  //クエスト6スロット
}



Adventurer::~Adventurer() {

}
/*
int hoge[][] = { {170,40,290,260}, {200,50,300,210} };

int[] Adventurer::GetMenuPosition(int menuIndex) {
	return hoge[menuIndex];
}*/

//選択項目の領域指定
void Adventurer::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::メニュー:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;

	case MENU_NUM::冒険者1:
	
		max_x = 656;
		min_x = 396;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::冒険者2:

		max_x = 1090;
		min_x = 830;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::冒険者3:

		max_x = 1524;
		min_x = 1264;
		max_y = 580;
		min_y = 270;

		break;
	case MENU_NUM::冒険者4:

		max_x = 656;
		min_x = 396;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::冒険者5:

		max_x = 1090;
		min_x = 830;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::冒険者6:

		max_x = 1524;
		min_x = 1264;
		max_y = 950;
		min_y = 640;

		break;

	case MENU_NUM::冒険者7:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	}
	
}

void Adventurer::Adventurer_Input() {
	int max_x, min_x, max_y, min_y;

	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		
				_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);

			}

	GetMenuPosition(MENU_NUM::冒険者1, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
		(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
	//DrawBox(1000, 900, 900, 100, GetColor(255, 0, 255), TRUE);
		MENU_NUM scene = MENU_NUM::冒険者1;
		//DrawString(800, 800, "aaaaaaaaaaaa", GetColor(255, 255, 0), FALSE);
				//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::冒険者2, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::冒険者2;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::冒険者3, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::冒険者3;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::冒険者4, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::冒険者4;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::冒険者5, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::冒険者5;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::冒険者6, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::冒険者6;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::冒険者7, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
}
void Adventurer::Adventurer_Update() {
		//ClearDrawScreen();
		DrawGraph(400, 200, _cg, TRUE);
		//DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
		//if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			switch (scene)
			{
			case Adventurer::MENU_NUM::冒険者1:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::冒険者2:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::冒険者3:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::冒険者4:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::冒険者5:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::冒険者6:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			}
		//}

}

void Adventurer::Adventurer_Render() {
	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
	DrawGraph(135, 185, _BIGrHandle, TRUE);
	//DrawGraph(400, 200, _cg, TRUE);
	DrawGraph(396, 270, Q1GrHandle, TRUE);  //画像サイズ　幅260　高さ310　以下同じ
	DrawGraph(830, 270, Q2GrHandle, TRUE);
	DrawGraph(1264, 270, Q3GrHandle, TRUE);
	DrawGraph(396, 640, Q4GrHandle, TRUE);
	DrawGraph(830, 640, Q5GrHandle, TRUE);
	DrawGraph(1264, 640, Q6GrHandle, TRUE);
}

