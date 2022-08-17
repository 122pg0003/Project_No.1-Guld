#pragma once

class Game;

class Mouse{
public:
	Mouse(Game& game);
	~Mouse();
	void M();
	int GetMouseX() { return MouseX; }
	int GetMouseY() { return MouseY; }
protected:
	Game& _game;

private:
	char SrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;

};
