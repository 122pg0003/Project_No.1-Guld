#pragma once

class TurnNumber {
public:
	TurnNumber();
	~TurnNumber();
	int turn;  ///ターン数(月)
	int month;
	int year;
	bool Start;
	void TurnCount();
	void Draw();
	
	
};