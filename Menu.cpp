#include"Menu.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"

Menu::Menu(SceneMgr& scenemgr, Game& game)
	:_scenemgr(scenemgr)
,_game(game) 
{
	//_cg = LoadGraph("images/Scene_Menu.png");
	QGrHandle = LoadGraph("image/Quest_Slot.png");  //�N�G�X�g�X���b�g
	MGrHandle = LoadGraph("image/Member_Slot.png");  //�����o�[�X���b�g
	GGrHandle = LoadGraph("image/Guild_Slot.png");  //�M���h�X���b�g
	TGrHandle = LoadGraph("image/Trade_Slot.png");  //���ՃX���b�g
	IGrHandle = LoadGraph("image/Investment_Slot.png");  //�����X���b�g
	NGrHandle = LoadGraph("image/Next_Slot.png");  //���փX���b�g
}


Menu::~Menu() {

}

//����
void Menu::Menu_Input() {
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < 140) &&
		(_game.GetMouseX() > 80)) && 
		(_game.GetMouseY() < 290) &&
		(_game.GetMouseY() > 270)) {
     
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Adventurer);
	}
}

//�X�V
void Menu::Menu_Update() {
		ClearDrawScreen();
		//DrawGraph(0, 60, _cg, FALSE);
		DrawString(0, 40, "�}�E�X���N���b�N����Ɩ`���҉�ʂɐi�݂܂��B", GetColor(255, 255, 255));

}

//�I�����ڂ̗̈�w��
void Menu::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
	case MENU_NUM::�N�G�X�g:
	{
		max_x = 140;
		min_x = 80;
		max_y = 290;
		min_y = 270;

		break;
	}
	}
}


//�`��
void Menu::Menu_Render() {
	DrawGraph(0, 190, QGrHandle, TRUE);
	DrawGraph(0, 338, MGrHandle, TRUE);
	DrawGraph(0, 486, GGrHandle, TRUE);
	DrawGraph(0, 634, TGrHandle, TRUE);
	DrawGraph(0, 782, IGrHandle, TRUE);
	DrawGraph(0, 930, NGrHandle, TRUE);
}