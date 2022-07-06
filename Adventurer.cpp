#include"Adventurer.h"
#include"SceneMgr.h"
#include"DxLib.h"

Adventurer::Adventurer(SceneMgr& scenemgr)
:_scenemgr(scenemgr)
{

}

Adventurer::~Adventurer() {

}

void Adventurer::Adventurer_Input() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {
		ClearDrawScreen();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		DrawString(0, 0, "�`���҉�ʂł��B", GetColor(255, 255, 255));
		DrawString(0, 60, "A�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
	}
}

void Adventurer::Adventurer_Update() {

}
