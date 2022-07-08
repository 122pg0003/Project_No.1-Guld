#include <memory>
#include "DxLib.h"
#include "Game.h"


// プログラムはWinMain から始まります
int WINAPI WinMain(
  HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow) {
  ChangeWindowMode(TRUE);    // ウインドウモードに変更
  SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);    // 画面の解像度(幅,高さ)と色数(32bit)を指定
  DxLib_Init();    // Dxライブラリ初期化
  //SetDrawScreen(DX_SCREEN_BACK);    // 描画先画面を裏にする

  
  auto game = std::make_unique<Game>();


  while (ProcessMessage() != -1) {
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
      break;
    }
    // ゲームの処理
    game->Input();    // 入力
    game->Update();   // 更新
    game->Render();   // 描画
   //game->M();
  }

  // Dxライブラリ終了
  DxLib_End();

  return 0;
}
