#pragma once
#include"Math.h"
#include<array>

class SceneMgr;
class Game;

class Guild :public Math{
public:
	Guild(SceneMgr& scenemgr, Game& game);
	~Guild();
	void Guild_Input();
	void Guild_Update();
	void Guild_Render();

	int GuildLv;
	int BarLv;
	int TheaterLv;
	int BathLv;
	int DiningLv;
	int NewspaperLv;
	int WeaponLv;
	int ArmorLv;
	int ChurchLv;
	int RifleLv;
	int SwordLv;
	int TrainingLv;
	int AtelierLv;
	int LibraryLv;


	int MaxBuilding;
	int TotalBuilding;




protected:
	Game& _game;
	SceneMgr& _scenemgr;
	//Math math;

private:
	enum class MENU_NUM {
		Up, //ãîó
		Down,  //ºîó
		Guild,  //Mhg£
		Bar,  //ðê
		Theater,  //ê
		Bath,  //åê
		Dining,  //H°
		Newspaper,  //V·­s
		Weapon,  //í®
		Armor,  //hï®
		Church,  //³ï
		Rifle,  //Ëê
		Sword,  //pê
		Training,  //bBê
		Atelier,  //AgG
		Library,  //}Ù
		Set,  //Ýu
		Development,  //­W
		Delete,  //í
		Return,  //j[Éßé
		GuildMenu,  //j[
		Null = -1,  //¢Ið

	};

	MENU_NUM pattern;
	MENU_NUM oldpattern;
	MENU_NUM nowSelectedPattern;

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _BIGrHandle{ -1 };
	int _BuildingSlotGrHandle{ -1 };
	int _BuildingGrHandle{ -1 };
	int _ButtonGrHandle{ -1 };
	int _ReturnGrHandle{ -1 };

	int BaseGrHandle{ -1 };
	int BoardGrHandle{ -1 };  //EBhE
	int YesGrHandle{ -1 };  //YES{^
	int NoGrHandle{ -1 };  //NO{^

	int upGrHandle{ -1 };  //ãîó
	int downGrHandle{ -1 };  //ºîó
	int setGrHandle{ -1 };  //Ýu{^
	int developmentGrHandle{ -1 };  //­W{^
	int deleteGrHandle{ -1 };  //í{^
	int TotalGrHandle{ -1 };  //{ÝÌg
	int g_0GrHandle{ -1 };  //Iðg

	int g_1GrHandle{ -1 };  //1ÍMhÝ
	int g_1_1GrHandle{ -1 };
	int g_1_2GrHandle{ -1 };
	int g_1_3GrHandle{ -1 };

	int g_2GrHandle{ -1 };  //2Íðê
	int g_2_0GrHandle{ -1 };
	int g_2_1GrHandle{ -1 };
	int g_2_2GrHandle{ -1 };
	int g_2_3GrHandle{ -1 };

	int g_3GrHandle{ -1 };  //3Íê
	int g_3_0GrHandle{ -1 };
	int g_3_1GrHandle{ -1 };
	int g_3_2GrHandle{ -1 };
	int g_3_3GrHandle{ -1 };

	int g_4GrHandle{ -1 };  //4Íåê
	int g_4_0GrHandle{ -1 };
	int g_4_1GrHandle{ -1 };
	int g_4_2GrHandle{ -1 };
	int g_4_3GrHandle{ -1 };

	int g_5GrHandle{ -1 };  //5ÍH°
	int g_5_0GrHandle{ -1 };
	int g_5_1GrHandle{ -1 };
	int g_5_2GrHandle{ -1 };
	int g_5_3GrHandle{ -1 };

	int g_6GrHandle{ -1 };  //6ÍV·­s
	int g_6_0GrHandle{ -1 };
	int g_6_1GrHandle{ -1 };
	int g_6_2GrHandle{ -1 };
	int g_6_3GrHandle{ -1 };

	int g_7GrHandle{ -1 };  //7Íí®
	int g_7_0GrHandle{ -1 };
	int g_7_1GrHandle{ -1 };
	int g_7_2GrHandle{ -1 };
	int g_7_3GrHandle{ -1 };

	int g_8GrHandle{ -1 };  //8Íhï®
	int g_8_0GrHandle{ -1 };
	int g_8_1GrHandle{ -1 };
	int g_8_2GrHandle{ -1 };
	int g_8_3GrHandle{ -1 };

	int g_9GrHandle{ -1 };  //9Í³ï
	int g_9_0GrHandle{ -1 };
	int g_9_1GrHandle{ -1 };
	int g_9_2GrHandle{ -1 };
	int g_9_3GrHandle{ -1 };

	int g_10GrHandle{ -1 };  //10ÍËê
	int g_10_0GrHandle{ -1 };
	int g_10_1GrHandle{ -1 };
	int g_10_2GrHandle{ -1 };
	int g_10_3GrHandle{ -1 };

	int g_11GrHandle{ -1 };  //11Ípê
	int g_11_0GrHandle{ -1 };
	int g_11_1GrHandle{ -1 };
	int g_11_2GrHandle{ -1 };
	int g_11_3GrHandle{ -1 };

	int g_12GrHandle{ -1 };  //12ÍbBê
	int g_12_0GrHandle{ -1 };
	int g_12_1GrHandle{ -1 };
	int g_12_2GrHandle{ -1 };
	int g_12_3GrHandle{ -1 };

	int g_13GrHandle{ -1 };  //13ÍAgG
	int g_13_0GrHandle{ -1 };
	int g_13_1GrHandle{ -1 };
	int g_13_2GrHandle{ -1 };
	int g_13_3GrHandle{ -1 };

	int g_14GrHandle{ -1 };  //14Í}Ù
	int g_14_0GrHandle{ -1 };
	int g_14_1GrHandle{ -1 };
	int g_14_2GrHandle{ -1 };
	int g_14_3GrHandle{ -1 };

	int ScreenNo;
	MENU_NUM BuiltType = MENU_NUM::Null;
};