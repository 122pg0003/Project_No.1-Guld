#pragma once


class SceneMgr;
class Game;

class Title {
public:
	Title(Game& game);
	~Title();
	int Title_Update();
	void Title_Render();
	// �^�C�g����ʂ��\������Ă���A���[�h�̑I�������ꂽ��true
	bool _isSelectGameMode;

private:
	Game& _game;
	//SceneMgr& _scenemgr;
	int _cg;
	int AMGGrHandle;
	int RogoGrHandle;
	int TitleGrHandle;
	bool skip();

	// �摜�̓��ߓx
	int _imageAlpha;
	// �摜�𓧉߂��ĕ\�����I�������P�J�E���g����J�E���^
	int _alphaLoopCount;


	const int _imageAlphaSpeed = 5;
	const int _waitMaxAlphaFrame = 20;
	int _waitTitleCount;
};
