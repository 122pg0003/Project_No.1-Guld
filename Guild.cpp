#include"Guild.h"
#include"DxLib.h"
#include"SceneMgr.h"
#include"Game.h"
#include"AABB.h"



//コンストラクタ
Guild::Guild(SceneMgr& scenemgr, Game& game) :
	_scenemgr(scenemgr)
	, _game(game) {
	Back = LoadGraph("images/back.png");

	_BIGrHandle = LoadGraph("images/window.png");
	_BuildingSlotGrHandle = LoadGraph("images/building.png");
	_BuildingGrHandle = LoadGraph("images/Guild.png");  //リストのベース
	_ButtonGrHandle = LoadGraph("images/pointer.png");
	_ReturnGrHandle = LoadGraph("images/back.png");

	BaseGrHandle = LoadGraph("images/gb.png");  //施設のボード
	BoardGrHandle = LoadGraph("images/che.png");  //ウィンドウ
	YesGrHandle = LoadGraph("images/yes.png");
	NoGrHandle = LoadGraph("images/no.png");


	upGrHandle = LoadGraph("images/up1.png");  //上矢印
	downGrHandle = LoadGraph("images/down1.png");  //下矢印
	setGrHandle = LoadGraph("images/Installation.2.png");  //設置ボタン
	developmentGrHandle = LoadGraph("images/development.2.png");  //発展ボタン
	deleteGrHandle = LoadGraph("images/delete.2.png");  //削除ボタン
	TotalGrHandle = LoadGraph("images/ginum.png");  //施設数の枠
	g_0GrHandle = LoadGraph("images/gi0.png");  //選択枠

	//1はギルド増設
	g_1_1GrHandle = LoadGraph("images/gi1_1.png");
	g_1_2GrHandle = LoadGraph("images/gi1_2.png");
	g_1_3GrHandle = LoadGraph("images/gi1_3.png");

	//2は酒場
	g_2_0GrHandle = LoadGraph("images/gi2_0.png");
	g_2_1GrHandle = LoadGraph("images/gi2_1.png");
	g_2_2GrHandle = LoadGraph("images/gi2_2.png");
	g_2_3GrHandle = LoadGraph("images/gi2_3.png");

	//3は演劇場
	g_3_0GrHandle = LoadGraph("images/gi3_0.png");
	g_3_1GrHandle = LoadGraph("images/gi3_1.png");
	g_3_2GrHandle = LoadGraph("images/gi3_2.png");
	g_3_3GrHandle = LoadGraph("images/gi3_3.png");

	//4は大浴場
	g_4_0GrHandle = LoadGraph("images/gi4_0.png");
	g_4_1GrHandle = LoadGraph("images/gi4_1.png");
	g_4_2GrHandle = LoadGraph("images/gi4_2.png");
	g_4_3GrHandle = LoadGraph("images/gi4_3.png");

	//5は食堂
	g_5_0GrHandle = LoadGraph("images/gi5_0.png");
	g_5_1GrHandle = LoadGraph("images/gi5_1.png");
	g_5_2GrHandle = LoadGraph("images/gi5_2.png");
	g_5_3GrHandle = LoadGraph("images/gi5_3.png");

	//6は新聞発行所
	g_6_0GrHandle = LoadGraph("images/gi6_0.png");
	g_6_1GrHandle = LoadGraph("images/gi6_1.png");
	g_6_2GrHandle = LoadGraph("images/gi6_2.png");
	g_6_3GrHandle = LoadGraph("images/gi6_3.png");

	//7は武器屋
	g_7_0GrHandle = LoadGraph("images/gi7_0.png");
	g_7_1GrHandle = LoadGraph("images/gi7_1.png");
	g_7_2GrHandle = LoadGraph("images/gi7_2.png");
	g_7_3GrHandle = LoadGraph("images/gi7_3.png");

	//8は防具屋
	g_8_0GrHandle = LoadGraph("images/gi8_0.png");
	g_8_1GrHandle = LoadGraph("images/gi8_1.png");
	g_8_2GrHandle = LoadGraph("images/gi8_2.png");
	g_8_3GrHandle = LoadGraph("images/gi8_3.png");

	//9は教会
	g_9_0GrHandle = LoadGraph("images/gi9_0.png");
	g_9_1GrHandle = LoadGraph("images/gi9_1.png");
	g_9_2GrHandle = LoadGraph("images/gi9_2.png");
	g_9_3GrHandle = LoadGraph("images/gi9_3.png");

	//10は射撃場
	g_10_0GrHandle = LoadGraph("images/gi10_0.png");
	g_10_1GrHandle = LoadGraph("images/gi10_1.png");
	g_10_2GrHandle = LoadGraph("images/gi10_2.png");
	g_10_3GrHandle = LoadGraph("images/gi10_3.png");

	//11は剣術場
	g_11_0GrHandle = LoadGraph("images/gi11_0.png");
	g_11_1GrHandle = LoadGraph("images/gi11_1.png");
	g_11_2GrHandle = LoadGraph("images/gi11_2.png");
	g_11_3GrHandle = LoadGraph("images/gi11_3.png");

	//12は鍛錬場
	g_12_0GrHandle = LoadGraph("images/gi12_0.png");
	g_12_1GrHandle = LoadGraph("images/gi12_1.png");
	g_12_2GrHandle = LoadGraph("images/gi12_2.png");
	g_12_3GrHandle = LoadGraph("images/gi12_3.png");

	//13はアトリエ
	g_13_0GrHandle = LoadGraph("images/gi13_0.png");
	g_13_1GrHandle = LoadGraph("images/gi13_1.png");
	g_13_2GrHandle = LoadGraph("images/gi13_2.png");
	g_13_3GrHandle = LoadGraph("images/gi13_3.png");

	//14は図書館
	g_14_0GrHandle = LoadGraph("images/gi14_0.png");
	g_14_1GrHandle = LoadGraph("images/gi14_1.png");
	g_14_2GrHandle = LoadGraph("images/gi14_2.png");
	g_14_3GrHandle = LoadGraph("images/gi14_3.png");

	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Up, upGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Down, downGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Guild, g_1_1GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Bar, g_2_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Theater, g_3_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Bath, g_4_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Dining, g_5_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Newspaper, g_6_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Weapon, g_7_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Armor, g_8_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Church, g_9_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Rifle, g_10_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Sword, g_11_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Training, g_12_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Atelier, g_13_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Library, g_14_0GrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Set, setGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Development, developmentGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Delete, deleteGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Back, Back);

	GuildLv = 11;
	BarLv = 20;
	TheaterLv = 30;
	BathLv = 40;
	DiningLv = 50;
	NewspaperLv = 60;
	WeaponLv = 70;
	ArmorLv = 80;
	ChurchLv = 90;
	RifleLv = 100;
	SwordLv = 110;
	TrainingLv = 120;
	AtelierLv = 130;
	LibraryLv = 140;



	MaxBuilding = 3;
	TotalBuilding = 0;


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

		max_x = 1900;
		min_x = 1750;
		max_y = 1050;
		min_y = 190;

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

		max_x = 1710;
		min_x = 1560;
		max_y = 386;
		min_y = 236;

		break;
	case MENU_NUM::Development:
		max_x = 1710;
		min_x = 1560;
		max_y = 567;
		min_y = 417;

		break;
	case MENU_NUM::Delete:
		max_x = 1710;
		min_x = 1560;
		max_y = 748;
		min_y = 598;

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
		AABBDraw::LOAD_NUM::Back,  
		};
		MENU_NUM pat[] = {
		MENU_NUM::Up,
		MENU_NUM::Down,
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
		MENU_NUM::Back,  //図書館
		};

		for (auto i = 0; i < 15; ++i) {
			int handle = AABBDraw::GetHandle(load[i]);

			if (touch->Handle == handle && (_game._mousetrg & MOUSE_INPUT_LEFT)) {
				pattern = pat[i];
				oldpattern = pat[i];
				break;
			}

		}
	}

	GetMenuPosition(MENU_NUM::Development, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg & MOUSE_INPUT_LEFT) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		pattern = MENU_NUM::Development;
	}

	GetMenuPosition(MENU_NUM::Delete, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg & MOUSE_INPUT_LEFT) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		pattern = MENU_NUM::Delete;
	}

	GetMenuPosition(MENU_NUM::Set, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg & MOUSE_INPUT_LEFT) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		pattern = MENU_NUM::Set;
	}
	
}

