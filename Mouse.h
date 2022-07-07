#pragma once

class Game;

class Mouse{
public:
	Mouse(Game& game);
	~Mouse();
	void M();
	int GetMouse() { return MouseX; }

protected:
	Game& _game;

private:
	char SrBuf[128], StrBuf2[32];
	int MouseX, MouseY;
	int StringCr, BoxCr;

};
