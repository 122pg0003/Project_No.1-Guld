#include"Game.h"
#include"DxLib.h"


//�R���X�g���N�^
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	//, aabb(*this) 
	,background(*this)
	
{
	Audio_Check = false;
}

//�f�X�g���N�^
Game::~Game() {

}

//����
void Game::Input() {
	scenemgr.Scene_Input();

}

//�X�V
void Game::Update() {
	scenemgr.Scene_Update();
	//auto A = Adventurer_Status::Find("Key1");

}

//�z��̏�����
void Game::Clear() {
	AABBDraw::Clear();
}


//�`��
void Game::Render() {
	if (Audio_Check == false) {
		audio.Main_Audio();
		Audio_Check = true;
	}
	audio.Check_Click();
	ClearDrawScreen();
	mouse.M();
	scenemgr.Scene_Render();
	ScreenFlip();
	//background.BackGround_Render();
}


//�G��Ă��邩�̃`�F�b�N
void Game::Check() {
	AABBDraw::TouchCheck();
}

void Game::SetRandom() {
	int tmp[7], i, j, flag;
	//srand((unsigned)time());

	for (i = 1; i <= 6; i++) {
		flag = TRUE;
		while (flag) {
			flag = FALSE;
			tmp[i] = rand() % 53;
			for (j = 1; j < i; j++) {
				if (tmp[j] == tmp[i]) {
					flag = TRUE;
					break;
				}
			}
		}
	}
	 random = tmp[1];
	random1 = tmp[2];
	random2 = tmp[3];
	random4 = tmp[4];
	random5 = tmp[5];
	random6 = tmp[6];

}
