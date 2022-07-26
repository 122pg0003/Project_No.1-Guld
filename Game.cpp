#include"Game.h"
#include"DxLib.h"


//コンストラクタ
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	//, aabb(*this) 
	,background(*this)
	
{

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

//描画
void Game::Render() {
	ClearDrawScreen();
	mouse.M();
	scenemgr.Scene_Render();
	ScreenFlip();
	//background.BackGround_Render();
}
