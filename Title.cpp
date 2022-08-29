#include"Title.h"
#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"

Title::Title(SceneMgr& scenemgr, Game& game):
_scenemgr(scenemgr),
_game(game)
{
	_cg = LoadGraph("images/gi_002.png");
}

Title::~Title() {

}


void Title::Title_Update() {
	
}


void Title::Title_Render() {
	WaitTimer(1000);
	for (auto i = 0; i < 255; i++)
	{
		// �`��P�x���Z�b�g
		SetDrawBright(i, i, i);

		// �O���t�B�b�N��`��
		DrawGraph(0, 0, _cg, FALSE);
		ScreenFlip();
	}
		DrawString(500, 500, "���������ĉ������B/n", GetColor(255, 255, 255), TRUE);
		WaitKey();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}


