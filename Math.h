#pragma once
#include"Adventurer_Status.h"
//#include"Quest.h"



class Math {
public:
	Math();     //コンストラクタ
	 ~Math();   //デストラクタ
	 void Math_Update();
	 void Math_Render();
	 void Guild_B();
	 void Success(int& SuccessRate, int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
	 void Set(int Lv);
	 void Info_Save();
	 void Info_Load();

	int SuccessRate;//クエストの成功率　各ステータスが必要量まであったら＋２５、最低０で最高１００
	int _questresult = -1;
	int Fame{ 0 };  //名声値
  //int mymoney;

	 void BarEffect(int Lv);
	 void TheaterEffect(int Lv);//Bar,Theaterは効果が同じだから一緒にしてもいいかも
	 void BathEffect(int Lv);
	 void DainingEffect(int Lv);
	 void NewspaperEffect(int Lv);
	 void WeaponEffect(int Lv);
	 void ArmorEffect(int Lv);
	 void ChurchEffect(int Lv);
	 void RifleEffect(int Lv);
	 void SwordEffect(int Lv);
	 void TrainingEffect(int Lv);
	 void AtelierEffect(int Lv);
	 void LibraryEffect(int Lv);
   void GuildCost(int Lv);

	//int Money_Update() { return no; }
	bool Judgement(int ClearTotalAttack, int ClearTotalDefence, int ClearTotalSkill, int ClearTotalKnow, int TotalAttack, int TotalDefence, int TotalSkill, int TotalKnow);
	const int AddSuccessrate = 25;  //成功率、ステータスが一つ必要量になったら＋される
protected:
	//int mymoney;

private:
	int no;
	Adventurer_Status status;
};
//int mymoney = 10000;
