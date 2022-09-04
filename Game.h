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
	void Input();    //����
	void Update();   //�X�V
	void Clear();  //�z��̏�����
	void Render();   //�`��
	void Check();  //�G�ꂽ���̃`�F�b�N
	int  GetMouseX() { return mouse.GetMouseX(); }      //�}�E�X��X���W�擾
	int  GetMouseY() { return mouse.GetMouseY(); }      //�}�E�X��Y���W�擾    
	//bool CheckHit() { return aabb.CheckHit(); }
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	Audio audio;
	//AABB  aabb;   //�����蔻��
	BackGround  background;
	bool Audio_Check;
	

	/*private:
	char StrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;*/

};

