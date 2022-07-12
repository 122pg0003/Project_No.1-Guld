#include"Game.h"
#include"DxLib.h"

//コンストラクタ
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	, aabb(*this) 
	
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

}

//描画
void Game::Render() {
	mouse.M();

}
