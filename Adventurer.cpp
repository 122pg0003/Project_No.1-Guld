#include"Adventurer.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"AABB.h"





Adventurer::Adventurer(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	       Back = LoadGraph("images/back.png");
	       menu = LoadGraph("images/chw_0.png");
	Adventurer1 = LoadGraph("images/ch_001.mini3.png ");
    Adventurer2 = LoadGraph("images/ch_02.mini3.png ");
    Adventurer3 = LoadGraph("images/ch_03_mini03.png ");
    Adventurer4 = LoadGraph("images/ ch_005_mini03.png");
    Adventurer5 = LoadGraph("images/ ch_06.mini3.png");
    Adventurer6 = LoadGraph("images/ ch_08_mini3.png");
	a = LoadGraph("images/ch_001.mini3.png");
	b = LoadGraph("images/ch_02.mini3.png");
	c = LoadGraph("images/ch_03_mini03.png");

   
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer1, Adventurer1);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer2, Adventurer2);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer3, Adventurer3);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer4, Adventurer4);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer5, Adventurer5);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Adventurer6, Adventurer6);

	ScreenNo = 1;
	pattern = MENU_NUM::Null;
	nowSelectedPattern = MENU_NUM::Null;
	oldpattern = MENU_NUM::Null;
}




Adventurer::~Adventurer() {

}
/*
int hoge[][] = { {170,40,290,260}, {200,50,300,210} };

int[] Adventurer::GetMenuPosition(int menuIndex) {
	return hoge[menuIndex];
}*/

//ëIëçÄñ⁄ÇÃóÃàÊéwíË
void Adventurer::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::Return:
	{
		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;
		break;
	}
	}
}


void Adventurer::Adventurer_Input() {
	int max_x, min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::Return, max_x, min_x, max_y, min_y);
	//âEè„ÇÃBOXÇÉNÉäÉbÉNÇ∑ÇÈÇ∆ÉzÅ[ÉÄÇ…ñﬂÇÈ
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);

	}

	auto isClick = AABBDraw::ClickCheck();

	if (AABBDraw::IsTouch() == true) {
		auto touch = AABBDraw::GetTouch();

		AABBDraw::LOAD_NUM load[] = {
		AABBDraw::LOAD_NUM::Adventurer1,///ñ`åØé“1
		AABBDraw::LOAD_NUM::Adventurer2,///ñ`åØé“2
		AABBDraw::LOAD_NUM::Adventurer3,///ñ`åØé“3
		AABBDraw::LOAD_NUM::Adventurer4,///ñ`åØé“4
		AABBDraw::LOAD_NUM::Adventurer5,///ñ`åØé“5
		AABBDraw::LOAD_NUM::Adventurer6,///ñ`åØé“6
		};
		MENU_NUM pat[] = {
		MENU_NUM::Adventurer1 ,
		MENU_NUM::Adventurer2 ,
		MENU_NUM::Adventurer3 ,
		MENU_NUM::Adventurer4 ,
		MENU_NUM::Adventurer5 ,
		MENU_NUM::Adventurer6 ,
		};

		for (auto i = 0; i < 16; ++i) {
			//if (pat[i] == MENU_NUM::Set) {
			//	pattern = MENU_NUM::GuildMenu;
			//}

			int handle = AABBDraw::GetHandle(load[i]);

			if (touch->Handle == handle) {
				pattern = pat[i];
				oldpattern = pat[i];
				break;
			}

		}

	}

}

void Adventurer::Adventurer_Update() {
		

}

void Adventurer::Adventurer_Render() {
	DrawGraph(0, 0, menu, TRUE);
	DrawGraph(1750, 20, Back, TRUE);

	AABBDraw::MyDrawGraph(790,234,Adventurer1,TRUE);
	AABBDraw::MyDrawGraph(1014,234,Adventurer2,TRUE);
	AABBDraw::MyDrawGraph(1238,234,Adventurer3,TRUE);
	AABBDraw::MyDrawGraph(1462,234,Adventurer4,TRUE);
	AABBDraw::MyDrawGraph(898,575,Adventurer5,TRUE);
	AABBDraw::MyDrawGraph(1125,575,Adventurer6,TRUE);

	switch (pattern)
	{
	case Adventurer::MENU_NUM::Adventurer1:
		DrawGraph(174, 215, a, TRUE);
		break;
	case Adventurer::MENU_NUM::Adventurer2:
		DrawGraph(174, 215, b, TRUE);
		break;
	case Adventurer::MENU_NUM::Adventurer3:
		DrawGraph(174, 215, c, TRUE);
		break;
	case Adventurer::MENU_NUM::Adventurer4:
		break;
	case Adventurer::MENU_NUM::Adventurer5:
		break;
	case Adventurer::MENU_NUM::Adventurer6:
		break;
	case Adventurer::MENU_NUM::Null:
		break;
	default:
		break;
	}
}

