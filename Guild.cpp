#include"Guild.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"AABB.h"

//コンストラクタ
Guild::Guild(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	_BIGrHandle = LoadGraph("images/window.png");
	_BuildingSlotGrHandle = LoadGraph("images/building.png");
	_BuildingGrHandle = LoadGraph("images/Guild.png");  //リストのベース
	_ButtonGrHandle = LoadGraph("images/pointer.png");

	upGrHandle = LoadGraph("images/up.png");  //上矢印
	downGrHandle = LoadGraph("images/down.png");  //下矢印
	setGrHandle = LoadGraph("images/g_set.png");  //設置ボタン
	g_0GrHandle = LoadGraph("images/g_0.png");  //選択枠

	g_1GrHandle = LoadGraph("images/g_1.png");  //1はギルド増設
	g_1_1GrHandle = LoadGraph("images/G_1_1.png");
	g_1_2GrHandle = LoadGraph("images/G_1_2.png");
	g_1_3GrHandle = LoadGraph("images/G_1_3.png");

	g_2GrHandle = LoadGraph("images/g_2.png");  //2は酒場
	g_2_1GrHandle = LoadGraph("images/G_2_1.png");
	g_2_2GrHandle = LoadGraph("images/G_2_2.png");
	g_2_3GrHandle = LoadGraph("images/G_2_3.png");

	g_3GrHandle = LoadGraph("images/g_3.png");  //3は演劇場
	g_3_1GrHandle = LoadGraph("images/G_3_1.png");
	g_3_2GrHandle = LoadGraph("images/G_3_2.png");
	g_3_3GrHandle = LoadGraph("images/G_3_3.png");

	g_4GrHandle = LoadGraph("images/g_4.png");  //4は大浴場
	g_4_1GrHandle = LoadGraph("images/G_4_1.png");
	g_4_2GrHandle = LoadGraph("images/G_4_2.png");
	g_4_3GrHandle = LoadGraph("images/G_4_3.png");

	g_5GrHandle = LoadGraph("images/g_5.png");  //5は食堂
	g_5_1GrHandle = LoadGraph("images/G_5_1.png");
	g_5_2GrHandle = LoadGraph("images/G_5_2.png");
	g_5_3GrHandle = LoadGraph("images/G_5_3.png");

	g_6GrHandle = LoadGraph("images/g_6.png");  //6は新聞発行所
	g_6_1GrHandle = LoadGraph("images/G_6_1.png");
	g_6_2GrHandle = LoadGraph("images/G_6_2.png");
	g_6_3GrHandle = LoadGraph("images/G_6_3.png");

	g_7GrHandle = LoadGraph("images/g_7.png");  //7は武器屋　ここまで1ページ目
	g_7_1GrHandle = LoadGraph("images/G_7_1.png");
	g_7_2GrHandle = LoadGraph("images/G_7_2.png");
	g_7_3GrHandle = LoadGraph("images/G_7_3.png");

	g_8GrHandle = LoadGraph("images/g_8.png");  //8は防具屋
	g_8_1GrHandle = LoadGraph("images/G_8_1.png");
	g_8_2GrHandle = LoadGraph("images/G_8_2.png");
	g_8_3GrHandle = LoadGraph("images/G_8_3.png");

	g_9GrHandle = LoadGraph("images/g_9.png");  //9は教会
	g_9_1GrHandle = LoadGraph("images/G_9_1.png");
	g_9_2GrHandle = LoadGraph("images/G_9_2.png");
	g_9_3GrHandle = LoadGraph("images/G_9_3.png");

	g_10GrHandle = LoadGraph("images/g_10.png");  //10は射撃場
	g_10_1GrHandle = LoadGraph("images/G_10_1.png");
	g_10_2GrHandle = LoadGraph("images/G_10_2.png");
	g_10_3GrHandle = LoadGraph("images/G_10_3.png");

	g_11GrHandle = LoadGraph("images/g_11.png");  //11は剣術場
	g_11_1GrHandle = LoadGraph("images/G_11_1.png");
	g_11_2GrHandle = LoadGraph("images/G_11_2.png");
	g_11_3GrHandle = LoadGraph("images/G_11_3.png");

	g_12GrHandle = LoadGraph("images/g_12.png");  //12は鍛錬場
	g_12_1GrHandle = LoadGraph("images/G_12_1.png");
	g_12_2GrHandle = LoadGraph("images/G_12_2.png");
	g_12_3GrHandle = LoadGraph("images/G_12_3.png");

	g_13GrHandle = LoadGraph("images/g_13.png");  //13はアトリエ
	g_13_1GrHandle = LoadGraph("images/G_13_1.png");
	g_13_2GrHandle = LoadGraph("images/G_13_2.png");
	g_13_3GrHandle = LoadGraph("images/G_13_3.png");

	g_14GrHandle = LoadGraph("images/g_14.png");  //14は図書館
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

//デストラクタ
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
	//右上のBOXをクリックするとホームに戻る
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
		//AABBDraw::LOAD_NUM::Set,  //建設
		AABBDraw::LOAD_NUM::Guild,  //ギルド拡張
		AABBDraw::LOAD_NUM::Bar,  //酒場
		AABBDraw::LOAD_NUM::Theater,  //演劇場
		AABBDraw::LOAD_NUM::Bath,  //大浴場
		AABBDraw::LOAD_NUM::Dining,  //食堂
		AABBDraw::LOAD_NUM::Newspaper,  //新聞発行所
		AABBDraw::LOAD_NUM::Weapon,  //武器屋
		AABBDraw::LOAD_NUM::Armor,  //防具屋
		AABBDraw::LOAD_NUM::Church,  //教会
		AABBDraw::LOAD_NUM::Rifle,  //射撃場
		AABBDraw::LOAD_NUM::Sword,  //剣術場
		AABBDraw::LOAD_NUM::Training,  //鍛錬場
		AABBDraw::LOAD_NUM::Atelier,  //アトリエ
		AABBDraw::LOAD_NUM::Library,  //図書館
		};
		MENU_NUM pat[] = {
		MENU_NUM::Up,
		MENU_NUM::Down,
		//MENU_NUM::Set,  //建設
		MENU_NUM::Guild,  //ギルド拡張
		MENU_NUM::Bar,  //酒場
		MENU_NUM::Theater,  //演劇場
		MENU_NUM::Bath,  //大浴場
		MENU_NUM::Dining,  //食堂
		MENU_NUM::Newspaper,  //新聞発行所
		MENU_NUM::Weapon,  //武器屋
		MENU_NUM::Armor,  //防具屋
		MENU_NUM::Church,  //教会
		MENU_NUM::Rifle,  //射撃場
		MENU_NUM::Sword,  //剣術場
		MENU_NUM::Training,  //鍛錬場
		MENU_NUM::Atelier,  //アトリエ
		MENU_NUM::Library,  //図書館
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

	//矢印をクリックするとページが切り替わる
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
		DrawGraph(135, 185, _BIGrHandle, TRUE);  //画像サイズ　幅1650、高さ850
		DrawGraph(205, 255, _BuildingGrHandle, TRUE);  //画像サイズ　幅680、高さ710

		AABBDraw::MyDrawGraph(243, 293, g_1GrHandle, TRUE);  //ギルド増設スロット
		AABBDraw::MyDrawGraph(243, 378, g_2GrHandle, TRUE);  //酒場
		AABBDraw::MyDrawGraph(243, 463, g_3GrHandle, TRUE);  //演劇場
		AABBDraw::MyDrawGraph(243, 548, g_4GrHandle, TRUE);  //大浴場
		AABBDraw::MyDrawGraph(243, 633, g_5GrHandle, TRUE);  //食堂
		AABBDraw::MyDrawGraph(243, 718, g_6GrHandle, TRUE);  //新聞発行所
		AABBDraw::MyDrawGraph(243, 803, g_7GrHandle, TRUE);  //武器屋

		AABBDraw::MyDrawGraph(505, 888, downGrHandle, TRUE);  //下矢印

		DrawBox(1800, 45, 1850, 90, GetColor(255, 0, 0), TRUE);
	}

	if (ScreenNo == 2) {
		DrawGraph(135, 185, _BIGrHandle, TRUE);  //画像サイズ　幅1650、高さ850
		DrawGraph(205, 255, _BuildingGrHandle, TRUE);  //画像サイズ　幅680、高さ710

		AABBDraw::MyDrawGraph(243, 335, g_8GrHandle, TRUE);  //ギルド増設スロット
		AABBDraw::MyDrawGraph(243, 420, g_9GrHandle, TRUE);  //防具屋
		AABBDraw::MyDrawGraph(243, 505, g_10GrHandle, TRUE);  //教会
		AABBDraw::MyDrawGraph(243, 590, g_11GrHandle, TRUE);  //射撃場
		AABBDraw::MyDrawGraph(243, 675, g_12GrHandle, TRUE);  //剣術場
		AABBDraw::MyDrawGraph(243, 760, g_13GrHandle, TRUE);  //アトリエ
		AABBDraw::MyDrawGraph(243, 845, g_14GrHandle, TRUE);  //図書館

		AABBDraw::MyDrawGraph(505, 260, upGrHandle, TRUE);  //上矢印

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
			DrawString(1055, 240, "ギルドを増設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Bar)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "酒場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Theater)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "演劇場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Bath)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "大浴場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Dining)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "食堂を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Newspaper)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "新聞発行所を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Weapon)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "武器屋を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Armor)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "防具屋を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Church)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "教会を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Rifle)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "射撃場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Sword)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "剣術場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Training)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "鍛錬場を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Atelier)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "アトリエを建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

		if (oldpattern == MENU_NUM::Library)
		{
			pattern = MENU_NUM::GuildMenu;
			DrawString(1055, 240, "図書館を建設しました", GetColor(0, 0, 0));
			nowSelectedPattern = MENU_NUM::GuildMenu;
		}

	}
	}
}


