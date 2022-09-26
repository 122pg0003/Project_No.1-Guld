#include"Math.h"
#include"Dxlib.h"
#include<vector>

//#include"Game.h"
//#include"SceneMgr.h"
//#include"Quest.h"



//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Math::Math()
{
	SuccessRate = 0;
	no = 0;
	//FameNo = 0;
	//mymoney = 10000;
	
}


//ƒfƒXƒgƒ‰ƒNƒ^
Math::~Math() {

}


	int mymoney = 10000;
	int reward = 10000;
	int cost = 1000;
	int Fame{ 0 };  //–¼º’l

void Math::Success(int& SuccessRate, int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow) {

	if (TotalAttack >= ClearTotalAttack) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalDefence >= ClearTotalDefence) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalSkill >= ClearTotalSkill) {
		SuccessRate += AddSuccessrate;
	}

	if (TotalKnow >= ClearTotalKnow) {
		SuccessRate += AddSuccessrate;
	}

}
///ƒNƒGƒXƒg”»’è
bool Math::Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow) {
	//¬Œ÷—¦‚ğƒp[ƒeƒB[‚Ìƒg[ƒ^ƒ‹ƒXƒe[ƒ^ƒX‚ÅŒˆ‚ß‚Ä‚¢‚é
	Success(SuccessRate, ClearTotalAttack, ClearTotalDefence, ClearTotalSkill, ClearTotalKnow, TotalAttack, TotalDefence, TotalSkill, TotalKnow);



	//if (TotalAttack >= ClearTotalAttack) {
	//	SuccessRate += AddSuccessrate;
	//}
	//
	//if (TotalDefence >= ClearTotalDefence) {
	//	SuccessRate += AddSuccessrate;
	//}
	//
	//if (TotalSkill >= ClearTotalSkill) {
	//	SuccessRate += AddSuccessrate;
	//}
	//
	//if (TotalKnow >= ClearTotalKnow) {  
	//	SuccessRate += AddSuccessrate;
	//}

	no = rand() % SuccessRate + 45;

	if (no > SuccessRate) {
		//ƒNƒGƒXƒg¸”s
		mymoney -= cost;
		SuccessRate = 0;
		Fame += 5000;

		_questresult = 0;
	}

	else {
		//ƒNƒGƒXƒg¬Œ÷
		mymoney += (reward - cost);
		SuccessRate = 0;
		Fame += 5000;

		_questresult = 1;
	}
	return 0;
}

int Math::GetMymoney() {
	return mymoney;
}

int Math::FameNo() {
	return Fame;
}


void Math::Math_Update() {

	//if (Fame == 0) {
	//	FameNo() = 2;
	//}

	//if (Fame > 1000) {
	//	FameNo() = 1;
	//}


	auto str = std::to_string(mymoney);
	auto C = str.c_str();
	auto length = std::strlen(C);
	width = GetDrawStringWidth(C, length);

	auto strFame = std::to_string(Fame);
	auto CFame = strFame.c_str();
	auto lengthFame = std::strlen(CFame);
	widthFame = GetDrawStringWidth(CFame, lengthFame);


}



