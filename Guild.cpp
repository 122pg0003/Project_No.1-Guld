#include"Guild.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

//�R���X�g���N�^
Guild::Guild(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_BIGrHandle = LoadGraph("images/Base-Illust.png");
	_BuildingSlotGrHandle = LoadGraph("images/building.png");
	_BuildingGrHandle = LoadGraph("images/List.png");
	_ButtonGrHandle = LoadGraph("images/pointer.png");
}

//�f�X�g���N�^
Guild::~Guild() {

}

void Guild::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	{
	case MENU_NUM::���j���[:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;
	case MENU_NUM::����:
		max_x = 900;
		min_x = 270;
		max_y = 350;
		min_y = 275;

		break;
	case MENU_NUM::�h:

		max_x = 900;
		min_x = 270;
		max_y = 435;
		min_y = 360;

		break;
	case MENU_NUM::����:

		max_x = 1785;
		min_x = 1770;
		max_y = 1035;
		min_y = 1020;

		break;
	}
	}
}

void Guild::Guild_Input() {
	int max_x, min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::���j���[, max_x, min_x, max_y, min_y);

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		math.Guild_B();
		//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);

	}
	
	GetMenuPosition(MENU_NUM::�h, max_x, min_x, max_y, min_y);
	GetMenuPosition(MENU_NUM::����, max_x, min_x, max_y, min_y);

	if ((GetMouseInput()) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawGraph(985, 235, _BuildingGrHandle, TRUE);  //��ԏ�̉摜�ɐG�ꂽ�Ƃ��ɕ\������
	}

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawGraph(985, 235, _BuildingGrHandle, TRUE);  //�摜���N���b�N���ꂽ�Ƃ��ɕ\������
		DrawGraph(1770, 1020, _ButtonGrHandle, TRUE);  //�摜�T�C�Y�@��15�A����15
	}

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawString(1000, 255, "��������݂��܂����B", GetColor(0, 0, 0));  //�{�^���������ꂽ�Ƃ��ɕ\������
		WaitKey();
	}
	DrawGraph(135, 185, _BIGrHandle, TRUE);  //�摜�T�C�Y�@��1650�A����850
	DrawGraph(235, 235, _BuildingGrHandle, TRUE);  //�摜�T�C�Y�@��700�A����750
	for (auto i = 0; i < 8; ++i) {
		int offset = i * 85;
		DrawGraph(270, 275 + offset, _BuildingSlotGrHandle, TRUE);  //�摜�T�C�Y�@��630�A����75
	}

	GetMenuPosition(MENU_NUM::�h, max_x, min_x, max_y, min_y);
	GetMenuPosition(MENU_NUM::����, max_x, min_x, max_y, min_y);

	if ((GetMouseInput()) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawGraph(985, 235, _BuildingGrHandle, TRUE);  //�ォ���Ԗڂ̉摜�ɐG�ꂽ�Ƃ��ɕ\������
	}

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawGraph(985, 235, _BuildingGrHandle, TRUE);  //�摜���N���b�N���ꂽ�Ƃ��ɕ\������
		DrawGraph(1770, 1020, _ButtonGrHandle, TRUE);  //�摜�T�C�Y�@��15�A����15
	}

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		DrawString(1000, 255, "�h�����݂��܂����B", GetColor(0, 0, 0));  //�{�^���������ꂽ�Ƃ��ɕ\������
		WaitKey();
	}
}

void Guild::Guild_Update() {

}

void Guild::Guild_Render() {
	DrawGraph(135, 185, _BIGrHandle, TRUE);  //�摜�T�C�Y�@��1650�A����850
	DrawGraph(235, 235, _BuildingGrHandle, TRUE);  //�摜�T�C�Y�@��700�A����750
	for (auto i = 0; i < 8; ++i) {
		int offset = i * 85;
		DrawGraph(270, 275 + offset, _BuildingSlotGrHandle, TRUE);  //�摜�T�C�Y�@��630�A����75
	}

	DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
}