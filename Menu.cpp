#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

#include "QuestContent.h"
#include"AABB.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
:_scenemgr(scenemgr)
, _game(game)
,quest(scenemgr,game)
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
	Quest = LoadGraph("images/クエストメニューバー＿2.png");  //
	Adventurer = LoadGraph("images/冒険者_2.png");  //
	Guild = LoadGraph("images/ギルドカラー_2.png");  //

	//_turnnumber.Start = FALSE;

	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Quest, QGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Adventurer, MGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Guild, GGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Save, NGrHandle);


	pattern = MENU_NUM::Null;
	nowSelectedPattern = MENU_NUM::Null;
	oldpattern = MENU_NUM::Null;
	 z = 1;
	
}


Menu::~Menu() {
	
}

//選択項目の領域指定
void Menu::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::Quest:
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
		max_y = 1050;
		min_y = 900;
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

	auto isClick = AABBDraw::ClickCheck();

	if (AABBDraw::IsTouch() == true) {
		auto touch = AABBDraw::GetTouch();

		AABBDraw::LOAD_NUM load[] = {
			AABBDraw::LOAD_NUM::Menu_Quest,
			AABBDraw::LOAD_NUM::Menu_Adventurer,
			AABBDraw::LOAD_NUM::Menu_Guild,
			AABBDraw::LOAD_NUM::Menu_Save,
		};

		MENU_NUM pat[] = {
		MENU_NUM::Quest,
		MENU_NUM::冒険者,
		MENU_NUM::ギルド,
		MENU_NUM::Save,

		};

		for (auto i = 0; i < 16; ++i) {
			int handle = AABBDraw::GetHandle(load[i]);

			if (touch->Handle == handle) {
				pattern = pat[i];
				oldpattern = pat[i];
				if (GetMouseInput() & MOUSE_INPUT_LEFT) {
					nowSelectedPattern = pat[i];
				
				}
				break;
			}


		}
	}



	//GetMenuPosition(MENU_NUM::Quest, max_x, min_x, max_y, min_y);

	//if( (_game.GetMouseX() < max_x) &&
	//	(_game.GetMouseX() > min_x) && 
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {
	//	//DrawGraph(0, 190, Quest, TRUE);
	//	
	//	if (_mousetrg != 0) {
	//		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
	//	}
	//}

	//GetMenuPosition(MENU_NUM::冒険者, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	//}

	//GetMenuPosition(MENU_NUM::ギルド, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
	//}

	//GetMenuPosition(MENU_NUM::交易, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
	//}

	//GetMenuPosition(MENU_NUM::投資, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	//}

	//GetMenuPosition(MENU_NUM::次の月, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
	//}
	GetMenuPosition(MENU_NUM::次のターン, max_x, min_x, max_y, min_y);

	if ((_mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_turnnumber.TurnCount();  //ターン数増加
		//_game.SetRandom();
		quest.Random_Quest();
		
		
		WaitKey();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}

	GetMenuPosition(MENU_NUM::クエスト中, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	}

}
//
////更新
void Menu::Menu_Update() {
//		//ClearDrawScreen();
//		//DrawGraph(0, 60, _cg, FALSE);
//		//DrawString(0, 40, "項目選択", GetColor(255, 255, 255));
	switch (nowSelectedPattern)
	{
	case Menu::MENU_NUM::Quest:
		if (quest_flag == true) {
			quest_flag = false;
			quest.Random_Quest();

		}
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
		break;
	case Menu::MENU_NUM::冒険者:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		break;
	case Menu::MENU_NUM::ギルド:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		break;
	case Menu::MENU_NUM::Save:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Save);
	default:
		break;
	}
	

		pattern = MENU_NUM::Null;
		nowSelectedPattern = MENU_NUM::Null;
		oldpattern = MENU_NUM::Null;

}


//描画
void Menu::Menu_Render() {
	
	AABBDraw::MyDrawGraph(18, 192, QGrHandle, TRUE);
	AABBDraw::MyDrawGraph(18, 411, MGrHandle, TRUE);
	AABBDraw::MyDrawGraph(18, 630, GGrHandle, TRUE);
	AABBDraw::MyDrawGraph(18, 849, NGrHandle, TRUE);

	//DrawGraph(0, 849, NGrHandle, TRUE);
	DrawGraph(1750, 900, NextGrHandle, TRUE);  //次のターンへボタン
	
	
	switch (pattern)
	{
	case Menu::MENU_NUM::Quest:
		DrawGraph(0, 190, Quest, TRUE);
		break;
	case Menu::MENU_NUM::冒険者:
		DrawGraph(0, 338, Adventurer, TRUE);
		break;
	case Menu::MENU_NUM::ギルド:
		DrawGraph(0, 486, Guild, TRUE);
		break;
	case Menu::MENU_NUM::Null:
		break;
	default:
		break;
	}
}

void Menu::HomeMenu_Render() {
	_turnnumber.Draw();
}
