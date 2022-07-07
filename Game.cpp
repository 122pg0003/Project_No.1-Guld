#include"Game.h"
#include"DxLib.h"

//コンストラクタ
Game::Game() :
scenemgr(*this)
,mouse(*this)
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
	DrawString(0, 20, "Gキーでゲーム画面、Cキーで設定、Mキーでメニュー画面になります。", GetColor(255, 255, 255));
}

//
//void Game::M(){
//  // マウスを表示状態にする
//  SetMouseDispFlag(TRUE);
//
//  // 白色の値を取得
//  StringCr = GetColor(255, 255, 255);
//
//  // 黒の値を取得
//  BoxCr = GetColor(0, 0, 0);
//
//    // マウスの位置を取得
//    GetMousePoint(&MouseX, &MouseY);
//
//    // 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
//    DrawBox(0, 0, 640, 32, BoxCr, TRUE);
//
//    // 座標文字列を描く
//    DrawFormatString(0, 0, StringCr, "座標Ｘ %d　　座標Ｙ %d", MouseX, MouseY);
//
//    // メッセージ処理
//  
//
//    // 一定時間待つ
//    WaitTimer(100);
//}

