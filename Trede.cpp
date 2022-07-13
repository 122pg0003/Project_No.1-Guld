#include"Trede.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

//コンストラクタ
Trede::Trede(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {

}

//デストラクタ
Trede::~Trede() {

}

void Trede::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::メニュー:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;
	}
}

void Trede::Trede_Input() {
	int max_x, min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::メニュー, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}
}

void Trede::Trede_Update() {

}

void Trede::Trede_Render() {
	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
}