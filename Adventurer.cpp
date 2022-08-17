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
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	Q1GrHandle = LoadGraph("images/Quest-1.png");  //�N�G�X�g1�X���b�g
	Q2GrHandle = LoadGraph("images/Quest-2.png");  //�N�G�X�g2�X���b�g
	Q3GrHandle = LoadGraph("images/Quest-3.png");  //�N�G�X�g3�X���b�g
	Q4GrHandle = LoadGraph("images/Quest-4.png");  //�N�G�X�g4�X���b�g
	Q5GrHandle = LoadGraph("images/Quest-5.png");  //�N�G�X�g5�X���b�g
	Q6GrHandle = LoadGraph("images/Quest-6.png");  //�N�G�X�g6�X���b�g
}



Adventurer::~Adventurer() {

}
/*
int hoge[][] = { {170,40,290,260}, {200,50,300,210} };

int[] Adventurer::GetMenuPosition(int menuIndex) {
	return hoge[menuIndex];
}*/

//�I�����ڂ̗̈�w��
void Adventurer::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::���j���[:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;

	case MENU_NUM::�`����1:
	
		max_x = 656;
		min_x = 396;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::�`����2:

		max_x = 1090;
		min_x = 830;
		max_y = 580;
		min_y = 270;

		break;

	case MENU_NUM::�`����3:

		max_x = 1524;
		min_x = 1264;
		max_y = 580;
		min_y = 270;

		break;
	case MENU_NUM::�`����4:

		max_x = 656;
		min_x = 396;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::�`����5:

		max_x = 1090;
		min_x = 830;
		max_y = 950;
		min_y = 640;

		break;
	case MENU_NUM::�`����6:

		max_x = 1524;
		min_x = 1264;
		max_y = 950;
		min_y = 640;

		break;

	case MENU_NUM::�`����7:

		max_x = 600;
		min_x = 500;
		max_y = 600;
		min_y = 500;

		break;
	}
	
}

void Adventurer::Adventurer_Input() {
	int max_x, min_x, max_y, min_y;

	GetMenuPosition(MENU_NUM::���j���[, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		
				_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);

			}

	GetMenuPosition(MENU_NUM::�`����1, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
		(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
	//DrawBox(1000, 900, 900, 100, GetColor(255, 0, 255), TRUE);
		MENU_NUM scene = MENU_NUM::�`����1;
		//DrawString(800, 800, "aaaaaaaaaaaa", GetColor(255, 255, 0), FALSE);
				//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::�`����2, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::�`����2;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::�`����3, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::�`����3;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::�`����4, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::�`����4;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::�`����5, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::�`����5;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}
	GetMenuPosition(MENU_NUM::�`����6, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		MENU_NUM scene = MENU_NUM::�`����6;
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		//DrawBox(x1,y1,x2,y2,GetColor(255, 0, 0), TRUE);

	}

	GetMenuPosition(MENU_NUM::�`����7, max_x, min_x, max_y, min_y);

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
		DrawGraph(400, 200, _cg, TRUE);
		//DrawString(0, 60, "A�L�[�������ƃ��j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
		//if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			switch (scene)
			{
			case Adventurer::MENU_NUM::�`����1:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::�`����2:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::�`����3:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::�`����4:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::�`����5:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			case Adventurer::MENU_NUM::�`����6:
				DrawBox(200, 200, 200, 200, GetColor(255, 0, 0), TRUE);
				break;
			}
		//}

}

void Adventurer::Adventurer_Render() {
	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
	DrawGraph(135, 185, _BIGrHandle, TRUE);
	//DrawGraph(400, 200, _cg, TRUE);
	DrawGraph(396, 270, Q1GrHandle, TRUE);  //�摜�T�C�Y�@��260�@����310�@�ȉ�����
	DrawGraph(830, 270, Q2GrHandle, TRUE);
	DrawGraph(1264, 270, Q3GrHandle, TRUE);
	DrawGraph(396, 640, Q4GrHandle, TRUE);
	DrawGraph(830, 640, Q5GrHandle, TRUE);
	DrawGraph(1264, 640, Q6GrHandle, TRUE);
}

