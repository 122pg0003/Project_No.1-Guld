#pragma once
#include"Adventurer_Status.h"
#include<string>
//#include"Quest.h"



class Math {
public:
	Math();     //�R���X�g���N�^
	 ~Math();   //�f�X�g���N�^
	 void Math_Update();
	 void Math_Render();
	 void Guild_B();
	 void Success(int& SuccessRate, int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
	 void Set(int Lv);
	 void Info_Save();
	 void Info_Load();
	 int FameNo();
	 int GetMymoney();
	 int GetFame();

	int SuccessRate;//�N�G�X�g�̐������@�e�X�e�[�^�X���K�v�ʂ܂ł�������{�Q�T�A�Œ�O�ōō��P�O�O
	int _questresult = -1;
	//int Fame{ 0 };  //�����l
  //int mymoney;
	//int GetFame() { return  Fame; }

	void BathEffect(int Lv);
	void DiningEffect(int Lv);
	void NewspaperEffect(int Lv);
	void WeaponEffect(int Lv);
	void ArmorEffect(int Lv);
	void ChurchEffect(int Lv);
	void RifleEffect(int Lv);
	void SwordEffect(int Lv);
	void TrainingEffect(int Lv);
	void AtelierEffect(int Lv);
	void LibraryEffect(int Lv);

	void WeaponDelete(int Lv);
	void ArmorDelete(int Lv);
	void ChurchDelete(int Lv);
	void RifleDelete(int Lv);


	void GuildCost(int Lv);


	//int Money_Update() { return no; }
	bool Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
	const int AddSuccessrate = 25;  //�������A�X�e�[�^�X����K�v�ʂɂȂ�����{�����
protected:
	//int mymoney;

private:
	int no;
	Adventurer_Status status;
	int width;
	int widthFame;
	
	//int Fame{ 0 };  //�����l

};
//int mymoney = 10000;