void Math::Math_Render() {
	Math_Update();
	DrawFormatString(1180 - width, 45, GetColor(255, 255, 255), "%d\n", mymoney);
	//DrawFormatString(1180, 45, GetColor(255, 255, 255), "%d\n", mymoney);
	DrawFormatString(1700 - widthFame, 45, GetColor(255, 255, 255), "%d\n", Fame);
	//DrawFormatString(1700, 45, GetColor(255, 255, 255), "%d\n", Fame);

}
//{İİ’u”ï
void Math::Set(int Lv) {
	switch (Lv)
	{
	case 11:  //1‚ÍƒMƒ‹ƒh‘İ
		mymoney -= 2000000;
		break;
	case 12:
		mymoney -= 5000000;
		break;

	case 20:  //‚Q‚Íğê
		mymoney -= 300000;
		break;
	case 21:
		mymoney -= 1000000;
		break;
	case 22:
		mymoney -= 3000000;
		break;

	case 30:  //‚R‚Í‰‰Œ€ê
		mymoney -= 300000;
		break;
	case 31:
		mymoney -= 1000000;
		break;
	case 32:
		mymoney -= 3000000;
		break;

	case 40:  //‚S‚Í‘å—ê
		mymoney -= 300000;
		break;
	case 41:
		mymoney -= 1000000;
		break;
	case 42:
		mymoney -= 3000000;
		break;

	case 50:  //‚T‚ÍH“°
		mymoney -= 300000;
		break;
	case 51:
		mymoney -= 1000000;
		break;
	case 52:
		mymoney -= 3000000;
		break;

	case 60:  //‚U‚ÍV•·”­sŠ
		mymoney -= 300000;
		break;
	case 61:
		mymoney -= 1000000;
		break;
	case 62:
		mymoney -= 3000000;
		break;

	case 70:  //‚V‚Í•Ší‰®
		mymoney -= 300000;
		break;
	case 71:
		mymoney -= 1000000;
		break;
	case 72:
		mymoney -= 3000000;

	case 80:  //‚W‚Í–h‹ï‰®
		mymoney -= 300000;
		break;
	case 81:
		mymoney -= 1000000;
		break;
	case 82:
		mymoney -= 3000000;
		break;

	case 90:  //‚X‚Í‹³‰ï
		mymoney -= 300000;
		break;
	case 91:
		mymoney -= 1000000;
		break;
	case 92:
		mymoney -= 3000000;
		break;

	case 100:  //‚P‚O‚ÍËŒ‚ê
		mymoney -= 300000;
		break;
	case 101:
		mymoney -= 1000000;
		break;
	case 102:
		mymoney -= 3000000;
		break;

	case 111:  //‚P‚P‚ÍŒ•pê
		mymoney -= 300000;
		break;
	case 112:
		mymoney -= 1000000;
		break;
	case 113:
		mymoney -= 3000000;
		break;

	case 120:  //‚P‚Q‚Í’b˜Bê
		mymoney -= 300000;
		break;
	case 121:
		mymoney -= 1000000;
		break;
	case 122:
		mymoney -= 3000000;
		break;

	case 130:  //‚P‚R‚ÍƒAƒgƒŠƒG
		mymoney -= 300000;
		break;
	case 131:
		mymoney -= 1000000;
		break;
	case 132:
		mymoney -= 3000000;
		break;

	case 140:  //‚P‚S‚Í}‘ŠÙ
		mymoney -= 300000;
		break;
	case 141:
		mymoney -= 1000000;
		break;
	case 142:
		mymoney -= 3000000;
		break;
	}
}

//ƒMƒ‹ƒh‚É‚¢‚é–`Œ¯Ò‚Ì‘Ì—Í‚ğ‚Ü‚ê‚ÉiLv1‚Í‚T“A‚»‚êˆÈã‚Í‚P‚O“j‚PiLv‚R‚Ì‚Í‚Qj‰ñ•œ‚·‚é
void Math::BathEffect(int Lv) {
	int no = rand() % 100 + 1;
	if (no < 5 && Lv == 41) {
		status.Physical[0] += 1;
		status.Physical[1] += 1;
		status.Physical[2] += 1;
		status.Physical[3] += 1;
		status.Physical[4] += 1;
		status.Physical[5] += 1;
		status.Physical[6] += 1;

	}
	else if (no < 10 && Lv == 42) {
		status.Physical[0] += 1;
		status.Physical[1] += 1;
		status.Physical[2] += 1;
		status.Physical[3] += 1;
		status.Physical[4] += 1;
		status.Physical[5] += 1;
		status.Physical[6] += 1;
	}
	else if (no < 10 && Lv == 43) {
		status.Physical[0] += 2;
		status.Physical[1] += 2;
		status.Physical[2] += 2;
		status.Physical[3] += 2;
		status.Physical[4] += 2;
		status.Physical[5] += 2;
		status.Physical[6] += 2;
	}
	else {

	}
}

