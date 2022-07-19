#pragma once
//#include"Quest.h"



class Math{
public:
	Math();     //コンストラクタ
	~Math();   //デストラクタ
	void Math_Update(int& no);
	//int Money_Update() { return no; }
  bool Judgement();

private:
	//Quest quest;
	int no;
};
