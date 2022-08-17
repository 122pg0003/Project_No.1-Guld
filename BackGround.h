#pragma once

class Game;

class BackGround {
public:
	BackGround(Game& game);
	~BackGround();
	void BackGround_Render();

protected:
	Game& _game;

private:
	int _bg;
};
