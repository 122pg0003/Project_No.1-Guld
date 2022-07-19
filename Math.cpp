#include"Math.h"
#include"Dxlib.h"



//コンストラクタ
Math::Math()


{
	
	no = 0;
}


//デストラクタ
Math::~Math() {

}


void Math::Math_Update(int& no) {
	no = 0;
	//int i;
	//_quest.GetMoney(i);
	no++;

	
}


bool Math::Judgement() {
	no = rand() % 100 + 1;
	return   no <= 50;
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "ランダム数%d\n", no);


	/*no = rand() % 100 + 1;
	if (no <= 50) {
		graph->DrawC();
	}
	else {
		graph->DrawF();
	}
	ScreenFlip();*/

}

