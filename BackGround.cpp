#include"BackGround.h"
#include"DxLib.h"

//�R���X�g���N�^
BackGround::BackGround(Game& game):
_game(game)
{
	_bg = LoadGraph("images/back_Full.png");
}

//�f�X�g���N�^
BackGround::~BackGround() {

}

void BackGround::BackGround_Render() {
	//DrawGraph(0, 0, _bg, TRUE);
}
