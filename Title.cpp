#include"Title.h"
#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"

Title::Title(Game& game) :
	_game(game)
{
	_cg = LoadGraph("images/gi_002.png");
	AMGGrHandle = LoadGraph("images/AMG-LOGO.png");
	RogoGrHandle = LoadGraph("images/rogo.png");
	TitleGrHandle = LoadGraph("images/title.png");

	_imageAlpha = 0;
	_alphaLoopCount = 0;
	_isSelectGameMode = false;
	_waitTitleCount = 0;
}

Title::~Title() {

}


int Title::Title_Update() {

	if (_alphaLoopCount < 2)
	{
		if (GetMouseInput() & MOUSE_INPUT_LEFT) // 実際にはモード選択が行われたら、にする
		{
			_imageAlpha = 0;
			_waitTitleCount = 0;
			_alphaLoopCount = 2;
		}
	}

	if (_imageAlpha < 256 * 2)
	{
		if (_imageAlpha > 256)
		{
			_waitTitleCount++;
			if (_waitTitleCount > _waitMaxAlphaFrame || _alphaLoopCount == 2)
			{
				_imageAlpha += _imageAlphaSpeed;
			}
			else
			{
				_imageAlpha = 256;
			}
		}
		else
		{
			_imageAlpha += _imageAlphaSpeed;
		}

		if (!_isSelectGameMode && _alphaLoopCount == 2 && _imageAlpha > 256)
		{
			_imageAlpha = 256;
			// タイトル画面での入力待ちをする
			if (GetMouseInput() & MOUSE_INPUT_LEFT) // 実際にはモード選択が行われたら、にする
			{
				_isSelectGameMode = true;
				

			}
		}
	}
	else
	{
		_imageAlpha = 0;
		_waitTitleCount = 0;
		_alphaLoopCount++;
		if (_alphaLoopCount == 3)
		{
			return 1;
			_imageAlpha = 0;
			_alphaLoopCount = 0;
			_waitTitleCount = 0;
			_alphaLoopCount = 0;
			//_scenemgr.SceneMgr_ChangeScene(SceneMgr::eScene::Menu);
		}
	}

	return 0;
}

bool Title::skip() {
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)) {
		return true;
	}
	return false;
}

void Title::Title_Render() {
	ClearDrawScreen();

	int drawAlpha = _imageAlpha;
	if (drawAlpha > 256)
	{
		drawAlpha = 256 * 2 - _imageAlpha;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha);

	switch (_alphaLoopCount)
	{
	case 0:
		DrawGraph(0, 0, AMGGrHandle, TRUE);
		break;
	case 1:
		DrawGraph(0, 0, RogoGrHandle, TRUE);
		break;
	case 2:
		DrawGraph(0, 0, _cg, TRUE);
		DrawGraph(0, 0, TitleGrHandle, TRUE);
		break;

	default:
		break;
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();


}
