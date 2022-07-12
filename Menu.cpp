#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
	:_scenemgr(scenemgr)
,_game(game) 
{
	//_cg = LoadGraph("images/Scene_Menu.png");
	QGrHandle = LoadGraph("image/Quest_Slot.png");  //クエストスロット
	MGrHandle = LoadGraph("image/Member_Slot.png");  //メンバースロット
	GGrHandle = LoadGraph("image/Guild_Slot.png");  //ギルドスロット
	TGrHandle = LoadGraph("image/Trade_Slot.png");  //交易スロット
	IGrHandle = LoadGraph("image/Investment_Slot.png");  //投資スロット
	NGrHandle = LoadGraph("image/Next_Slot.png");  //次へスロット
}


Menu::~Menu() {

}

//入力
void Menu::Menu_Input() {
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < 140) &&
		(_game.GetMouseX() > 80)) && 
		(_game.GetMouseY() < 290) &&
		(_game.GetMouseY() > 270)) {
     
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	}
}

//更新
void Menu::Menu_Update() {
		ClearDrawScreen();
		//DrawGraph(0, 60, _cg, FALSE);
		DrawString(0, 40, "マウスをクリックすると冒険者画面に進みます。", GetColor(255, 255, 255));

}

//選択項目の領域指定
void Menu::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::クエスト:
	{
		max_x = 140;
		min_x = 80;
		max_y = 290;
		min_y = 270;

		break;
	}
	}
}


//描画
void Menu::Menu_Render() {
	DrawGraph(0, 190, QGrHandle, TRUE);
	DrawGraph(0, 338, MGrHandle, TRUE);
	DrawGraph(0, 486, GGrHandle, TRUE);
	DrawGraph(0, 634, TGrHandle, TRUE);
	DrawGraph(0, 782, IGrHandle, TRUE);
	DrawGraph(0, 930, NGrHandle, TRUE);
}