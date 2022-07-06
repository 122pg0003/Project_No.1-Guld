#pragma once
#include"SceneMgr.h"

constexpr auto SCREEN_W = 1280;
constexpr auto SCREEN_H = 720;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //入力
	void Update();   //更新
	void Render();   //描画

protected:
	SceneMgr scenemgr;

	
};

