#pragma once
#include<unordered_map>

class Adventurer_Status {
public:
	Adventurer_Status();
	~Adventurer_Status();
	int Find(std::string status);
	const int AdventurerMember[10]{};  //–`Œ¯Ò”
	int Attack[3]{100,50,250};  //–`Œ¯Ò‚ÌUŒ‚—Í
	int Defence[3]{50,50,100};  //–`Œ¯Ò‚Ì–hŒä—Í
	int Skill[3]{100,100,220};  //–`Œ¯Ò‚Ì‹Zp
	int Know[3]{50,100,150};  //–`Œ¯Ò‚Ì’m¯
	int Physical[3]{3,3,4};  //–`Œ¯Ò‚Ì‘Ì—Í
	int good[3]{ 1,2,3 };    //–`Œ¯Ò‚ÌƒNƒGƒXƒg‚Ì“¾ˆÓ•s“¾ˆÓ
	const int AdventurerCost[3]{};  //–`Œ¯Ò‚Éx•¥‚¤ƒRƒXƒg

private:
	static std::unordered_map<std::string, int> _status;
   	

};

	//map["Key1"] = 20,30,40;