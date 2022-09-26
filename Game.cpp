#include"Game.h"
#include"DxLib.h"


//コンストラクタ
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	,background(*this)
	,quest(scenemgr,*this)
	, guild(scenemgr, *this)
{
	Audio_Check = false;
	EndingFlag = 0;
}

//デストラクタ
Game::~Game() {

}

//入力
void Game::Input() {
	scenemgr.Scene_Input();

}

//更新
void Game::Update() {
	scenemgr.Scene_Update();
	//auto A = Adventurer_Status::Find("Key1");
	if (math.FameNo() >= 5000) {
		EndingFlag = 1;
	}

	if (math.GetMymoney() < 0) {
		EndingFlag = 2;
	}
}



//配列の初期化
void Game::Clear() {
	AABBDraw::Clear();
}


//描画
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


//触れているかのチェック
void Game::Check() {
	int keyold = _mouse;
	_mouse = (GetMouseInput() & MOUSE_INPUT_LEFT);
	//_mousetrg = (_mouse ^ keyold) & _mouse;
	_mousetrg = (keyold == 0) && (_mouse == 1);
	AABBDraw::TouchCheck();
}

//void Game::SetRandom() {
//}
