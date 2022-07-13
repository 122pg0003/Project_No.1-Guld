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

//‘I‘ğ€–Ú‚Ì—Ìˆæw’è
void Adventurer::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::ƒƒjƒ…[:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;

	case MENU_NUM::–`Œ¯Ò1:
	
		max_x = 800;
		min_x = 900;
		max_y = 800;
		min_y = 900;

		break;

	case MENU_NUM::–`Œ¯Ò2:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;

	case MENU_NUM::–`Œ¯Ò3:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	case MENU_NUM::–`Œ¯Ò4:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	case MENU_NUM::–`Œ¯Ò5:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	case MENU_NUM::–`Œ¯Ò6:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;

	case MENU_NUM::–`Œ¯Ò7:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	}
	
}

void Adventurer::Adventurer_Input() {
	int max_x, min_x, max_y, min_y;

	GetMenuPosition(MENU_NUM::ƒƒjƒ…[, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		
				_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);

			}

	GetMenuPosition(MENU_NUM::–`Œ¯Ò1, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
		(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawBox(1000, 900, 900, 100, GetColor(255, 0, 255), TRUE);
		//MENU_NUM scene = MENU_NUM::–`Œ¯Ò1;
		//DrawString(800, 800, "aaaaaaaaaaaa", GetColor(255, 255, 0), FALSE);
				//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::–`Œ¯Ò2, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::–`Œ¯Ò3, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::–`Œ¯Ò4, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::–`Œ¯Ò5, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::–`Œ¯Ò6, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::–`Œ¯Ò7, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
}
void Adventurer::Adventurer_Update() {
		//ClearDrawScreen();
	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
		DrawGraph(100, 200, _cg, TRUE);
		//DrawString(0, 60, "AƒL[‚ğ‰Ÿ‚·‚Æƒƒjƒ…[‰æ–Ê‚Éi‚İ‚Ü‚·B", GetColor(255, 255, 255));
		//if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			switch (scene)
			{
			case Adventurer::MENU_NUM::–`Œ¯Ò1:
				break;
			case Adventurer::MENU_NUM::–`Œ¯Ò2:
				break;
			case Adventurer::MENU_NUM::–`Œ¯Ò3:
				break;
			case Adventurer::MENU_NUM::–`Œ¯Ò4:
				break;
			case Adventurer::MENU_NUM::–`Œ¯Ò5:
				break;
			case Adventurer::MENU_NUM::–`Œ¯Ò6:
				break;
			default:
				break;
			}
		//}

}