//–ˆƒ^[ƒ“Š‹ài‚T‚O–œA‚P‚T‚O–œA‚R‚O‚O–œjŠl“¾
void Math::DiningEffect(int Lv) {
	switch (Lv)
	{
	case 51:
		mymoney += 500000;
		break;
	case 52:
		mymoney += 1500000;
		break;
	case 53:
		mymoney += 3000000;
		break;
	}
}

//–ˆƒ^[ƒ“–¼º’li‚P‚OC‚T‚OC‚P‚O‚Oj‚ğŠl“¾
void Math::NewspaperEffect(int Lv) {
	switch (Lv)
	{
	case 61:
		Fame += 10;
		break;
	case 62:
		Fame += 50;
		break;
	case 63:
		Fame += 100;
		break;
	}
}

//ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚ÌUŒ‚i‚R‚OC‚T‚OC‚P‚O‚Oj‚ğã‚°‚é
void Math::WeaponEffect(int Lv) {
	switch (Lv)
	{
	case 71:
		status.Attack[0] += 30;
		status.Attack[1] += 30;
		status.Attack[2] += 30;
		status.Attack[3] += 30;
		status.Attack[4] += 30;
		status.Attack[5] += 30;
		status.Attack[6] += 30;
		break;
	case 72:
		status.Attack[0] += 20;
		status.Attack[1] += 20;
		status.Attack[2] += 20;
		status.Attack[3] += 20;
		status.Attack[4] += 20;
		status.Attack[5] += 20;
		status.Attack[6] += 20;
		break;
	case 73:
		status.Attack[0] += 50;
		status.Attack[1] += 50;
		status.Attack[2] += 50;
		status.Attack[3] += 50;
		status.Attack[4] += 50;
		status.Attack[5] += 50;
		status.Attack[6] += 50;
		break;
	}
}

//ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ìç”õi‚R‚OC‚T‚OC‚P‚O‚Oj‚ğã‚°‚é
void Math::ArmorEffect(int Lv) {
	switch (Lv)
	{
	case 81:
		status.Defence[0] += 30;
		status.Defence[1] += 30;
		status.Defence[2] += 30;
		status.Defence[3] += 30;
		status.Defence[4] += 30;
		status.Defence[5] += 30;
		status.Defence[6] += 30;
		break;
	case 82:
		status.Defence[0] += 20;
		status.Defence[1] += 20;
		status.Defence[2] += 20;
		status.Defence[3] += 20;
		status.Defence[4] += 20;
		status.Defence[5] += 20;
		status.Defence[6] += 20;
		break;
	case 83:
		status.Defence[0] += 50;
		status.Defence[1] += 50;
		status.Defence[2] += 50;
		status.Defence[3] += 50;
		status.Defence[4] += 50;
		status.Defence[5] += 50;
		status.Defence[6] += 50;
		break;
	}
}

//ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ì’m—Íi‚R‚OC‚T‚OC‚P‚O‚Oj‚ğã‚°‚é
void Math::ChurchEffect(int Lv) {
	switch (Lv)
	{
	case 91:
		status.Know[0] += 30;
		status.Know[1] += 30;
		status.Know[2] += 30;
		status.Know[3] += 30;
		status.Know[4] += 30;
		status.Know[5] += 30;
		status.Know[6] += 30;
		break;
	case 92:
		status.Know[0] += 20;
		status.Know[1] += 20;
		status.Know[2] += 20;
		status.Know[3] += 20;
		status.Know[4] += 20;
		status.Know[5] += 20;
		status.Know[6] += 20;
		break;
	case 93:
		status.Know[0] += 50;
		status.Know[1] += 50;
		status.Know[2] += 50;
		status.Know[3] += 50;
		status.Know[4] += 50;
		status.Know[5] += 50;
		status.Know[6] += 50;
		break;
	}
}

//ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ì‹Zpi‚R‚OC‚T‚OC‚P‚O‚Oj‚ğã‚°‚é
void Math::RifleEffect(int Lv) {
	switch (Lv)
	{
	case 101:
		status.Skill[0] += 30;
		status.Skill[1] += 30;
		status.Skill[2] += 30;
		status.Skill[3] += 30;
		status.Skill[4] += 30;
		status.Skill[5] += 30;
		status.Skill[6] += 30;
		break;
	case 102:
		status.Skill[0] += 20;
		status.Skill[1] += 20;
		status.Skill[2] += 20;
		status.Skill[3] += 20;
		status.Skill[4] += 20;
		status.Skill[5] += 20;
		status.Skill[6] += 20;
		break;
	case 103:
		status.Skill[0] += 50;
		status.Skill[1] += 50;
		status.Skill[2] += 50;
		status.Skill[3] += 50;
		status.Skill[4] += 50;
		status.Skill[5] += 50;
		status.Skill[6] += 50;
		break;
	}
}

//–ˆƒ^[ƒ“ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚ÌUŒ‚—Íi‚TC‚P‚TC‚R‚Oj‚ğã‚°‚é
void Math::SwordEffect(int Lv) {
	switch (Lv)
	{
	case 111:
		status.Attack[0] += 5;
		status.Attack[1] += 5;
		status.Attack[2] += 5;
		status.Attack[3] += 5;
		status.Attack[4] += 5;
		status.Attack[5] += 5;
		status.Attack[6] += 5;
		break;
	case 112:
		status.Attack[0] += 15;
		status.Attack[1] += 15;
		status.Attack[2] += 15;
		status.Attack[3] += 15;
		status.Attack[4] += 15;
		status.Attack[5] += 15;
		status.Attack[6] += 15;
		break;
	case 113:
		status.Attack[0] += 30;
		status.Attack[1] += 30;
		status.Attack[2] += 30;
		status.Attack[3] += 30;
		status.Attack[4] += 30;
		status.Attack[5] += 30;
		status.Attack[6] += 30;
		break;
	}
}

//–ˆƒ^[ƒ“ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ìç”õi‚TC‚P‚TC‚R‚Oj‚ğã‚°‚é
void Math::TrainingEffect(int Lv) {
	switch (Lv)
	{
	case 121:
		status.Defence[0] += 5;
		status.Defence[1] += 5;
		status.Defence[2] += 5;
		status.Defence[3] += 5;
		status.Defence[4] += 5;
		status.Defence[5] += 5;
		status.Defence[6] += 5;
		break;
	case 122:
		status.Defence[0] += 15;
		status.Defence[1] += 15;
		status.Defence[2] += 15;
		status.Defence[3] += 15;
		status.Defence[4] += 15;
		status.Defence[5] += 15;
		status.Defence[6] += 15;
		break;
	case 123:
		status.Defence[0] += 30;
		status.Defence[1] += 30;
		status.Defence[2] += 30;
		status.Defence[3] += 30;
		status.Defence[4] += 30;
		status.Defence[5] += 30;
		status.Defence[6] += 30;
		break;
	}
}

//–ˆƒ^[ƒ“ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ì‹Zpi‚TC‚P‚TC‚R‚Oj‚ğã‚°‚é
void Math::AtelierEffect(int Lv) {
	switch (Lv)
	{
	case 131:
		status.Skill[0] += 5;
		status.Skill[1] += 5;
		status.Skill[2] += 5;
		status.Skill[3] += 5;
		status.Skill[4] += 5;
		status.Skill[5] += 5;
		status.Skill[6] += 5;
		break;
	case 132:
		status.Skill[0] += 15;
		status.Skill[1] += 15;
		status.Skill[2] += 15;
		status.Skill[3] += 15;
		status.Skill[4] += 15;
		status.Skill[5] += 15;
		status.Skill[6] += 15;
		break;
	case 133:
		status.Skill[0] += 30;
		status.Skill[1] += 30;
		status.Skill[2] += 30;
		status.Skill[3] += 30;
		status.Skill[4] += 30;
		status.Skill[5] += 30;
		status.Skill[6] += 30;
		break;
	}
}

