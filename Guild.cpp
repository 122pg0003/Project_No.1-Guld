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
	_ReturnGrHandle = LoadGraph("images/back.png");

	BaseGrHandle = LoadGraph("images/gb.png");  //施設のボード
	BoardGrHandle = LoadGraph("images/che.png");  //ウィンドウ
	YesGrHandle = LoadGraph("images/yes.png");


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
	g_13_0GrHandle = LoadGraph("images/gi14_0.png");
	g_13_1GrHandle = LoadGraph("images/gi14_1.png");
	g_13_2GrHandle = LoadGraph("images/gi14_2.png");
	g_13_3GrHandle = LoadGraph("images/gi14_3.png");

	//14は図書館
	g_14_0GrHandle = LoadGraph("images/gi13_0.png");
	g_14_1GrHandle = LoadGraph("images/gi13_1.png");
	g_14_2GrHandle = LoadGraph("images/gi13_2.png");
	g_14_3GrHandle = LoadGraph("images/gi13_3.png");

	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Yes, YesGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Up, upGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Down, downGrHandle);
	AABBDraw::SetHandle(AABBDraw::LOAD_NUM::Guild, g_1_1GrHandle);
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

	GuildLv = 11;
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

	MaxBuildFlag = false;
	MoneyFlag = false;
	DeleteFlag = false;

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

		max_x = 1920;
		min_x = 1770;
		max_y = 195;
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
	case MENU_NUM::Yes:
		max_x = 967;
		min_x = 707;
		max_y = 700;
		min_y = 625;
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
		MENU_NUM::Guild,  //ギルド拡張
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

		if (_game._mousetrg != 0) {
			std::shared_ptr<AABBInfo> Touch = AABBDraw::GetTouch();

			if (Touch != nullptr) {
				AABBDraw::LOAD_NUM Type = AABBDraw::GetType(Touch->Handle);

				for (auto i = 0; i < 14; ++i) {
					if (load[i] == Type) {
						//oldpattern = pattern;
						pattern = pat[i];
						oldpattern = pat[i];
						break;
					}
				}
			}
		}
	}

	GetMenuPosition(MENU_NUM::Development, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//oldpattern = pattern;
		pattern = MENU_NUM::Development;
	}

	GetMenuPosition(MENU_NUM::Delete, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//oldpattern = pattern;
		pattern = MENU_NUM::Delete;
	}

	GetMenuPosition(MENU_NUM::Set, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//oldpattern = pattern;
		pattern = MENU_NUM::Set;
	}
	GetMenuPosition(MENU_NUM::Yes, max_x, min_x, max_y, min_y);
	if ((_game._mousetrg != 0) &&
		((_game.GetMouseX() < max_x) &&
			(_game.GetMouseX() > min_x)) &&
		(_game.GetMouseY() < max_y) &&
		(_game.GetMouseY() > min_y)) {
		//oldpattern = pattern;
		pattern = MENU_NUM::GuildMenu;
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
	case MENU_NUM::GuildMenu:
	{
		BuiltType = MENU_NUM::Null;
		pattern = MENU_NUM::Null;
		oldpattern = MENU_NUM::Null;
		MoneyFlag = false;
		break;
	}
	case MENU_NUM::Guild:
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
		if (_game._mousetrg != 0) {
			if (TotalBuilding == MaxBuilding) {
				MaxBuildFlag = true;
				break;
			}
			if (oldpattern == MENU_NUM::Guild)
			{
				BuiltType = MENU_NUM::Guild;
				oldpattern = MENU_NUM::Null;
				break;
			}

			if (oldpattern == MENU_NUM::Bath) {
				int money = GetBuildingMoney(oldpattern);

				if (BathLv == 40 && math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Bath;
					math.Set(BathLv);
					BathLv += 1;
					TotalBuilding += 1;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Dining) && DiningLv == 50) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Dining;
					math.Set(DiningLv);
					DiningLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Newspaper) && NewspaperLv == 60) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Newspaper;
					math.Set(NewspaperLv);
					NewspaperLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Weapon) && WeaponLv == 70) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Weapon;
					math.Set(WeaponLv);
					WeaponLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Armor) && ArmorLv == 80) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Armor;
					math.Set(ArmorLv);
					ArmorLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Church) && ChurchLv == 90) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Church;
					math.Set(ChurchLv);
					ChurchLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}


			if ((oldpattern == MENU_NUM::Rifle) && RifleLv == 100) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Rifle;
					math.Set(RifleLv);
					RifleLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}


			if ((oldpattern == MENU_NUM::Sword) && SwordLv == 110) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Sword;
					math.Set(SwordLv);
					SwordLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
				}
			}

			if ((oldpattern == MENU_NUM::Training) && TrainingLv == 120) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Training;
					math.Set(TrainingLv);
					TrainingLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}

			if ((oldpattern == MENU_NUM::Atelier) && AtelierLv == 130) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Atelier;

					math.Set(AtelierLv);
					AtelierLv += 1;
					TotalBuilding += 1;
					MoneyFlag = false;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}


			if ((oldpattern == MENU_NUM::Library) && LibraryLv == 140) {
				int money = GetBuildingMoney(oldpattern);
				if (math.GetMymoney() >= money) {
					BuiltType = MENU_NUM::Library;
					math.Set(LibraryLv);
					LibraryLv += 1;
					TotalBuilding += 1;
					oldpattern = MENU_NUM::Null;
					DeleteFlag = true;
					MoneyFlag = false;
				}
				else {
					MoneyFlag = true;
					oldpattern = MENU_NUM::Null;
				}
			}
		}
		break;
	}
	case MENU_NUM::Development:
	{
		if ((oldpattern == MENU_NUM::Guild) && GuildLv < 13)
		{
			int money = GetBuildingMoney(oldpattern);
			if (GuildLv == 11 && math.GetMymoney() >= money) {
				MaxBuilding += 2;
				MaxBuildFlag = false;
				MoneyFlag = false;
			}
			else if (GuildLv == 12 && math.GetMymoney() >= money) {
				MaxBuilding += 3;
				MaxBuildFlag = false;
				MoneyFlag = false;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
			BuiltType = MENU_NUM::Guild;
			math.Set(GuildLv);
			GuildLv += 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Bath) && BathLv < 43 && BathLv != 40)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Bath;
				math.Set(BathLv);
				BathLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Dining) && DiningLv < 53 && DiningLv != 50)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Dining;
				math.Set(DiningLv);
				DiningLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Newspaper) && NewspaperLv < 63 && NewspaperLv != 60)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Newspaper;
				math.Set(NewspaperLv);
				NewspaperLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Weapon) && WeaponLv < 73 && WeaponLv != 70)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Weapon;
				math.Set(WeaponLv);
				WeaponLv += 1;
				math.WeaponEffect(WeaponLv);
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Armor) && ArmorLv < 83 && ArmorLv != 80)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Armor;
				math.Set(ArmorLv);
				ArmorLv += 1;
				math.ArmorEffect(ArmorLv);
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Church) && ChurchLv < 93 && ChurchLv != 90)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Church;
				math.Set(ChurchLv);
				ChurchLv += 1;
				math.ChurchEffect(ChurchLv);
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Rifle) && RifleLv < 103 && RifleLv != 100)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Rifle;
				math.Set(RifleLv);
				RifleLv += 1;
				math.RifleEffect(RifleLv);
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Sword) && SwordLv < 113 && SwordLv != 110)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Sword;
				math.Set(SwordLv);
				SwordLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Training) && TrainingLv < 123 && TrainingLv != 120)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Training;
				math.Set(TrainingLv);
				TrainingLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Atelier) && AtelierLv < 133 && AtelierLv != 130)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Atelier;
				math.Set(AtelierLv);
				AtelierLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		if ((oldpattern == MENU_NUM::Library) && LibraryLv < 143 && LibraryLv != 140)
		{
			int money = GetBuildingMoney(oldpattern);
			if (math.GetMymoney() >= money) {
				BuiltType = MENU_NUM::Library;
				math.Set(LibraryLv);
				LibraryLv += 1;
				oldpattern = MENU_NUM::Null;
				MoneyFlag = false;
				DeleteFlag = true;
			}
			else if (math.GetMymoney() < money) {
				MoneyFlag = true;
				break;
			}
		}
		break;
	}


	case MENU_NUM::Delete:
	{
		if (oldpattern == MENU_NUM::Guild)
		{
			BuiltType = MENU_NUM::Guild;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Bath) && BathLv < 44)
		{
			if (BathLv == 40) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Bath;
			BathLv = 40;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Dining) && DiningLv < 54)
		{
			if (DiningLv == 50) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Dining;
			DiningLv = 50;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Newspaper) && NewspaperLv < 64)
		{
			if (NewspaperLv == 60) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Newspaper;
			NewspaperLv = 60;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Weapon) && WeaponLv < 74)
		{
			if (WeaponLv == 70) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Weapon;
			math.WeaponDelete(WeaponLv);
			WeaponLv = 70;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Armor) && ArmorLv < 84)
		{
			if (ArmorLv == 80) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Armor;
			math.ArmorDelete(ArmorLv);
			ArmorLv = 80;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Church) && ChurchLv < 94)
		{
			if (ChurchLv == 90) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Church;
			math.ChurchDelete(ChurchLv);
			ChurchLv = 90;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Rifle) && RifleLv < 104)
		{
			if (RifleLv == 100) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Rifle;
			math.RifleDelete(RifleLv);
			RifleLv = 100;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Sword) && SwordLv < 114)
		{
			if (SwordLv == 110) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Sword;
			SwordLv = 110;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Training) && TrainingLv < 124)
		{
			if (TrainingLv == 120) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Training;
			TrainingLv = 120;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Atelier) && AtelierLv < 134)
		{
			if (AtelierLv == 130) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Atelier;
			math.Set(AtelierLv);
			AtelierLv = 130;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		if ((oldpattern == MENU_NUM::Library) && LibraryLv < 144)
		{
			if (LibraryLv == 140) {
				DeleteFlag = false;
				break;
			}
			BuiltType = MENU_NUM::Library;
			LibraryLv = 140;
			TotalBuilding -= 1;
			oldpattern = MENU_NUM::Null;
		}
		break;
	}
	}
}

