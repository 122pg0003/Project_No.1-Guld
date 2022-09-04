#include"Guild.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"AABB.h"

//�R���X�g���N�^
Guild::Guild(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_BIGrHandle = LoadGraph("images/window.png");
	_BuildingSlotGrHandle = LoadGraph("images/building.png");
	_BuildingGrHandle = LoadGraph("images/Guild.png");  //���X�g�̃x�[�X
	_ButtonGrHandle = LoadGraph("images/pointer.png");

	upGrHandle = LoadGraph("images/up.png");  //����
	downGrHandle = LoadGraph("images/down.png");  //�����
	setGrHandle = LoadGraph("images/g_set.png");  //�ݒu�{�^��
	g_0GrHandle = LoadGraph("images/g_0.png");  //�I��g

	g_1GrHandle = LoadGraph("images/g_1.png");  //1�̓M���h����
	g_1_1GrHandle = LoadGraph("images/G_1_1.png");
	g_1_2GrHandle = LoadGraph("images/G_1_2.png");
	g_1_3GrHandle = LoadGraph("images/G_1_3.png");

	g_2GrHandle = LoadGraph("images/g_2.png");  //2�͎���
	g_2_1GrHandle = LoadGraph("images/G_2_1.png");
	g_2_2GrHandle = LoadGraph("images/G_2_2.png");
	g_2_3GrHandle = LoadGraph("images/G_2_3.png");

	g_3GrHandle = LoadGraph("images/g_3.png");  //3�͉�����
	g_3_1GrHandle = LoadGraph("images/G_3_1.png");
	g_3_2GrHandle = LoadGraph("images/G_3_2.png");
	g_3_3GrHandle = LoadGraph("images/G_3_3.png");

	g_4GrHandle = LoadGraph("images/g_4.png");  //4�͑嗁��
	g_4_1GrHandle = LoadGraph("images/G_4_1.png");
	g_4_2GrHandle = LoadGraph("images/G_4_2.png");
	g_4_3GrHandle = LoadGraph("images/G_4_3.png");

	g_5GrHandle = LoadGraph("images/g_5.png");  //5�͐H��
	g_5_1GrHandle = LoadGraph("images/G_5_1.png");
	g_5_2GrHandle = LoadGraph("images/G_5_2.png");
	g_5_3GrHandle = LoadGraph("images/G_5_3.png");

	g_6GrHandle = LoadGraph("images/g_6.png");  //6�͐V�����s��
	g_6_1GrHandle = LoadGraph("images/G_6_1.png");
	g_6_2GrHandle = LoadGraph("images/G_6_2.png");
	g_6_3GrHandle = LoadGraph("images/G_6_3.png");

	g_7GrHandle = LoadGraph("images/g_7.png");  //7�͕��퉮�@�����܂�1�y�[�W��
	g_7_1GrHandle = LoadGraph("images/G_7_1.png");
	g_7_2GrHandle = LoadGraph("images/G_7_2.png");
	g_7_3GrHandle = LoadGraph("images/G_7_3.png");

	g_8GrHandle = LoadGraph("images/g_8.png");  //8�͖h�
	g_8_1GrHandle = LoadGraph("images/G_8_1.png");
	g_8_2GrHandle = LoadGraph("images/G_8_2.png");
	g_8_3GrHandle = LoadGraph("images/G_8_3.png");

	g_9GrHandle = LoadGraph("images/g_9.png");  //9�͋���
	g_9_1GrHandle = LoadGraph("images/G_9_1.png");
	g_9_2GrHandle = LoadGraph("images/G_9_2.png");
	g_9_3GrHandle = LoadGraph("images/G_9_3.png");

	g_10GrHandle = LoadGraph("images/g_10.png");  //10�͎ˌ���
	g_10_1GrHandle = LoadGraph("images/G_10_1.png");
	g_10_2GrHandle = LoadGraph("images/G_10_2.png");
	g_10_3GrHandle = LoadGraph("images/G_10_3.png");

	g_11GrHandle = LoadGraph("images/g_11.png");  //11�͌��p��
	g_11_1GrHandle = LoadGraph("images/G_11_1.png");
	g_11_2GrHandle = LoadGraph("images/G_11_2.png");
	g_11_3GrHandle = LoadGraph("images/G_11_3.png");

	g_12GrHandle = LoadGraph("images/g_12.png");  //12�͒b�B��
	g_12_1GrHandle = LoadGraph("images/G_12_1.png");
	g_12_2GrHandle = LoadGraph("images/G_12_2.png");
	g_12_3GrHandle = LoadGraph("images/G_12_3.png");

	g_13GrHandle = LoadGraph("images/g_13.png");  //13�̓A�g���G
	g_13_1GrHandle = LoadGraph("images/G_13_1.png");
	g_13_2GrHandle = LoadGraph("images/G_13_2.png");
	g_13_3GrHandle = LoadGraph("images/G_13_3.png");

	g_14GrHandle = LoadGraph("images/g_14.png");  //14�͐}����
	g_14_1GrHandle = LoadGraph("images/G_14_1.png");
	g_14_2GrHandle = LoadGraph("images/G_14_2.png");
	g_14_3GrHandle = LoadGraph("images/G_14_3.png");

	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Up, upGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Down, downGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Set, setGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Guild, g_1GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Bar, g_2GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Theater, g_3GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Bath, g_4GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Dining, g_5GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Newspaper, g_6GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Weapon, g_7GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Armor, g_8GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Church, g_9GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Rifle, g_10GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Sword, g_11GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Training, g_12GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Atelier, g_13GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Library, g_14GrHandle);


	ScreenNo = 1;
	pattern = MENU_NUM::Null;
	nowSelectedPattern = MENU_NUM::Null;
	oldpattern = MENU_NUM::Null;
}

