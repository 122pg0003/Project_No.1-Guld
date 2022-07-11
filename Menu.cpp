#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
	:_scenemgr(scenemgr)
,_game(game) {
	_cg = LoadGraph("images/Scene_Menu.png");
}

Menu::~Menu() {

}

void Menu::Menu_Input() {
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && ((_game.GetMouseX() < 500) && (_game.GetMouseX() > 80)) && (_game.GetMouseY() < 140) && (_game.GetMouseY() > 90)) {
		ClearDrawScreen();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		DrawGraph(0, 60, _cg, FALSE);
		DrawString(0, 40, "マウスをクリックすると冒険者画面に進みます。", GetColor(255, 255, 255));
	}
}

void Menu::Menu_Update() {

}

void Menu::Menu_Render() {
	//DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	//DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}

