#pragma once
#include<array>

class SceneMgr;
class Game;

class Guild {
public:
	Guild(SceneMgr& scenemgr, Game& game);
	~Guild();
	void Guild_Input();
	void Guild_Update();
	void Guild_Render();
	//施設ごとのレベル
	std::array<int, 14> Lv{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0 };

protected:
	Game& _game;
	SceneMgr& _scenemgr;
	

private:
	enum class MENU_NUM {
		Return,  //メニューに戻る
		GuildMenu,  //メニュー
		Up, //上矢印
		Down,  //下矢印
		Set,  //設置
		Guild,  //ギルド拡張
		Bar,  //酒場
		Theater,  //演劇場
		Bath,  //大浴場
		Dining,  //食堂
		Newspaper,  //新聞発行所
		Weapon,  //武器屋
		Armor,  //防具屋
		Church,  //教会
		Rifle,  //射撃場
		Sword,  //剣術場
		Training,  //鍛錬場
		Atelier,  //アトリエ
		Library,  //図書館
		Null = -1,  //未選択

	};

	MENU_NUM pattern;
	MENU_NUM oldpattern;
	MENU_NUM nowSelectedPattern;

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _BIGrHandle{ -1 };
	int _BuildingSlotGrHandle{ -1 };
	int _BuildingGrHandle{ -1 };
	int _ButtonGrHandle{ -1 };

	int upGrHandle{ -1 };  //上矢印
	int downGrHandle{ -1 };  //下矢印
	int setGrHandle{ -1 };  //設置ボタン
	int g_0GrHandle{ -1 };  //選択枠

	int g_1GrHandle{ -1 };  //1はギルド増設
	int g_1_1GrHandle{ -1 };
	int g_1_2GrHandle{ -1 };
	int g_1_3GrHandle{ -1 };

	int g_2GrHandle{ -1 };  //2は酒場
	int g_2_1GrHandle{ -1 };
	int g_2_2GrHandle{ -1 };
	int g_2_3GrHandle{ -1 };

	int g_3GrHandle{ -1 };  //3は演劇場
	int g_3_1GrHandle{ -1 };
	int g_3_2GrHandle{ -1 };
	int g_3_3GrHandle{ -1 };

	int g_4GrHandle{ -1 };  //4は大浴場
	int g_4_1GrHandle{ -1 };
	int g_4_2GrHandle{ -1 };
	int g_4_3GrHandle{ -1 };

	int g_5GrHandle{ -1 };  //5は食堂
	int g_5_1GrHandle{ -1 };
	int g_5_2GrHandle{ -1 };
	int g_5_3GrHandle{ -1 };

	int g_6GrHandle{ -1 };  //6は新聞発行所
	int g_6_1GrHandle{ -1 };
	int g_6_2GrHandle{ -1 };
	int g_6_3GrHandle{ -1 };

	int g_7GrHandle{ -1 };  //7は武器屋　ここまで1ページ目
	int g_7_1GrHandle{ -1 };
	int g_7_2GrHandle{ -1 };
	int g_7_3GrHandle{ -1 };

	int g_8GrHandle{ -1 };  //8は防具屋
	int g_8_1GrHandle{ -1 };
	int g_8_2GrHandle{ -1 };
	int g_8_3GrHandle{ -1 };

	int g_9GrHandle{ -1 };  //9は教会
	int g_9_1GrHandle{ -1 };
	int g_9_2GrHandle{ -1 };
	int g_9_3GrHandle{ -1 };

	int g_10GrHandle{ -1 };  //10は射撃場
	int g_10_1GrHandle{ -1 };
	int g_10_2GrHandle{ -1 };
	int g_10_3GrHandle{ -1 };

	int g_11GrHandle{ -1 };  //11は剣術場
	int g_11_1GrHandle{ -1 };
	int g_11_2GrHandle{ -1 };
	int g_11_3GrHandle{ -1 };

	int g_12GrHandle{ -1 };  //12は鍛錬場
	int g_12_1GrHandle{ -1 };
	int g_12_2GrHandle{ -1 };
	int g_12_3GrHandle{ -1 };

	int g_13GrHandle{ -1 };  //13はアトリエ
	int g_13_1GrHandle{ -1 };
	int g_13_2GrHandle{ -1 };
	int g_13_3GrHandle{ -1 };

	int g_14GrHandle{ -1 };  //14は図書館
	int g_14_1GrHandle{ -1 };
	int g_14_2GrHandle{ -1 };
	int g_14_3GrHandle{ -1 };

	int ScreenNo;
};