//–ˆƒ^[ƒ“ƒMƒ‹ƒh‚Ì–`Œ¯Ò‚Ì’m—Íi‚TC‚P‚TC‚R‚Oj‚ğã‚°‚é
void Math::LibraryEffect(int Lv) {
	switch (Lv)
	{
	case 141:
		status.Know[0] += 5;
		status.Know[1] += 5;
		status.Know[2] += 5;
		status.Know[3] += 5;
		status.Know[4] += 5;
		status.Know[5] += 5;
		status.Know[6] += 5;
		break;
	case 142:
		status.Know[0] += 15;
		status.Know[1] += 15;
		status.Know[2] += 15;
		status.Know[3] += 15;
		status.Know[4] += 15;
		status.Know[5] += 15;
		status.Know[6] += 15;
		break;
	case 143:
		status.Know[0] += 30;
		status.Know[1] += 30;
		status.Know[2] += 30;
		status.Know[3] += 30;
		status.Know[4] += 30;
		status.Know[5] += 30;
		status.Know[6] += 30;
		break;
	}
}

void Math::WeaponDelete(int Lv) {
	switch (Lv)
	{
	case 71:
		status.Attack[0] -= 30;
		status.Attack[1] -= 30;
		status.Attack[2] -= 30;
		status.Attack[3] -= 30;
		status.Attack[4] -= 30;
		status.Attack[5] -= 30;
		status.Attack[6] -= 30;
		break;
	case 72:
		status.Attack[0] -= 50;
		status.Attack[1] -= 50;
		status.Attack[2] -= 50;
		status.Attack[3] -= 50;
		status.Attack[4] -= 50;
		status.Attack[5] -= 50;
		status.Attack[6] -= 50;
		break;
	case 73:
		status.Attack[0] -= 100;
		status.Attack[1] -= 100;
		status.Attack[2] -= 100;
		status.Attack[3] -= 100;
		status.Attack[4] -= 100;
		status.Attack[5] -= 100;
		status.Attack[6] -= 100;
		break;
	}
}

void Math::ArmorDelete(int Lv) {
	switch (Lv)
	{
	case 81:
		status.Defence[0] -= 30;
		status.Defence[1] -= 30;
		status.Defence[2] -= 30;
		status.Defence[3] -= 30;
		status.Defence[4] -= 30;
		status.Defence[5] -= 30;
		status.Defence[6] -= 30;
		break;
	case 82:
		status.Defence[0] -= 50;
		status.Defence[1] -= 50;
		status.Defence[2] -= 50;
		status.Defence[3] -= 50;
		status.Defence[4] -= 50;
		status.Defence[5] -= 50;
		status.Defence[6] -= 50;
		break;
	case 83:
		status.Defence[0] -= 100;
		status.Defence[1] -= 100;
		status.Defence[2] -= 100;
		status.Defence[3] -= 100;
		status.Defence[4] -= 100;
		status.Defence[5] -= 100;
		status.Defence[6] -= 100;
		break;
	}
}

void Math::ChurchDelete(int Lv) {
	switch (Lv)
	{
	case 91:
		status.Know[0] -= 30;
		status.Know[1] -= 30;
		status.Know[2] -= 30;
		status.Know[3] -= 30;
		status.Know[4] -= 30;
		status.Know[5] -= 30;
		status.Know[6] -= 30;
		break;
	case 92:
		status.Know[0] -= 50;
		status.Know[1] -= 50;
		status.Know[2] -= 50;
		status.Know[3] -= 50;
		status.Know[4] -= 50;
		status.Know[5] -= 50;
		status.Know[6] -= 50;
		break;
	case 93:
		status.Know[0] -= 100;
		status.Know[1] -= 100;
		status.Know[2] -= 100;
		status.Know[3] -= 100;
		status.Know[4] -= 100;
		status.Know[5] -= 100;
		status.Know[6] -= 100;
		break;
	}
}

void Math::RifleDelete(int Lv) {
	switch (Lv)
	{
	case 101:
		status.Skill[0] -= 30;
		status.Skill[1] -= 30;
		status.Skill[2] -= 30;
		status.Skill[3] -= 30;
		status.Skill[4] -= 30;
		status.Skill[5] -= 30;
		status.Skill[6] -= 30;
		break;
	case 102:
		status.Skill[0] -= 50;
		status.Skill[1] -= 50;
		status.Skill[2] -= 50;
		status.Skill[3] -= 50;
		status.Skill[4] -= 50;
		status.Skill[5] -= 50;
		status.Skill[6] -= 50;
		break;
	case 103:
		status.Skill[0] -= 100;
		status.Skill[1] -= 100;
		status.Skill[2] -= 100;
		status.Skill[3] -= 100;
		status.Skill[4] -= 100;
		status.Skill[5] -= 100;
		status.Skill[6] -= 100;
		break;
	}
}







