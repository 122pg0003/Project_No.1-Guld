#include"Menu.h"
#include"DxLib.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::Menu_Input() {
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
		DrawString(0, 40, "Gキーを押すと冒険者画面に進みます。", GetColor(255, 255, 255));
	}
}

void Menu::Menu_Update() {

}

void Menu::Menu_Render() {
	//DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	//DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}