void Guild::Guild_Update() {
	switch (pattern)
	{
	case MENU_NUM::Up:
	{
		ScreenNo -= 1;
		pattern = MENU_NUM::GuildMenu;
		break;
	}
	case MENU_NUM::Down:
	{
		ScreenNo += 1;
		pattern = MENU_NUM::GuildMenu;
		break;
	}
	case MENU_NUM::Guild:
	{
		break;
	}
	case MENU_NUM::Bar:
	{
		break;
	}
	case MENU_NUM::Theater:
	{
		break;
	}
	case MENU_NUM::Bath:
	{
		break;
	}
	case MENU_NUM::Dining:
	{
		break;
	}
	case MENU_NUM::Newspaper:
	{
		break;
	}
	case MENU_NUM::Weapon:
	{
		break;
	}
	case MENU_NUM::Armor:
	{
		break;
	}
	case MENU_NUM::Church:
	{
		break;
	}
	case MENU_NUM::Rifle:
	{
		break;
	}
	case MENU_NUM::Sword:
	{
		break;
	}
	case MENU_NUM::Training:
	{
		break;
	}
	case MENU_NUM::Atelier:
	{
		break;
	}
	case MENU_NUM::Library:
	{
		break;
	}
	case MENU_NUM::Set:
	{
		if ((oldpattern == MENU_NUM::Guild) && GuildLv < 13)
		{
			if (GuildLv == 11) {
				MaxBuilding += 2;
			}
			if (GuildLv == 12) {
				MaxBuilding += 3;
			}
			BuiltType = MENU_NUM::Guild;
			Set(GuildLv);
			GuildLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		if (TotalBuilding == MaxBuilding) {
			break;
		}
		if ((oldpattern == MENU_NUM::Bar) && BarLv == 20) {
			BuiltType = MENU_NUM::Bar;
			Set(BarLv);
			BarLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Bar) && BarLv < 23)
		{
			BuiltType = MENU_NUM::Bar;
			Set(BarLv);
			BarLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Theater) && TheaterLv == 30) {
			BuiltType = MENU_NUM::Theater;
			Set(TheaterLv);
			TheaterLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Theater) && TheaterLv < 33)
		{
			BuiltType = MENU_NUM::Theater;
			Set(TheaterLv);
			TheaterLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Bath) && BathLv == 40) {
			BuiltType = MENU_NUM::Bath;
			Set(BathLv);
			BathLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Bath) && BathLv < 43)
		{
			BuiltType = MENU_NUM::Bath;
			Set(BathLv);
			BathLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Dining) && DiningLv == 50) {
			BuiltType = MENU_NUM::Dining;
			Set(DiningLv);
			DiningLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Dining) && DiningLv < 53)
		{
			BuiltType = MENU_NUM::Dining;
			Set(DiningLv);
			DiningLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Newspaper) && NewspaperLv == 60) {
			BuiltType = MENU_NUM::Newspaper;
			Set(NewspaperLv);
			NewspaperLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Newspaper) && NewspaperLv < 63)
		{
			BuiltType = MENU_NUM::Newspaper;
			Set(NewspaperLv);
			NewspaperLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Weapon) && WeaponLv == 70) {
			BuiltType = MENU_NUM::Weapon;
			Set(WeaponLv);
			WeaponLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Weapon) && WeaponLv < 73)
		{
			BuiltType = MENU_NUM::Weapon;
			Set(WeaponLv);
			WeaponLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Armor) && ArmorLv == 80) {
			BuiltType = MENU_NUM::Armor;
			Set(ArmorLv);
			ArmorLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Armor) && ArmorLv < 83)
		{
			BuiltType = MENU_NUM::Armor;
			Set(ArmorLv);
			ArmorLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Church) && ChurchLv == 90) {
			BuiltType = MENU_NUM::Church;
			Set(ChurchLv);
			ChurchLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Church) && ChurchLv < 93)
		{
			BuiltType = MENU_NUM::Church;
			Set(ChurchLv);
			ChurchLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Rifle) && RifleLv == 100) {
			BuiltType = MENU_NUM::Rifle;
			Set(RifleLv);
			RifleLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Rifle) && RifleLv < 103)
		{
			BuiltType = MENU_NUM::Rifle;
			Set(RifleLv);
			RifleLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Sword) && SwordLv == 110) {
			BuiltType = MENU_NUM::Sword;
			Set(SwordLv);
			SwordLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Sword) && SwordLv < 113)
		{
			BuiltType = MENU_NUM::Sword;
			Set(SwordLv);
			SwordLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Training) && TrainingLv == 120) {
			BuiltType = MENU_NUM::Training;
			Set(TrainingLv);
			TrainingLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Training) && TrainingLv < 123)
		{
			BuiltType = MENU_NUM::Training;
			Set(TrainingLv);
			TrainingLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}

		if ((oldpattern == MENU_NUM::Atelier) && AtelierLv == 130) {
			BuiltType = MENU_NUM::Atelier;

			Set(AtelierLv);
			AtelierLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Atelier) && AtelierLv < 133)
		{
			BuiltType = MENU_NUM::Atelier;
			Set(AtelierLv);
			AtelierLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}


		if ((oldpattern == MENU_NUM::Library) && LibraryLv == 140) {
			BuiltType = MENU_NUM::Library;
			Set(LibraryLv);
			LibraryLv += 1;
			TotalBuilding += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		else if ((oldpattern == MENU_NUM::Library) && LibraryLv < 143)

		{
			BuiltType = MENU_NUM::Library;
			Set(LibraryLv);
			LibraryLv += 1;
			pattern = MENU_NUM::GuildMenu;
		}
		break;
	}
	case MENU_NUM::Development:
	{
		break;
	}


	case MENU_NUM::Delete:
	{
		break;
	}


	}



}

