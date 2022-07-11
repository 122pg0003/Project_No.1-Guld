#include"Adventurer.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"





Adventurer::Adventurer(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_cg = LoadGraph("images/Scene_Game.png");
	/*  x1 = 1000 ;
		y1 = 600 ;
		x2 = 100;
		y2 = 100 ;*/

}

Adventurer::~Adventurer() {

}
/*
int hoge[][] = { {170,40,290,260}, {200,50,300,210} };

int[] Adventurer::GetMenuPosition(int menuIndex) {
	return hoge[menuIndex];
}*/
void Adventurer::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::クエスト:
	{
		max_x = 170;
		min_x = 40;
		max_y = 290;
		min_y = 260;

		break;
	}
	}
}

void Adventurer::Adventurer_Input() {

	int max_x = 0;
	int min_x, max_y, min_y;
	GetMenuPosition(0, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && _game.CheckHit() == false/*((_game.GetMouseX() < 170) && (_game.GetMouseX() > 40)) && (_game.GetMouseY() < 290) && (_game.GetMouseY() > 260) * /*/) {
		ClearDrawScreen();
		DrawGraph(0, 60, _cg, FALSE);
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);
		DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));

	}
}
void Adventurer::Adventurer_Update() {


}
