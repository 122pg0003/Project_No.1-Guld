#include"Adventurer.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

class SceneMgr;


Adventurer::Adventurer(SceneMgr& scenemgr,Game& game):
	_scenemgr(scenemgr)
	,_game(game)
{

}

Adventurer::~Adventurer() {

}


void Adventurer::Adventurer_Input() {
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)  {
		/*if (_game.GetMouse() > 0)*/
			ClearDrawScreen();
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			DrawString(0, 0, "冒険者画面です。", GetColor(255, 255, 255));
			DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
		
	}
}

void Adventurer::Adventurer_Update() {

}
