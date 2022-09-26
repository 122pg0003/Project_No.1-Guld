#include"DxLib.h"
#include"Ending.h"
#include"Game.h"
#include"SceneMgr.h"

Ending::Ending(Game& game) :
	_game(game) {
	EDGrHandle1 = LoadGraph("images/EDÅQ01.png");
	EDGrHandle2 = LoadGraph("images/ED__02.png");
	EDGrHandle3 = LoadGraph("images/ED__03.png");
	EDGrHandle4 = LoadGraph("images/ED__04.png");

	CreditGrHandle1 = LoadGraph("images/SR1.png");
	CreditGrHandle2 = LoadGraph("images/SR2.png");
	CreditGrHandle3 = LoadGraph("images/SR3.png");
	CreditGrHandle4 = LoadGraph("images/SR4.png");
	CreditGrHandle5 = LoadGraph("images/SR5.png");
	CreditGrHandle6 = LoadGraph("images/SR6.png");

	EDcount = 1;
}

Ending::~Ending() {

}

void Ending::Update() {
	if (_game._mousetrg != 0 && _game.EndingFlag == 1) {
		EDcount += 1;
	}
	else if (_game._mousetrg != 0 && _game.EndingFlag == 2) {

	}
}

void Ending::Render() {
	ClearDrawScreen();
	DrawGraph(0, 0, EDGrHandle1, TRUE);
	switch (EDcount) {
	case 1: {
		DrawGraph(0, 0, EDGrHandle1, TRUE);
		break;
	}
	case 2: {
		DrawGraph(0, 0, EDGrHandle2, TRUE);
		break;
	}
	case 3: {
		DrawGraph(0, 0, EDGrHandle3, TRUE);
		break;
	}
	case 4: {
		DrawGraph(0, 0, CreditGrHandle1, TRUE);
		break;
	}
	case 5: {
		DrawGraph(0, 0, CreditGrHandle2, TRUE);
		break;
	}
	case 6: {
		DrawGraph(0, 0, CreditGrHandle3, TRUE);
		break;
	}
	case 7: {
		DrawGraph(0, 0, CreditGrHandle4, TRUE);
		break;
	}
	case 8: {
		DrawGraph(0, 0, CreditGrHandle5, TRUE);
		break;
	}
	case 9: {
		DrawGraph(0, 0, CreditGrHandle6, TRUE);
		break;
	}
				ScreenFlip();

	}

	if (_game.EndingFlag == 2) {
		DrawGraph(0, 0, EDGrHandle4, TRUE);
	}

}