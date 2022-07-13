#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

//コンストラクタ
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_cg = LoadGraph("images/Adventurer.jpg");
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	Q1GrHandle = LoadGraph("images/Quest-1.png");  //クエスト1スロット
	Q2GrHandle = LoadGraph("images/Quest-2.png");  //クエスト2スロット
	Q3GrHandle = LoadGraph("images/Quest-3.png");  //クエスト3スロット
	Q4GrHandle = LoadGraph("images/Quest-4.png");  //クエスト4スロット
	Q5GrHandle = LoadGraph("images/Quest-5.png");  //クエスト5スロット
	Q6GrHandle = LoadGraph("images/Quest-6.png");  //クエスト6スロット
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
	}
}


//入力
void Quest::Quest_Input() {
	int max_x, min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);

	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}

	GetMenuPosition(MENU_NUM::クエスト1, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		scene = MENU_NUM::クエスト1;
		//return;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
	}

	GetMenuPosition(MENU_NUM::クエスト2, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	}

	GetMenuPosition(MENU_NUM::クエスト3, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
	}

	GetMenuPosition(MENU_NUM::クエスト4, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
	}

	GetMenuPosition(MENU_NUM::クエスト5, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	}

	GetMenuPosition(MENU_NUM::クエスト6, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
	}
}


//更新
void Quest::Quest_Update() {

}

//描画
void Quest::Quest_Render() {
	DrawGraph(400, 200, _cg, TRUE);
	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);  //戻るボタン
	DrawGraph(396, 270, Q1GrHandle, TRUE);  //画像サイズ　幅260　高さ310　以下同じ
	DrawGraph(830, 270, Q2GrHandle, TRUE);
	DrawGraph(1264, 270, Q3GrHandle, TRUE);
	DrawGraph(396, 640, Q4GrHandle, TRUE);
	DrawGraph(830, 640, Q5GrHandle, TRUE);
	DrawGraph(1264, 640, Q6GrHandle, TRUE);
	//int max_x, min_x, max_y, min_y;
	//GetMenuPosition(MENU_NUM::クエスト1, max_x, min_x, max_y, min_y);
	switch (scene)
	{
	case MENU_NUM::クエスト1:
		DrawBox(800, 45, 850, 90, GetColor(255, 0, 0), TRUE);
		break;
		/*case
			break;
		case
			break;
		case
			break;
		case :
			break;
		case
			break;
		default:
			break;*/
	}
}

