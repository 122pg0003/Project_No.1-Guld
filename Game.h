#pragma once
#include"SceneMgr.h"
#include"Mouse.h"
#include"Collision.h"

constexpr auto SCREEN_W = 1280;
constexpr auto SCREEN_H = 720;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //ì¸óÕ
	void Update();   //çXêV
	void Render();   //ï`âÊ
	int  GetMouseX() { return mouse.GetMouseX(); }
	int  GetMouseY() { return mouse.GetMouseY(); }
	bool CheckHit() { return aabb.CheckHit(); }
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	AABB  aabb;


	/*private:
	char StrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;*/

};

