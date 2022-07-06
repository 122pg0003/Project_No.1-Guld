#pragma once
#include"SceneMgr.h"

constexpr auto SCREEN_W = 1280;
constexpr auto SCREEN_H = 720;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //����
	void Update();   //�X�V
	void Render();   //�`��

protected:
	SceneMgr scenemgr;

	
};

