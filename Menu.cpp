#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

#include "QuestContent.h"
#include"AABB.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
:_scenemgr(scenemgr)
, _game(game)
//,quest(scenemgr.quest)
{
	_bg = LoadGraph("images/gi_001.png");  //�z�[�����
	QGrHandle = LoadGraph("images/Quest_Slot.png");  //�N�G�X�g�X���b�g
	MGrHandle = LoadGraph("images/Member_Slot.png");  //�����o�[�X���b�g
	GGrHandle = LoadGraph("images/Guild_Slot.png");  //�M���h�X���b�g
	TGrHandle = LoadGraph("images/Trade_Slot.png");  //���ՃX���b�g
	IGrHandle = LoadGraph("images/Investment_Slot.png");  //�����X���b�g
	NGrHandle = LoadGraph("images/Save_Slot.png");  //�Z�[�u�X���b�g
	QGGrHandle = LoadGraph("images/Quest_Going.png");  //�N�G�X�g���X���b�g
	NextGrHandle = LoadGraph("images/Next_m_3.png");  //���̃^�[���փ{�^��
	NextTurnGrHandle = LoadGraph("images/Base-Illust.png");  //���̃^�[���Ɉڂ鎞�̉��
	Quest = LoadGraph("images/�N�G�X�g���j���[�o�[�Q2.png");  //
	Adventurer = LoadGraph("images/�`����_2.png");  //
	Guild = LoadGraph("images/�M���h�J���[_2.png");  //

	//_turnnumber.Start = FALSE;

	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Quest, QGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Adventurer, MGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Menu_Guild, GGrHandle);


	pattern = MENU_NUM::Null;
	nowSelectedPattern = MENU_NUM::Null;
	oldpattern = MENU_NUM::Null;
	 z = 1;
}


Menu::~Menu() {

}

