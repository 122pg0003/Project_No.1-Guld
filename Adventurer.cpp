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

	case MENU_NUM::冒険者:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;

	}
	}
}

void Adventurer::Adventurer_Input() {

	int max_x;
	int min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::クエスト, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) &&
		((_game.GetMouseX() < max_x) &&
		(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::冒険者, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
}
void Adventurer::Adventurer_Update() {
		ClearDrawScreen();
		DrawGraph(100, 200, _cg, FALSE);
		DrawString(0, 60, "Aキーを押すとメニュー画面に進みます。", GetColor(255, 255, 255));


}
