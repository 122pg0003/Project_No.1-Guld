#include"Menu.h"
#include"DxLib.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::Menu_Input() {
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
		DrawString(0, 40, "G�L�[�������Ɩ`���҉�ʂɐi�݂܂��B", GetColor(255, 255, 255));
	}
}

void Menu::Menu_Update() {

}

void Menu::Menu_Render() {
	//DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
	//DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

