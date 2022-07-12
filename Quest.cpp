#include"Quest.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Quest::Quest(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {

}

//ƒfƒXƒgƒ‰ƒNƒ^
Quest::~Quest()
{

}

//‘I‘ğ€–Ú‚Ì—Ìˆæw’è
void Quest::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::–`Œ¯Ò1:
	{
		max_x = 420;
		min_x = 0;
		max_y = 290;
		min_y = 190;

		break;
	case MENU_NUM::–`Œ¯Ò2:

		max_x = 420;
		min_x = 0;
		max_y = 438;
		min_y = 338;

		break;
	case MENU_NUM::–`Œ¯Ò3:

		max_x = 420;
		min_x = 0;
		max_y = 586;
		min_y = 486;

		break;
	case MENU_NUM::–`Œ¯Ò4:

		max_x = 420;
		min_x = 0;
		max_y = 734;
		min_y = 634;

		break;
	case MENU_NUM::–`Œ¯Ò5:

		max_x = 420;
		min_x = 0;
		max_y = 882;
		min_y = 782;

		break;
	case MENU_NUM::–`Œ¯Ò6:

		max_x = 420;
		min_x = 0;
		max_y = 1030;
		min_y = 930;

		break;

	}
	}
}

//“ü—Í
void Quest::Quest_Input(){
		int max_x, min_x, max_y, min_y;
		GetMenuPosition(MENU_NUM::–`Œ¯Ò1, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
		}

		GetMenuPosition(MENU_NUM::–`Œ¯Ò2, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		}

		GetMenuPosition(MENU_NUM::–`Œ¯Ò3, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		}

		GetMenuPosition(MENU_NUM::–`Œ¯Ò4, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
		}

		GetMenuPosition(MENU_NUM::–`Œ¯Ò5, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
		}

		GetMenuPosition(MENU_NUM::–`Œ¯Ò6, max_x, min_x, max_y, min_y);

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
			((_game.GetMouseX() < max_x) &&
				(_game.GetMouseX() > min_x)) &&
			(_game.GetMouseY() < max_y) &&
			(_game.GetMouseY() > min_y)) {

			_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
		}
	}


//XV
void Quest::Quest_Update() {

}

//•`‰æ
void Quest::Quest_Render() {
	switch (scene)
	{
	case Quest::MENU_NUM::–`Œ¯Ò1:
		break;
	case Quest::MENU_NUM::–`Œ¯Ò2:
		break;
	case Quest::MENU_NUM::–`Œ¯Ò3:
		break;
	case Quest::MENU_NUM::–`Œ¯Ò4:
		break;
	case Quest::MENU_NUM::–`Œ¯Ò5:
		break;
	case Quest::MENU_NUM::–`Œ¯Ò6:
		break;
	default:
		break;
	}

}
