#pragma once
#include"SceneMgr.h"
#include"Mouse.h"
#include"BackGround.h"
#include"Adventurer_Status.h"
#include"AABB.h"
#include"Audio.h"
#include"TurnNumber.h"


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
//	void SetRandom() { return quest.Random_Quest(); }  ///�N�G�X�g�p����

	int  GetMouseX() { return mouse.GetMouseX(); }      //�}�E�X��X���W�擾
	int  GetMouseY() { return mouse.GetMouseY(); }      //�}�E�X��Y���W�擾
	int  GetTrun() { return turnno.turn; }
	int GetRandom() { return random; }
	int GetRandom1() { return random1; }
	int GetRandom2() { return random2; }
	int GetRandom3() { return random3; }
	int GetRandom4() { return random4; }
	int GetRandom5() { return random5; }
	int GetRandom6() { return random6; }

	int _mouse, _mousetrg;
	bool Audio_Check;
	
protected:
	SceneMgr scenemgr;
	Mouse mouse;
	Audio audio;
	BackGround  background;
	TurnNumber turnno;
	Quest quest;

private:
	int random;
	int random1;
	int random2;
	int random3;
	int random4;
	int random5;
	int random6;

};