void Guild::Guild_Render() {

	DrawGraph(1750, 900, Back, TRUE);

	DrawFormatString(0, 0, GetColor(0, 0, 0), "pattern=%d", pattern);

	DrawGraph(0, 0, BaseGrHandle, TRUE);
	DrawGraph(1545, 753, TotalGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 236, setGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 417, developmentGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 598, deleteGrHandle, TRUE);

	DrawFormatString(1581, 853, GetColor(0, 0, 0), "%d/%d", TotalBuilding, MaxBuilding);



	if (ScreenNo == 1) {

		AABBDraw::MyDrawGraph(170, 228, g_1_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_2_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_3_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_4_0GrHandle, TRUE);

		if (GuildLv == 11) {
			DrawGraph(170, 228, g_1_1GrHandle, FALSE);
		}
		else if (GuildLv == 12) {
			DrawGraph(170, 228, g_1_2GrHandle, FALSE);
		}
		else if (GuildLv == 13) {
			DrawGraph(170, 228, g_1_3GrHandle, FALSE);
		}

		if (BarLv == 20) {
			DrawGraph(873, 228, g_2_0GrHandle, FALSE);
		}
		else if (BarLv == 21) {
			DrawGraph(873, 228, g_2_1GrHandle, FALSE);
		}
		else if (BarLv == 22) {
			DrawGraph(873, 228, g_2_2GrHandle, FALSE);
		}
		else if (BarLv == 23) {
			DrawGraph(873, 228, g_2_3GrHandle, FALSE);
		}

		if (TheaterLv == 30) {
			DrawGraph(170, 598, g_3_0GrHandle, FALSE);
		}
		else if (TheaterLv == 31) {
			DrawGraph(170, 598, g_3_1GrHandle, FALSE);
		}
		else if (TheaterLv == 32) {
			DrawGraph(170, 598, g_3_2GrHandle, FALSE);
		}
		else if (TheaterLv == 33) {
			DrawGraph(170, 598, g_3_3GrHandle, FALSE);
		}

		if (BathLv == 40) {
			DrawGraph(873, 598, g_4_0GrHandle, FALSE);
		}
		else if (BathLv == 41) {
			DrawGraph(873, 598, g_4_1GrHandle, FALSE);
		}
		else if (BathLv == 42) {
			DrawGraph(873, 598, g_4_2GrHandle, FALSE);
		}
		else if (BathLv == 43) {
			DrawGraph(873, 598, g_4_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 943, downGrHandle, TRUE);
	}

	if (ScreenNo == 2) {

		AABBDraw::MyDrawGraph(170, 228, g_5_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_6_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_7_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_8_0GrHandle, TRUE);

		if (DiningLv == 50) {
			AABBDraw::MyDrawGraph(170, 228, g_5_0GrHandle, FALSE);
		}
		else if (DiningLv == 51) {
			AABBDraw::MyDrawGraph(170, 228, g_5_1GrHandle, FALSE);
		}
		else if (DiningLv == 52) {
			AABBDraw::MyDrawGraph(170, 228, g_5_2GrHandle, FALSE);
		}
		else if (DiningLv == 53) {
			AABBDraw::MyDrawGraph(170, 228, g_5_3GrHandle, FALSE);
		}

		if (NewspaperLv == 60) {
			AABBDraw::MyDrawGraph(873, 228, g_6_0GrHandle, FALSE);
		}
		else if (NewspaperLv == 61) {
			AABBDraw::MyDrawGraph(873, 228, g_6_1GrHandle, FALSE);
		}
		else if (NewspaperLv == 62) {
			AABBDraw::MyDrawGraph(873, 228, g_6_2GrHandle, FALSE);
		}
		else if (NewspaperLv == 63) {
			AABBDraw::MyDrawGraph(873, 228, g_6_3GrHandle, FALSE);
		}

		if (WeaponLv == 70) {
			AABBDraw::MyDrawGraph(170, 598, g_7_0GrHandle, FALSE);
		}
		else if (WeaponLv == 71) {
			AABBDraw::MyDrawGraph(170, 598, g_7_1GrHandle, FALSE);
		}
		else if (WeaponLv == 72) {
			AABBDraw::MyDrawGraph(170, 598, g_7_2GrHandle, FALSE);
		}
		else if (WeaponLv == 73) {
			AABBDraw::MyDrawGraph(170, 598, g_7_3GrHandle, FALSE);
		}

		if (ArmorLv == 80) {
			AABBDraw::MyDrawGraph(873, 598, g_8_0GrHandle, FALSE);
		}
		else if (ArmorLv == 81) {
			AABBDraw::MyDrawGraph(873, 598, g_8_1GrHandle, FALSE);
		}
		else if (ArmorLv == 82) {
			AABBDraw::MyDrawGraph(873, 598, g_8_2GrHandle, FALSE);
		}
		else if (ArmorLv == 83) {
			AABBDraw::MyDrawGraph(873, 598, g_8_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 121, upGrHandle, TRUE);
		AABBDraw::MyDrawGraph(802, 943, downGrHandle, TRUE);
	}

	if (ScreenNo == 3) {

		AABBDraw::MyDrawGraph(170, 228, g_9_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_10_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_11_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_12_0GrHandle, TRUE);

		if (ChurchLv == 90) {
			AABBDraw::MyDrawGraph(170, 228, g_9_0GrHandle, FALSE);
		}
		else if (ChurchLv == 91) {
			AABBDraw::MyDrawGraph(170, 228, g_9_1GrHandle, FALSE);
		}
		else if (ChurchLv == 92) {
			AABBDraw::MyDrawGraph(170, 228, g_9_2GrHandle, FALSE);
		}
		else if (ChurchLv == 93) {
			AABBDraw::MyDrawGraph(170, 228, g_9_3GrHandle, FALSE);
		}

		if (RifleLv == 100) {
			AABBDraw::MyDrawGraph(873, 228, g_10_0GrHandle, FALSE);
		}
		else if (RifleLv == 101) {
			AABBDraw::MyDrawGraph(873, 228, g_10_1GrHandle, FALSE);
		}
		else if (RifleLv == 102) {
			AABBDraw::MyDrawGraph(873, 228, g_10_2GrHandle, FALSE);
		}
		else if (RifleLv == 103) {
			AABBDraw::MyDrawGraph(873, 228, g_10_3GrHandle, FALSE);
		}

		if (SwordLv == 110) {
			AABBDraw::MyDrawGraph(170, 598, g_11_0GrHandle, FALSE);
		}
		else if (SwordLv == 111) {
			AABBDraw::MyDrawGraph(170, 598, g_11_1GrHandle, FALSE);
		}
		else if (SwordLv == 112) {
			AABBDraw::MyDrawGraph(170, 598, g_11_2GrHandle, FALSE);
		}
		else if (SwordLv == 113) {
			AABBDraw::MyDrawGraph(170, 598, g_11_3GrHandle, FALSE);
		}

		if (TrainingLv == 120) {
			AABBDraw::MyDrawGraph(873, 598, g_12_0GrHandle, FALSE);
		}
		else if (TrainingLv == 121) {
			AABBDraw::MyDrawGraph(873, 598, g_12_1GrHandle, FALSE);
		}
		else if (TrainingLv == 122) {
			AABBDraw::MyDrawGraph(873, 598, g_12_2GrHandle, FALSE);
		}
		else if (TrainingLv == 123) {
			AABBDraw::MyDrawGraph(873, 598, g_12_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 121, upGrHandle, TRUE);
		AABBDraw::MyDrawGraph(802, 943, downGrHandle, TRUE);
	}

	if (ScreenNo == 4) {

		AABBDraw::MyDrawGraph(170, 598, g_13_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_14_0GrHandle, TRUE);

		if (AtelierLv == 130) {
			AABBDraw::MyDrawGraph(170, 228, g_13_0GrHandle, FALSE);
		}
		else if (AtelierLv == 131) {
			AABBDraw::MyDrawGraph(170, 228, g_13_1GrHandle, FALSE);
		}
		else if (AtelierLv == 132) {
			AABBDraw::MyDrawGraph(170, 228, g_13_2GrHandle, FALSE);
		}
		else if (AtelierLv == 133) {
			AABBDraw::MyDrawGraph(170, 228, g_13_3GrHandle, FALSE);
		}

		if (LibraryLv == 140) {
			AABBDraw::MyDrawGraph(873, 228, g_14_0GrHandle, FALSE);
		}
		else if (LibraryLv == 141) {
			AABBDraw::MyDrawGraph(873, 228, g_14_1GrHandle, FALSE);
		}
		else if (LibraryLv == 142) {
			AABBDraw::MyDrawGraph(873, 228, g_14_2GrHandle, FALSE);
		}
		else if (LibraryLv == 143) {
			AABBDraw::MyDrawGraph(873, 228, g_14_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 121, upGrHandle, TRUE);
	}

	switch (pattern)
	{
	case MENU_NUM::Set:
	{
		DrawGraph(377, 340, BoardGrHandle, TRUE);
		if (TotalBuilding == MaxBuilding) {
			DrawGraph(507, 625, YesGrHandle, TRUE);
			DrawGraph(507, 625, YesGrHandle, TRUE);
			DrawString(550, 400, "施設上限です。", GetColor(0, 0, 0));
			break;
		}
	}
	case MENU_NUM::GuildMenu:
	{

		if (TotalBuilding == MaxBuilding) {
			DrawString(550, 400, "施設上限です。", GetColor(0, 0, 0));
			break;
		}

		if (BuiltType == MENU_NUM::Guild)
		{
			DrawString(1055, 240, "ギルドを増設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Bar && BarLv > 21)
		{
			DrawString(1055, 240, "酒場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Bar)
		{
			DrawString(1055, 240, "酒場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Theater && TheaterLv > 31)
		{
			DrawString(1055, 240, "演劇場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Theater)
		{
			DrawString(1055, 240, "演劇場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Bath && BathLv > 41)
		{
			DrawString(1055, 240, "大浴場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Bath)
		{
			DrawString(1055, 240, "大浴場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Dining && DiningLv > 51)
		{
			DrawString(1055, 240, "食堂を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Dining)
		{
			DrawString(1055, 240, "食堂を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Newspaper && NewspaperLv > 61)
		{
			DrawString(1055, 240, "新聞発行所を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Newspaper)
		{
			DrawString(1055, 240, "新聞発行所を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Weapon && WeaponLv > 71)
		{
			DrawString(1055, 240, "武器屋を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Weapon)
		{
			DrawString(1055, 240, "武器屋を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Armor && ArmorLv > 81)
		{
			DrawString(1055, 240, "防具屋を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Armor)
		{
			DrawString(1055, 240, "防具屋を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Church && ChurchLv > 91)
		{
			DrawString(1055, 240, "教会を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Church)
		{
			DrawString(1055, 240, "教会を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Rifle && RifleLv > 101)
		{
			DrawString(1055, 240, "射撃場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Rifle)
		{
			DrawString(1055, 240, "射撃場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Sword && SwordLv > 111)
		{
			DrawString(1055, 240, "剣術場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Sword)
		{
			DrawString(1055, 240, "剣術場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Training && TrainingLv > 121)
		{
			DrawString(1055, 240, "鍛錬場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Training)
		{
			DrawString(1055, 240, "鍛錬場を建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Atelier && AtelierLv > 131)
		{
			DrawString(1055, 240, "アトリエを増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Atelier)
		{
			DrawString(1055, 240, "アトリエを建設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Library && LibraryLv > 141)
		{
			DrawString(1055, 240, "図書館を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Library)
		{
			DrawString(1055, 240, "図書館を建設しました", GetColor(0, 0, 0));
		}
	}
	break;

	case MENU_NUM::Development:
	{
		DrawGraph(480, 340, BoardGrHandle, TRUE);
		break;
	}
	break;

	case MENU_NUM::Delete:
	{
		DrawGraph(480, 340, BoardGrHandle, TRUE);
		break;
	}


	case MENU_NUM::Guild:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Bar:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Theater:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Bath:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Dining:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Newspaper:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Weapon:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Armor:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Church:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Rifle:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Sword:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Training:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Atelier:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Library:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	}
}


