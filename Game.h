#pragma once
#include"SceneMgr.h"
#include"Mouse.h"
#include"BackGround.h"
#include"Adventurer_Status.h"
#include"AABB.h"
#include"Guild.h"
#include"Math.h"
#include"Audio.h"

constexpr auto SCREEN_W = 1980;
constexpr auto SCREEN_H = 1080;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //入力
	void Update();   //更新
	void Clear();  //配列の初期化
	void Render();   //描画
	void Check();  //触れたかのチェック
//	void SetRandom() { return quest.Random_Quest(); }  ///クエスト用乱数
	//void GetSave() { return math.Info_Save(); }
	//void GetLoad() { return math.Info_Load(); }
	//void GetMathRender() { return math.Math_Render(); }
	

	int  GetMouseX() { return mouse.GetMouseX(); }      //マウスのX座標取得
	int  GetMouseY() { return mouse.GetMouseY(); }      //マウスのY座標取得
	int  GetTrun() { return turnno.turn; }
	int GetRandom() { return random; }
	int GetRandom1() { return random1; }
	int GetRandom2() { return random2; }
	int GetRandom3() { return random3; }
	int GetRandom4() { return random4; }
	int GetRandom5() { return random5; }
	int GetRandom6() { return random6; }
	int GetQuest() { return math.FameNo(); }
	int GetBathLv() { return guild.BathLv; }
	int GetDiningLv() { return guild.DiningLv; }
	int GetNewspaperLv() { return guild.NewspaperLv; }
	int GetSwordLv() { return guild.SwordLv; }
	int GetTrainingLv() { return guild.TrainingLv; }
	int GetAtelierLv() { return guild.AtelierLv; }
	int GetLibraryLv() { return guild.LibraryLv; }	
	

	int _mouse, _mousetrg;
	bool Audio_Check;
	int EndingFlag;
	
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	Audio audio;
	BackGround  background;
	TurnNumber turnno;
	Quest quest;
  Math math;
	Guild guild;

private:
	int random;
	int random1;
	int random2;
	int random3;
	int random4;
	int random5;
	int random6;

};

