#include"Adventurer.h"
#include"DxLib.h"
//#include"SceneMgr.h"

Adventurer::Adventurer() {

}

Adventurer::~Adventurer() {

}

void Adventurer::Adventurer_Input() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {

		scenemgr.SceneMgr_ChangeScene(scene eScene::Menu);

		DrawString(0, 0, "�`���҉�ʂł��B", GetColor(255, 255, 255));
		DrawString(0, 60, "G�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
	}
}

void Adventurer::Adventurer_Update() {

}