//�I�����ڂ̗̈�w��
void Menu::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::Quest:
	{
		max_x = 420;
		min_x = 0;
		max_y = 290;
		min_y = 190;

		break;
	case MENU_NUM::�`����:

		max_x = 420;
		min_x = 0;
		max_y = 438;
		min_y = 338;

		break;
	case MENU_NUM::�M���h:

		max_x = 420;
		min_x = 0;
		max_y = 586;
		min_y = 486;

		break;
	case MENU_NUM::����:

		max_x = 420;
		min_x = 0;
		max_y = 734;
		min_y = 634;

		break;
	case MENU_NUM::����:

		max_x = 420;
		min_x = 0;
		max_y = 882;
		min_y = 782;

		break;
	case MENU_NUM::���̌�:

		max_x = 420;
		min_x = 0;
		max_y = 1030;
		min_y = 930;
		break;
	case MENU_NUM::���̃^�[��:

		max_x = 1900;
		min_x = 1750;
		max_y = 150;
		min_y = 0;
		break;

	case MENU_NUM::�N�G�X�g��:
		max_x = 1920;
		min_x = 1500;
		max_y = 290;
		min_y = 190;
		break;

	}
	}
}



//����
void Menu::Menu_Input() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	_mousetrg = (_mouse ^ keyold) & _mouse;
	int max_x, min_x, max_y, min_y;
	int mouse_x = _game.GetMouseX();
	int mouse_y = _game.GetMouseY();

	auto isClick = AABBDraw::ClickCheck();

	if (AABBDraw::IsTouch() == true) {
		auto touch = AABBDraw::GetTouch();

		AABBDraw::LOAD_NUM load[] = {
			AABBDraw::LOAD_NUM::Menu_Quest,
			AABBDraw::LOAD_NUM::Menu_Adventurer,
			AABBDraw::LOAD_NUM::Menu_Guild,
		};

		MENU_NUM pat[] = {
		MENU_NUM::Quest,
		MENU_NUM::�`����,
		MENU_NUM::�M���h,

		};

		for (auto i = 0; i < 16; ++i) {
			int handle = AABBDraw::GetHandle(load[i]);

			if (touch->Handle == handle) {
				pattern = pat[i];
				oldpattern = pat[i];
				if (GetMouseInput() & MOUSE_INPUT_LEFT) {
					nowSelectedPattern = pat[i];
				
				}
				break;
			}


		}
	}



	//GetMenuPosition(MENU_NUM::Quest, max_x, min_x, max_y, min_y);

	//if( (_game.GetMouseX() < max_x) &&
	//	(_game.GetMouseX() > min_x) && 
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {
	//	//DrawGraph(0, 190, Quest, TRUE);
	//	
	//	if (_mousetrg != 0) {
	//		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
	//	}
	//}

	//GetMenuPosition(MENU_NUM::�`����, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	//}

	//GetMenuPosition(MENU_NUM::�M���h, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
	//}

	//GetMenuPosition(MENU_NUM::����, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
	//}

	//GetMenuPosition(MENU_NUM::����, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	//}

	//GetMenuPosition(MENU_NUM::���̌�, max_x, min_x, max_y, min_y);

	//if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {

	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::NextMonth);
	//}
	//GetMenuPosition(MENU_NUM::���̃^�[��, max_x, min_x, max_y, min_y);

	//if ((_mousetrg != 0) &&
	//	((_game.GetMouseX() < max_x) &&
	//		(_game.GetMouseX() > min_x)) &&
	//	(_game.GetMouseY() < max_y) &&
	//	(_game.GetMouseY() > min_y)) {
	//	//ClearDrawScreen();
	//	_turnnumber.TurnCount();  //�^�[��������
	//	//DrawGraph(135,115, NextTurnGrHandle, TRUE);
	//	//ScreenFlip();
	//	WaitKey();
	//	_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	//}

	GetMenuPosition(MENU_NUM::�N�G�X�g��, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {

		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Investment);
	}

}
//
////�X�V
void Menu::Menu_Update() {
//		//ClearDrawScreen();
//		//DrawGraph(0, 60, _cg, FALSE);
//		//DrawString(0, 40, "���ڑI��", GetColor(255, 255, 255));
	switch (nowSelectedPattern)
	{
	case Menu::MENU_NUM::Quest:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Quest);
		break;
	case Menu::MENU_NUM::�`����:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
		break;
	case Menu::MENU_NUM::�M���h:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Guild);
		break;
	case Menu::MENU_NUM::����:
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Trede);
	default:
		break;
	}
	
	//if (z == 1) {
		pattern = MENU_NUM::Null;
		nowSelectedPattern = MENU_NUM::Null;
		oldpattern = MENU_NUM::Null;
 //    z = -1;
	//}

}


//�`��
void Menu::Menu_Render() {
	//int no = 100;
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "������%d/n", no);
	//DrawGraph(0, 0, _bg, TRUE);

	//DrawGraph(0, 190, Quest, TRUE);
	AABBDraw::MyDrawGraph(0, 190, QGrHandle, TRUE);
	AABBDraw::MyDrawGraph(0, 338, MGrHandle, TRUE);
	AABBDraw::MyDrawGraph(0, 486, GGrHandle, TRUE);


	//DrawGraph(0, 338, MGrHandle, TRUE);
	//DrawGraph(0, 486, GGrHandle, TRUE);
	DrawGraph(0, 634, TGrHandle, TRUE);
	DrawGraph(0, 782, IGrHandle, TRUE);
	DrawGraph(0, 930, NGrHandle, TRUE);
	DrawGraph(1750, 0, NextGrHandle, TRUE);  //���̃^�[���փ{�^��
	//_turnnumber.Draw();
	DrawGraph(1500, 190, QGGrHandle, TRUE);  //�N�G�X�g���X���b�g�A�N�G�X�g�ɍs���Ă���Ԃ����\��������
	
	switch (pattern)
	{
	case Menu::MENU_NUM::Quest:
		DrawGraph(0, 190, Quest, TRUE);
		break;
	case Menu::MENU_NUM::�`����:
		DrawGraph(0, 338, Adventurer, TRUE);
		break;
	case Menu::MENU_NUM::�M���h:
		DrawGraph(0, 486, Guild, TRUE);
		break;
	case Menu::MENU_NUM::Null:
		break;
	default:
		break;
	}
}

void Menu::HomeMenu_Render() {
	_turnnumber.Draw();
}