void Guild::Guild_Render() {

	DrawFormatString(0, 0, GetColor(0, 0, 0), "pattern=%d", pattern);
	DrawFormatString(0, 100, GetColor(0, 0, 0), "oldpattern=%d", oldpattern);

	DrawGraph(0, 0, BaseGrHandle, TRUE);
	DrawGraph(1545, 753, TotalGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 236, setGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 417, developmentGrHandle, TRUE);
	AABBDraw::MyDrawGraph(1560, 598, deleteGrHandle, TRUE);

	DrawFormatString(1581, 853, GetColor(0, 0, 0), "%d/%d", TotalBuilding, MaxBuilding);



	if (ScreenNo == 1) {

		AABBDraw::MyDrawGraph(170, 228, g_1_1GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_4_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_5_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_6_0GrHandle, TRUE);

		if (GuildLv == 11) {
			DrawGraph(170, 228, g_1_1GrHandle, FALSE);
		}
		else if (GuildLv == 12) {
			DrawGraph(170, 228, g_1_2GrHandle, FALSE);
		}
		else if (GuildLv == 13) {
			DrawGraph(170, 228, g_1_3GrHandle, FALSE);
		}

		if (BathLv == 40) {
			DrawGraph(873, 228, g_4_0GrHandle, FALSE);
		}
		else if (BathLv == 41) {
			DrawGraph(873, 228, g_4_1GrHandle, FALSE);
		}
		else if (BathLv == 42) {
			DrawGraph(873, 228, g_4_2GrHandle, FALSE);
		}
		else if (BathLv == 43) {
			DrawGraph(873, 228, g_4_3GrHandle, FALSE);
		}

		if (DiningLv == 50) {
			DrawGraph(170, 598, g_5_0GrHandle, FALSE);
		}
		else if (DiningLv == 51) {
			DrawGraph(170, 598, g_5_1GrHandle, FALSE);
		}
		else if (DiningLv == 52) {
			DrawGraph(170, 598, g_5_2GrHandle, FALSE);
		}
		else if (DiningLv == 53) {
			DrawGraph(170, 598, g_5_3GrHandle, FALSE);
		}

		if (NewspaperLv == 60) {
			DrawGraph(873, 598, g_6_0GrHandle, FALSE);
		}
		else if (NewspaperLv == 61) {
			DrawGraph(873, 598, g_6_1GrHandle, FALSE);
		}
		else if (NewspaperLv == 62) {
			DrawGraph(873, 598, g_6_2GrHandle, FALSE);
		}
		else if (NewspaperLv == 63) {
			DrawGraph(873, 598, g_6_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 943, downGrHandle, TRUE);
	}

	if (ScreenNo == 2) {

		AABBDraw::MyDrawGraph(170, 228, g_7_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_8_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_9_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_10_0GrHandle, TRUE);

		if (WeaponLv == 70) {
			DrawGraph(170, 228, g_7_0GrHandle, FALSE);
		}
		else if (WeaponLv == 71) {
			DrawGraph(170, 228, g_7_1GrHandle, FALSE);
		}
		else if (WeaponLv == 72) {
			DrawGraph(170, 228, g_7_2GrHandle, FALSE);
		}
		else if (WeaponLv == 73) {
			DrawGraph(170, 228, g_7_3GrHandle, FALSE);
		}

		if (ArmorLv == 80) {
			DrawGraph(873, 228, g_8_0GrHandle, FALSE);
		}
		else if (ArmorLv == 81) {
			DrawGraph(873, 228, g_8_1GrHandle, FALSE);
		}
		else if (ArmorLv == 82) {
			DrawGraph(873, 228, g_8_2GrHandle, FALSE);
		}
		else if (ArmorLv == 83) {
			DrawGraph(873, 228, g_8_3GrHandle, FALSE);
		}

		if (ChurchLv == 90) {
			DrawGraph(170, 598, g_9_0GrHandle, FALSE);
		}
		else if (ChurchLv == 91) {
			DrawGraph(170, 598, g_9_1GrHandle, FALSE);
		}
		else if (ChurchLv == 92) {
			DrawGraph(170, 598, g_9_2GrHandle, FALSE);
		}
		else if (ChurchLv == 93) {
			DrawGraph(170, 598, g_9_3GrHandle, FALSE);
		}

		if (RifleLv == 100) {
			DrawGraph(873, 598, g_10_0GrHandle, FALSE);
		}
		else if (RifleLv == 101) {
			DrawGraph(873, 598, g_10_1GrHandle, FALSE);
		}
		else if (RifleLv == 102) {
			DrawGraph(873, 598, g_10_2GrHandle, FALSE);
		}
		else if (RifleLv == 103) {
			DrawGraph(873, 598, g_10_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 121, upGrHandle, TRUE);
		AABBDraw::MyDrawGraph(802, 943, downGrHandle, TRUE);
	}

	if (ScreenNo == 3) {

		AABBDraw::MyDrawGraph(170, 228, g_11_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 228, g_12_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(170, 598, g_13_0GrHandle, TRUE);
		AABBDraw::MyDrawGraph(873, 598, g_14_0GrHandle, TRUE);

		if (SwordLv == 110) {
			DrawGraph(170, 228, g_11_0GrHandle, FALSE);
		}
		else if (SwordLv == 111) {
			DrawGraph(170, 228, g_11_1GrHandle, FALSE);
		}
		else if (SwordLv == 112) {
			DrawGraph(170, 228, g_11_2GrHandle, FALSE);
		}
		else if (SwordLv == 113) {
			DrawGraph(170, 228, g_11_3GrHandle, FALSE);
		}

		if (TrainingLv == 120) {
			DrawGraph(873, 228, g_12_0GrHandle, FALSE);
		}
		else if (TrainingLv == 121) {
			DrawGraph(873, 228, g_12_1GrHandle, FALSE);
		}
		else if (TrainingLv == 122) {
			DrawGraph(873, 228, g_12_2GrHandle, FALSE);
		}
		else if (TrainingLv == 123) {
			DrawGraph(873, 228, g_12_3GrHandle, FALSE);
		}

		if (AtelierLv == 130) {
			DrawGraph(170, 598, g_13_0GrHandle, FALSE);
		}
		else if (AtelierLv == 131) {
			DrawGraph(170, 598, g_13_1GrHandle, FALSE);
		}
		else if (AtelierLv == 132) {
			DrawGraph(170, 598, g_13_2GrHandle, FALSE);
		}
		else if (AtelierLv == 133) {
			DrawGraph(170, 598, g_13_3GrHandle, FALSE);
		}

		if (LibraryLv == 140) {
			DrawGraph(873, 598, g_14_0GrHandle, FALSE);
		}
		else if (LibraryLv == 141) {
			DrawGraph(873, 598, g_14_1GrHandle, FALSE);
		}
		else if (LibraryLv == 142) {
			DrawGraph(873, 598, g_14_2GrHandle, FALSE);
		}
		else if (LibraryLv == 143) {
			DrawGraph(873, 598, g_14_3GrHandle, FALSE);
		}
		AABBDraw::MyDrawGraph(802, 121, upGrHandle, TRUE);
	}


	switch (pattern)
	{
	case MENU_NUM::Set:
	{
		DrawGraph(377, 340, BoardGrHandle, TRUE);
		AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
		if (BuiltType == MENU_NUM::Bath)
		{
			DrawString(507, 400, "大浴場を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Dining)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "食堂を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Newspaper)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "新聞発行所を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Weapon)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "武器屋を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Armor)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "防具屋を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Church)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "教会を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Rifle)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "射撃場を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Sword)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "剣術場を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Training)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "鍛錬場を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Atelier)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "アトリエを建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Library)
		{
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "図書館を建設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Guild)
		{
			DrawString(507, 400, "すでに設置されています。", GetColor(0, 0, 0));
		}
		else if (MaxBuildFlag == true) {
			DrawString(507, 400, "施設上限です。", GetColor(0, 0, 0));
		}
		else if (MoneyFlag == true) {
			DrawString(507, 400, "所持金が足りません。", GetColor(0, 0, 0));
		}

		break;

	case MENU_NUM::Development:
	{
		DrawGraph(377, 340, BoardGrHandle, TRUE);
		AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい



		if (BuiltType == MENU_NUM::Guild)
		{
			DrawString(507, 400, "ギルドを増設しました", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Bath && BathLv > 40)
		{
			DrawString(507, 400, "大浴場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Dining && DiningLv > 50)
		{
			DrawString(507, 400, "食堂を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Newspaper && NewspaperLv > 60)
		{
			DrawString(507, 400, "新聞発行所を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Weapon && WeaponLv > 70)
		{
			DrawString(507, 400, "武器屋を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Armor && ArmorLv > 80)
		{
			DrawString(507, 400, "防具屋を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Church && ChurchLv > 90)
		{
			DrawString(507, 400, "教会を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Rifle && RifleLv > 100)
		{
			DrawString(507, 400, "射撃場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Sword && SwordLv > 110)
		{
			DrawString(507, 400, "剣術場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Training && TrainingLv > 120)
		{
			DrawString(507, 400, "鍛錬場を増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Atelier && AtelierLv > 130)
		{
			DrawString(507, 400, "アトリエを増設しました", GetColor(0, 0, 0));
		}
		else if (BuiltType == MENU_NUM::Library && LibraryLv > 140)
		{
			DrawString(507, 400, "図書館を増設しました", GetColor(0, 0, 0));
		}
		else if (TotalBuilding == MaxBuilding) {
			AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい
			DrawString(507, 400, "施設上限です。", GetColor(0, 0, 0));
			break;
		}
		else if (MoneyFlag == true) {
			DrawString(507, 400, "所持金が足りません。", GetColor(0, 0, 0));
		}
		break;

	case MENU_NUM::Delete:
	{
		DrawGraph(377, 340, BoardGrHandle, TRUE);
		AABBDraw::MyDrawGraph(707, 625, YesGrHandle, TRUE);  //枠の真ん中くらい

		if (BuiltType == MENU_NUM::Guild)
		{
			DrawString(507, 400, "削除できません", GetColor(0, 0, 0));
		}

		else if (BuiltType == MENU_NUM::Bath)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "大浴場を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Dining)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "食堂を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Newspaper)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "新聞発行所を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Weapon)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "武器屋を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Armor)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "防具屋を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Church)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "教会を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Rifle)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "射撃場を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Sword)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "剣術場を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Training)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "鍛錬場を削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Atelier)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "アトリエを削除しました", GetColor(0, 0, 0));
			}
		}
		else if (BuiltType == MENU_NUM::Library)
		{
			if (DeleteFlag == false) {
				DrawString(507, 400, "建設されていません", GetColor(0, 0, 0));
			}
			else if (DeleteFlag == true) {
				DrawString(507, 400, "図書館を削除しました", GetColor(0, 0, 0));
			}
			break;
		}
		break;
	}

	case MENU_NUM::Guild:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Bath:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Dining:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Newspaper:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Weapon:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Armor:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Church:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Rifle:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Sword:
	{
		DrawGraph(170, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Training:
	{
		DrawGraph(873, 228, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Atelier:
	{
		DrawGraph(170, 598, g_0GrHandle, TRUE);
		break;
	}
	case MENU_NUM::Library:
	{
		DrawGraph(873, 598, g_0GrHandle, TRUE);
		break;
	}
	}
	}
	}
}



int Guild::GetBuildingMoney(MENU_NUM type) {
	if (type == MENU_NUM::Guild) {
		int Lv = GuildLv % 10;
		if (Lv == 1) {
			return 2000000;
		}
		else if (Lv == 2) {
			return 5000000;
		}
	}
	else {
		int Lv = -1;
		if (type == MENU_NUM::Bath) {
			Lv = BathLv % 10;
		}
		else if (type == MENU_NUM::Bath) {
			Lv = BathLv % 10;
		}
		else if (type == MENU_NUM::Dining) {
			Lv = DiningLv % 10;
		}
		else if (type == MENU_NUM::Newspaper) {
			Lv = NewspaperLv % 10;
		}
		else if (type == MENU_NUM::Weapon) {
			Lv = WeaponLv % 10;
		}
		else if (type == MENU_NUM::Armor) {
			Lv = ArmorLv % 10;
		}
		else if (type == MENU_NUM::Church) {
			Lv = ChurchLv % 10;
		}
		else if (type == MENU_NUM::Rifle) {
			Lv = RifleLv % 10;
		}
		else if (type == MENU_NUM::Sword) {
			Lv = SwordLv % 10;
		}
		else if (type == MENU_NUM::Training) {
			Lv = TrainingLv % 10;
		}
		else if (type == MENU_NUM::Atelier) {
			Lv = AtelierLv % 10;
		}
		else if (type == MENU_NUM::Library) {
			Lv = LibraryLv % 10;
		}

		if (Lv == 0) {
			return 300000;
		}
		else if (Lv == 1) {
			return 1000000;
		}
		else if (Lv == 2) {
			return 3000000;
		}
	}
	return 0;
}