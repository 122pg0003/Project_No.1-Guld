#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"

Menu::Menu(SceneMgr& scenemgr)
	:_scenemgr(scenemgr) {

}

Menu::~Menu() {

}

void Menu::Menu_Input() {
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		ClearDrawScreen();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		DrawBox(100, 100, 0, 0, GetColor(255, 0, 0), TRUE);
		DrawString(0, 40, "マウスをクリックすると冒険者画面に進みます。", GetColor(255, 255, 255));
	}
}

void Menu::Menu_Update() {

}

void Menu::Menu_Render() {
	//DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	//DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}

