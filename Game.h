#pragma once
#include"SceneMgr.h"
#include"Mouse.h"
#include"BackGround.h"
#include"Adventurer_Status.h"


constexpr auto SCREEN_W = 1980;
constexpr auto SCREEN_H = 1080;
constexpr auto SCREEN_DEPTH = 32;

class Game {
public:
	Game();
	~Game();
	void Input();    //����
	void Update();   //�X�V
	void Render();   //�`��
	int  GetMouseX() { return mouse.GetMouseX(); }      //�}�E�X��X���W�擾
	int  GetMouseY() { return mouse.GetMouseY(); }      //�}�E�X��Y���W�擾    
	//bool CheckHit() { return aabb.CheckHit(); }
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	//AABB  aabb;   //�����蔻��
	BackGround  background;
	

	/*private:
	char StrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;*/

};

