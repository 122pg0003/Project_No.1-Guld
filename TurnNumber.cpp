#include "DxLib.h"
#include "TurnNumber.h"

TurnNumber::TurnNumber(){
	turn = 1;
	month = 1;
	year = 1;
	//Start = FALSE;
}


TurnNumber::~TurnNumber() {

}

void TurnNumber::TurnCount() {
	turn += 1;
	month += 1;
	
	if (month >= 13) {
		month = 1;
		year += 1;
	}
}

void TurnNumber::Draw() {
	SetFontSize(60);
	DrawFormatString(145, 45, GetColor(255, 255, 255), "%d       %d　", year, month);
	//DrawFormatString(10, 10, GetColor(255, 255, 255), "%d年目　%d月　%dターン目", year, month, turn);
}