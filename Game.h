#pragma once
#include"SceneMgr.h"
#include"Mouse.h"
#include"BackGround.h"
#include"Adventurer_Status.h"
#include"AABB.h"
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
	int  GetMouseX() { return mouse.GetMouseX(); }      //マウスのX座標取得
	int  GetMouseY() { return mouse.GetMouseY(); }      //マウスのY座標取得    
	//bool CheckHit() { return aabb.CheckHit(); }
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	Audio audio;
	//AABB  aabb;   //当たり判定
	BackGround  background;
	bool Audio_Check;
	

	/*private:
	char StrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;*/

};

