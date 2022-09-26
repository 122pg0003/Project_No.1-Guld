#pragma once


class SceneMgr;
class Game;

class Title {
public:
	Title(Game& game);
	~Title();
	int Title_Update();
	void Title_Render();
	// タイトル画面が表示されてから、モードの選択をされたらtrue
	bool _isSelectGameMode;

private:
	Game& _game;
	//SceneMgr& _scenemgr;
	int _cg;
	int AMGGrHandle;
	int RogoGrHandle;
	int TitleGrHandle;
	bool skip();

	// 画像の透過度
	int _imageAlpha;
	// 画像を透過して表示が終わったら１カウントするカウンタ
	int _alphaLoopCount;


	const int _imageAlphaSpeed = 5;
	const int _waitMaxAlphaFrame = 20;
	int _waitTitleCount;
};
