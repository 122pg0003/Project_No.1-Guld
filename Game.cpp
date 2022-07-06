#include"Game.h"
#include"DxLib.h"

//コンストラクタ
Game::Game() {

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
	DrawString(0, 20, "Gキーでゲーム画面、Cキーで設定、Mキーでメニュー画面になります。", GetColor(255, 255, 255));
}
