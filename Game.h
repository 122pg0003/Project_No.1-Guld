#pragma once
#include"SceneMgr.h"
#include"Mouse.h"


constexpr auto SCREEN_W = 1280;
constexpr auto SCREEN_H = 720;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //“ü—Í
	void Update();   //XV
	void Render();   //•`‰æ
	int  GetMouseX() { return mouse.GetMouseX(); }
	int  GetMouseY() { return mouse.GetMouseY(); }
protected:
	SceneMgr scenemgr;
	Mouse mouse;


	/*private:
	char StrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;*/

};

