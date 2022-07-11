#include"Mouse.h"
#include"DxLib.h"

Mouse::Mouse(Game& game) :
_game(game)
{

}

Mouse::~Mouse() {

}

void Mouse::M() {
  // マウスを表示状態にする
  SetMouseDispFlag(TRUE);

  // 白色の値を取得
  StringCr = GetColor(255, 255, 255);

  // 黒の値を取得
  BoxCr = GetColor(0, 0, 0);

  // マウスの位置を取得
  GetMousePoint(&MouseX, &MouseY);

  // 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
  DrawBox(0, 0, 640, 32, BoxCr, TRUE);

  // 座標文字列を描く
  DrawFormatString(0, 600, StringCr, "座標Ｘ %d　　座標Ｙ %d", MouseX, MouseY);

  // メッセージ処理


  // 一定時間待つ
  //WaitTimer(100);
}

