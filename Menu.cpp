#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include "Quest.h"
#include "QuestContent.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
:_scenemgr(scenemgr)
, _game(game)
//,quest(scenemgr.quest)
{
	_bg = LoadGraph("images/gi_001.png");  //ホーム画面
	QGrHandle = LoadGraph("images/Quest_Slot.png");  //クエストスロット
	MGrHandle = LoadGraph("images/Member_Slot.png");  //メンバースロット
	GGrHandle = LoadGraph("images/Guild_Slot.png");  //ギルドスロット
	TGrHandle = LoadGraph("images/Trade_Slot.png");  //交易スロット
	IGrHandle = LoadGraph("images/Investment_Slot.png");  //投資スロット
	NGrHandle = LoadGraph("images/Save_Slot.png");  //セーブスロット
	QGGrHandle = LoadGraph("images/Quest_Going.png");  //クエスト中スロット
	NextGrHandle = LoadGraph("images/Next_m_3.png");  //次のターンへボタン
	NextTurnGrHandle = LoadGraph("images/Base-Illust.png");  //次のターンに移る時の画面
	//_turnnumber.Start = FALSE;
}


Menu::~Menu() {

}

//選択項目の領域指定
void Menu::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::クエスト:
	{
		max_x = 420;
		min_x = 0;
		max_y = 290;
		min_y = 190;

		break;
	case MENU_NUM::冒険者:

		max_x = 420;
		min_x = 0;
		max_y = 438;
		min_y = 338;

		break;
	case MENU_NUM::ギルド:

		max_x = 420;
		min_x = 0;
		max_y = 586;
		min_y = 486;

		break;
	case MENU_NUM::交易:

		max_x = 420;
		min_x = 0;
		max_y = 734;
		min_y = 634;

		break;
	case MENU_NUM::投資:

		max_x = 420;
		min_x = 0;
		max_y = 882;
		min_y = 782;

		break;
	case MENU_NUM::次の月:

		max_x = 420;
		min_x = 0;
		max_y = 1030;
		min_y = 930;
		break;
	case MENU_NUM::次のターン:

		max_x = 1900;
		min_x = 1750;
		max_y = 150;
		min_y = 0;
		break;

	case MENU_NUM::クエスト中:
		max_x = 1920;
		min_x = 1500;
		max_y = 290;
		min_y = 190;
		break;

	}
	}
}



//入力
void Menu::Menu_Input() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();
	

	GetMenuPosition(MENU_NUM::クエスト, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
		(_game.GetMouseX() > min_x)) && 
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
	}

	GetMenuPosition(MENU_NUM::冒険者, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	}

	GetMenuPosition(MENU_NUM::ギルド, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
	}

	GetMenuPosition(MENU_NUM::交易, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
	}

	GetMenuPosition(MENU_NUM::投資, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	}

	GetMenuPosition(MENU_NUM::次の月, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
	}
	GetMenuPosition(MENU_NUM::次のターン, max_x, min_x, max_y, min_y);

	if ((_mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//ClearDrawScreen();
		_turnnumber.TurnCount();  //ターン数増加
		//DrawGraph(135,115, NextTurnGrHandle, TRUE);
		//ScreenFlip();
		WaitKey();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}

	GetMenuPosition(MENU_NUM::クエスト中, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::QuestEnd);
	}

}

//更新
void Menu::Menu_Update() {
		//ClearDrawScreen();
		//DrawGraph(0, 60, _cg, FALSE);
		//DrawString(0, 40, "項目選択", GetColor(255, 255, 255));

}


//描画
void Menu::Menu_Render() {
	//int no = 100;
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "所持金%d/n", no);
	//DrawGraph(0, 0, _bg, TRUE);
	DrawGraph(0, 190, QGrHandle, TRUE);
	DrawGraph(0, 338, MGrHandle, TRUE);
	DrawGraph(0, 486, GGrHandle, TRUE);
	DrawGraph(0, 634, TGrHandle, TRUE);
	DrawGraph(0, 782, IGrHandle, TRUE);
	DrawGraph(0, 930, NGrHandle, TRUE);
	DrawGraph(1750, 0, NextGrHandle, TRUE);  //次のターンへボタン
	//_turnnumber.Draw();
	DrawGraph(1500, 190, QGGrHandle, TRUE);  //クエスト中スロット、クエストに行っている間だけ表示したい
	
}

void Menu::HomeMenu_Render() {
	_turnnumber.Draw();
}
