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
		DrawString(0, 0, "冒険者画面です。", GetColor(255, 255, 255));
		DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
	}
}

void Adventurer::Adventurer_Update() {

}
