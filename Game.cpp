#include"Game.h"
#include"DxLib.h"


//コンストラクタ
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	//, aabb(*this) 
	,background(*this)
	
{
	Audio_Check = false;
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
	AABBDraw::TouchCheck();
}