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
		// 描画輝度をセット
		SetDrawBright(i, i, i);

		// グラフィックを描画
		DrawGraph(0, 0, _cg, FALSE);
		ScreenFlip();
	}
		DrawString(500, 500, "何か押して下さい。/n", GetColor(255, 255, 255), TRUE);
		WaitKey();
		_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
	}