//ˆÛ”ï‚Ì’¥û
void Math::GuildCost(int Lv) {

	switch (Lv)
	{
	case 11:
		mymoney -= 1000000;
		break;
	case 12:
		mymoney -= 3000000;
		break;
	case 13:
		mymoney -= 5000000;
		break;

	case 41:
		mymoney -= 100000;
		break;
	case 42:
		mymoney -= 500000;
		break;
	case 43:
		mymoney -= 1000000;
		break;

	case 51:
		mymoney -= 200000;
		break;
	case 52:
		mymoney -= 500000;
		break;
	case 53:
		mymoney -= 700000;
		break;

	case 61:
		mymoney -= 100000;
		break;
	case 62:
		mymoney -= 3000000;
		break;
	case 63:
		mymoney -= 5000000;
		break;

	case 71:
		mymoney -= 100000;
		break;
	case 72:
		mymoney -= 300000;
		break;
	case 73:
		mymoney -= 600000;
		break;

	case 81:
		mymoney -= 100000;
		break;
	case 82:
		mymoney -= 300000;
		break;
	case 83:
		mymoney -= 600000;
		break;

	case 91:
		mymoney -= 100000;
		break;
	case 92:
		mymoney -= 300000;
		break;
	case 93:
		mymoney -= 600000;
		break;

	case 101:
		mymoney -= 100000;
		break;
	case 102:
		mymoney -= 300000;
		break;
	case 103:
		mymoney -= 600000;
		break;

	case 111:
		mymoney -= 100000;
		break;
	case 112:
		mymoney -= 300000;
		break;
	case 113:
		mymoney -= 600000;
		break;

	case 121:
		mymoney -= 100000;
		break;
	case 122:
		mymoney -= 300000;
		break;
	case 123:
		mymoney -= 600000;
		break;

	case 131:
		mymoney -= 100000;
		break;
	case 132:
		mymoney -= 300000;
		break;
	case 133:
		mymoney -= 600000;
		break;

	case 141:
		mymoney -= 100000;
		break;
	case 142:
		mymoney -= 300000;
		break;
	case 143:
		mymoney -= 600000;
		break;
	}
}

		//char ch[50] = "ABCDEFGH";
		

void Math::Info_Save() {
		FILE* fp;
		fopen_s(&fp, "ƒZ[ƒuƒf[ƒ^.dat", "wb"); // ƒtƒ@ƒCƒ‹‚ğŠJ‚­
		if (fp == NULL) { // NULL‚ª•Ô‚Á‚Ä‚«‚½‚çƒGƒ‰[”­¶
			return;
		}
		fwrite(&mymoney, sizeof(int), 1, fp); // ƒtƒ@ƒCƒ‹‚Émoney‚Ì’l‚ğo—Í‚·‚é
		fwrite(&Fame, sizeof(int), 1, fp); // ƒtƒ@ƒCƒ‹‚Émoney‚Ì’l‚ğo—Í‚·‚é
		fclose(fp); //ƒtƒ@ƒCƒ‹‚ğ•Â‚¶‚é

	}

void Math::Info_Load() {
	FILE* fp;
	fopen_s(&fp, "ƒZ[ƒuƒf[ƒ^.dat", "rb");

	if (fp == NULL) {
		DrawString(100, 100, "ƒNƒGƒXƒg2", TRUE);
		printf("ƒtƒ@ƒCƒ‹‚ğŠJ‚¯‚Ü‚¹‚ñ‚Å‚µ‚½");
	}

	fread(&mymoney, sizeof(int), 1, fp);
	fread(&Fame, sizeof(int), 1, fp);
	fclose(fp);
}