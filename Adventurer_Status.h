#pragma once
#include<unordered_map>

class Adventurer_Status {
public:
	Adventurer_Status();
	~Adventurer_Status();
	int Find(std::string status);
	const int AdventurerMember[10]{};  //�`���Ґ�
	int Attack[3]{100,50,250};  //�`���҂̍U����
	int Defence[3]{50,50,100};  //�`���҂̖h���
	int Skill[3]{100,100,220};  //�`���҂̋Z�p
	int Know[3]{50,100,150};  //�`���҂̒m��
	int Physical[3]{3,3,4};  //�`���҂̗̑�
	int good[3]{ 1,2,3 };    //�`���҂̃N�G�X�g�̓��ӕs����
	const int AdventurerCost[3]{};  //�`���҂Ɏx�����R�X�g

private:
	static std::unordered_map<std::string, int> _status;
   	

};

	//map["Key1"] = 20,30,40;