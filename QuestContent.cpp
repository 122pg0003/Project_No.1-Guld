#include "DxLib.h"
#include "QuestContent.h"


QuestContent::QuestContent() {
	QuestIconGrHandle[0] = LoadGraph("images/Quest-1.png");
	QuestIconGrHandle[1] = LoadGraph("images/Quest-2.png");
	QuestIconGrHandle[2] = LoadGraph("images/Quest-3.png");
	QuestIconGrHandle[3] = LoadGraph("images/Quest-4.png");
	QuestIconGrHandle[4] = LoadGraph("images/Quest-5.png");
	QuestIconGrHandle[5] = LoadGraph("images/Quest-6.png");
	QuestIconGrHandle[6] = LoadGraph("images/Quest-1.png");
	QuestIconGrHandle[7] = LoadGraph("images/Quest-2.png");
	QuestIconGrHandle[8] = LoadGraph("images/Quest-3.png");
	QuestIconGrHandle[9] = LoadGraph("images/Quest-4.png");
	QuestIconGrHandle[10] = LoadGraph("images/Quest-5.png");
	QuestIconGrHandle[11] = LoadGraph("images/Quest-6.png");

}

QuestContent::~QuestContent() {

}

void QuestContent::QuestEtc(int questIndex,
	int& ClearTotalAttack,
	int& ClearTotalDefence,
	int& ClearTotalSkill,
	int& ClearTotalKnow
	) {
	 QuestNo = questIndex;
	//no = rand() % 12;

	if (QuestNo == 0) {
		ClearTotalAttack = QuestClearAttacks[0];
		ClearTotalDefence = QuestClearDefence[0];
		ClearTotalSkill = QuestClearSkill[0];
		ClearTotalKnow = QuestClearKnow[0];
		QuestTurn = necessaryturn[0];
	}
	if (QuestNo == 1) {
		ClearTotalAttack = QuestClearAttacks[1];
		ClearTotalDefence = QuestClearDefence[1];
		ClearTotalSkill = QuestClearSkill[1];
		ClearTotalKnow = QuestClearKnow[1];
		QuestTurn = necessaryturn[1];
	}
	if (QuestNo == 2) {
		ClearTotalAttack = QuestClearAttacks[2];
		ClearTotalDefence = QuestClearDefence[2];
		ClearTotalSkill = QuestClearSkill[2];
		ClearTotalKnow = QuestClearKnow[2];
		QuestTurn = necessaryturn[2];
	}
	if (QuestNo == 3) {
		ClearTotalAttack = QuestClearAttacks[3];
		ClearTotalDefence = QuestClearDefence[3];
		ClearTotalSkill = QuestClearSkill[3];
		ClearTotalKnow = QuestClearKnow[3];
		QuestTurn = necessaryturn[3];
	}
	if (QuestNo == 4) {
		ClearTotalAttack = QuestClearAttacks[4];
		ClearTotalDefence = QuestClearDefence[4];
		ClearTotalSkill = QuestClearSkill[4];
		ClearTotalKnow = QuestClearKnow[4];
		QuestTurn = necessaryturn[4];
	}
	if (QuestNo == 5) {
		ClearTotalAttack = QuestClearAttacks[5];
		ClearTotalDefence = QuestClearDefence[5];
		ClearTotalSkill = QuestClearSkill[5];
		ClearTotalKnow = QuestClearKnow[5];
		QuestTurn = necessaryturn[5];
	}
	if (QuestNo == 6) {
		ClearTotalAttack = QuestClearAttacks[6];
		ClearTotalDefence = QuestClearDefence[6];
		ClearTotalSkill = QuestClearSkill[6];
		ClearTotalKnow = QuestClearKnow[6];
		QuestTurn = necessaryturn[6];
	}
	if (QuestNo == 7) {
		ClearTotalAttack = QuestClearAttacks[7];
		ClearTotalDefence = QuestClearDefence[7];
		ClearTotalSkill = QuestClearSkill[7];
		ClearTotalKnow = QuestClearKnow[7];
		QuestTurn = necessaryturn[7];
	}
	if (QuestNo == 8) {
		ClearTotalAttack = QuestClearAttacks[8];
		ClearTotalDefence = QuestClearDefence[8];
		ClearTotalSkill = QuestClearSkill[8];
		ClearTotalKnow = QuestClearKnow[8];
		QuestTurn = necessaryturn[8];
	}
	if (QuestNo == 9) {
		ClearTotalAttack = QuestClearAttacks[9];
		ClearTotalDefence = QuestClearDefence[9];
		ClearTotalSkill = QuestClearSkill[9];
		ClearTotalKnow = QuestClearKnow[9];
		QuestTurn = necessaryturn[9];
	}
	if (QuestNo == 10) {
		ClearTotalAttack = QuestClearAttacks[10];
		ClearTotalDefence = QuestClearDefence[10];
		ClearTotalSkill = QuestClearSkill[10];
		ClearTotalKnow = QuestClearKnow[10];
		QuestTurn = necessaryturn[10];
	}
	if (QuestNo == 11) {
		ClearTotalAttack = QuestClearAttacks[11];
		ClearTotalDefence = QuestClearDefence[11];
		ClearTotalSkill = QuestClearSkill[11];
		ClearTotalKnow = QuestClearKnow[11];
		QuestTurn = necessaryturn[11];
	}
}