//�f�X�g���N�^
Guild::~Guild() {

}

void Guild::GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y) {
	switch (menuIndex)
	{
		{
	case MENU_NUM::Return:

		max_x = 1850;
		min_x = 1800;
		max_y = 90;
		min_y = 45;

		break;
	case MENU_NUM::Up:

		max_x = 575;
		min_x = 505;
		max_y = 330;
		min_y = 260;

		break;
	case MENU_NUM::Down:

		max_x = 575;
		min_x = 505;
		max_y = 958;
		min_y = 888;

		break;
	case MENU_NUM::Set:

		max_x = 1675;
		min_x = 1435;
		max_y = 935;
		min_y = 825;

		break;
		}
	}
}

void Guild::Guild_Input() {
	int max_x, min_x, max_y, min_y;
	GetMenuPosition(MENU_NUM::Return, max_x, min_x, max_y, min_y);
	//�E���BOX���N���b�N����ƃz�[���ɖ߂�
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
		AABBDraw::LOAD_NUM::Up,
		AABBDraw::LOAD_NUM::Down,
		//AABBDraw::LOAD_NUM::Set,  //����
		AABBDraw::LOAD_NUM::Guild,  //�M���h�g��
		AABBDraw::LOAD_NUM::Bar,  //����
		AABBDraw::LOAD_NUM::Theater,  //������
		AABBDraw::LOAD_NUM::Bath,  //�嗁��
		AABBDraw::LOAD_NUM::Dining,  //�H��
		AABBDraw::LOAD_NUM::Newspaper,  //�V�����s��
		AABBDraw::LOAD_NUM::Weapon,  //���퉮
		AABBDraw::LOAD_NUM::Armor,  //�h�
		AABBDraw::LOAD_NUM::Church,  //����
		AABBDraw::LOAD_NUM::Rifle,  //�ˌ���
		AABBDraw::LOAD_NUM::Sword,  //���p��
		AABBDraw::LOAD_NUM::Training,  //�b�B��
		AABBDraw::LOAD_NUM::Atelier,  //�A�g���G
		AABBDraw::LOAD_NUM::Library,  //�}����
		};
		MENU_NUM pat[] = {
		MENU_NUM::Up,
		MENU_NUM::Down,
		//MENU_NUM::Set,  //����
		MENU_NUM::Guild,  //�M���h�g��
		MENU_NUM::Bar,  //����
		MENU_NUM::Theater,  //������
		MENU_NUM::Bath,  //�嗁��
		MENU_NUM::Dining,  //�H��
		MENU_NUM::Newspaper,  //�V�����s��
		MENU_NUM::Weapon,  //���퉮
		MENU_NUM::Armor,  //�h�
		MENU_NUM::Church,  //����
		MENU_NUM::Rifle,  //�ˌ���
		MENU_NUM::Sword,  //���p��
		MENU_NUM::Training,  //�b�B��
		MENU_NUM::Atelier,  //�A�g���G
		MENU_NUM::Library,  //�}����
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

	//if (AABBDraw::ClickCheck() == true)
	//{
	//	nowSelectedPattern = pattern;
	//}

	GetMenuPosition(MENU_NUM::Set, max_x, min_x, max_y, min_y);
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		nowSelectedPattern = MENU_NUM::Set;
	}

	//�����N���b�N����ƃy�[�W���؂�ւ��
	GetMenuPosition(MENU_NUM::Up, max_x, min_x, max_y, min_y);
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		ScreenNo = 1;
	}

	GetMenuPosition(MENU_NUM::Down, max_x, min_x, max_y, min_y);
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		ScreenNo = 2;
	}
}

