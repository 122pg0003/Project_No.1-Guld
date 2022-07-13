#include"BackGround.h"
#include"DxLib.h"

//コンストラクタ
BackGround::BackGround(Game& game):
_game(game)
{
	_bg = LoadGraph("images/back_Full.png");
}

//デストラクタ
BackGround::~BackGround() {

}

void BackGround::BackGround_Render() {
	//DrawGraph(0, 0, _bg, TRUE);
}
