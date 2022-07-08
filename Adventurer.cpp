#include"Adventurer.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

class SceneMgr;


Adventurer::Adventurer(SceneMgr& scenemgr,Game& game):
	_scenemgr(scenemgr)
	,_game(game)
{
	_cg = LoadGraph("images/Scene_Game.png");
	/*  x1 = 1000 ;
		y1 = 600 ;
		x2 = 100;
		y2 = 100 ;*/

}

Adventurer::~Adventurer() {

}


void Adventurer::Adventurer_Input() {
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && ((_game.GetMouseX() < 100) && (_game.GetMouseX() > 0)) && (_game.GetMouseY() < 100) && (_game.GetMouseY() > 0) && (scene != SceneMgr::eScene::Adventurer)) {
			ClearDrawScreen();
			DrawGraph(0, 60, _cg, FALSE);
			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
			//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);
			DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));
	
	}
}
void Adventurer::Adventurer_Update() {


}