void Guild::Guild_Update() {

}

void Guild::Guild_Render() {
	if (ScreenNo == 1) {
		DrawGraph(135, 185, _BIGrHandle, TRUE);  //�摜�T�C�Y�@��1650�A����850
		DrawGraph(205, 255, _BuildingGrHandle, TRUE);  //�摜�T�C�Y�@��680�A����710

		AABBDraw::MyDrawGraph(243, 293, g_1GrHandle, TRUE);  //�M���h���݃X���b�g
		AABBDraw::MyDrawGraph(243, 378, g_2GrHandle, TRUE);  //����
		AABBDraw::MyDrawGraph(243, 463, g_3GrHandle, TRUE);  //������
		AABBDraw::MyDrawGraph(243, 548, g_4GrHandle, TRUE);  //�嗁��
		AABBDraw::MyDrawGraph(243, 633, g_5GrHandle, TRUE);  //�H��
		AABBDraw::MyDrawGraph(243, 718, g_6GrHandle, TRUE);  //�V�����s��
		AABBDraw::MyDrawGraph(243, 803, g_7GrHandle, TRUE);  //���퉮

		AABBDraw::MyDrawGraph(505, 888, downGrHandle, TRUE);  //�����

		DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
	}

	if (ScreenNo == 2) {
		DrawGraph(135, 185, _BIGrHandle, TRUE);  //�摜�T�C�Y�@��1650�A����850
		DrawGraph(205, 255, _BuildingGrHandle, TRUE);  //�摜�T�C�Y�@��680�A����710

		AABBDraw::MyDrawGraph(243, 335, g_8GrHandle, TRUE);  //�M���h���݃X���b�g
		AABBDraw::MyDrawGraph(243, 420, g_9GrHandle, TRUE);  //�h�
		AABBDraw::MyDrawGraph(243, 505, g_10GrHandle, TRUE);  //����
		AABBDraw::MyDrawGraph(243, 590, g_11GrHandle, TRUE);  //�ˌ���
		AABBDraw::MyDrawGraph(243, 675, g_12GrHandle, TRUE);  //���p��
		AABBDraw::MyDrawGraph(243, 760, g_13GrHandle, TRUE);  //�A�g���G
		AABBDraw::MyDrawGraph(243, 845, g_14GrHandle, TRUE);  //�}����

		AABBDraw::MyDrawGraph(505, 260, upGrHandle, TRUE);  //����

		DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
	}

	switch (pattern)
	{
	case MENU_NUM::Guild:
	{
		DrawGraph(243, 293, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_1_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Bar:
	{
		DrawGraph(243, 378, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_2_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Theater:
	{
		DrawGraph(243, 463, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_3_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Bath:
	{
		DrawGraph(243, 548, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_4_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Dining:
	{
		DrawGraph(243, 633, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_5_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Newspaper:
	{
		DrawGraph(243, 718, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_6_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Weapon:
	{
		DrawGraph(243, 803, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_7_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Armor:
	{
		DrawGraph(243, 335, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_8_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Church:
	{
		DrawGraph(243, 420, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_9_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Rifle:
	{
		DrawGraph(243, 505, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_10_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Sword:
	{
		DrawGraph(243, 590, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_11_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Training:
	{
		DrawGraph(243, 675, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_12_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Atelier:
	{
		DrawGraph(243, 760, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_13_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	case MENU_NUM::Library:
	{
		DrawGraph(243, 845, g_0GrHandle, TRUE);
		DrawGraph(1035, 255, g_2_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(1435, 825, setGrHandle, TRUE);
		break;
	}
	}
	switch (nowSelectedPattern)
	{
	case MENU_NUM::Set:
	{
		if (oldpattern == MENU_NUM::Guild)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�M���h�𑝐݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Bar)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "��������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Theater)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "����������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Bath)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�嗁������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Dining)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�H�������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Newspaper)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�V�����s�������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Weapon)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "���퉮�����݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Armor)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�h������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Church)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "��������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Rifle)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�ˌ�������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Sword)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "���p������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Training)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�b�B������݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Atelier)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�A�g���G�����݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Library)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "�}���ق����݂��܂���", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

	}
	}
}


