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
			DrawString(0, 0, "�`���҉�ʂł��B", GetColor(255, 255, 255));
			DrawString(0, 60, "A�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
		
	}
}

void Adventurer::Adventurer_Update() {

}
