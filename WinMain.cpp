#include <memory>
#include "DxLib.h"
#include "Game.h"
#include"Audio.h"
#include"Ending.h"

enum GameMode
{
  MODE_TITLE,
  MODE_GAME,
  MODE_ENDING,
};



// プログラムはWinMain から始まります
int WINAPI WinMain(
  HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow) {
  ChangeWindowMode(TRUE);    // ウインドウモードに変更
  SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);    // 画面の解像度(幅,高さ)と色数(32bit)を指定
  DxLib_Init();    // Dxライブラリ初期化
  SetDrawScreen(DX_SCREEN_BACK);    // 描画先画面を裏にする

  GameMode nowSelectGameMode = MODE_TITLE;

  //ユニークポインタを作っている
  auto game = std::make_unique<Game>();

  auto title = std::make_unique<Title>(*game);
  auto ending = std::make_unique<Ending>(*game);
  auto audio = std::make_unique<Audio>();

  if (nowSelectGameMode == GameMode::MODE_GAME) {
    audio->Main_Audio();
  }

  //game->SetRandom();

  //メインループ
  while (ProcessMessage() != -1) {
    //ESCAPEで終了
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
      break;
    }

    switch (nowSelectGameMode)
    {
    case MODE_TITLE:
    {
      if (title->Title_Update() == 1)
      {
        nowSelectGameMode = MODE_GAME;
      }
      title->Title_Render();
      break;
    }
    case MODE_GAME:
    {
      // ゲームの処理
      game->Input();    // 入力
      game->Update();   // 更新
      game->Clear();    //配列の初期化
      ending->Render();
      //game->Render();   // 描画
      game->Check();    //触れたかのチェック
      if (game->EndingFlag == 1) {
        nowSelectGameMode = MODE_ENDING;
      }
      break;
    }
    case MODE_ENDING:
    { 
      ending->Update();
     ending->Render();
    if (game->_mousetrg != 0 && ending->EDcount == 9) {
      nowSelectGameMode = MODE_GAME;
      ending->EDcount = 1;
    }

    if (game->_mousetrg != 0 && game->EndingFlag == 2) {
      title->_isSelectGameMode = false;

      nowSelectGameMode = MODE_TITLE;
    }

    break;
    }
    default:
      break;
    }
  }

  // Dxライブラリ終了
  DxLib_End();

  return 0;
}
