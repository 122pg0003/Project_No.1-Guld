#pragma once
#include"Math.h"

class SceneMgr;
class Game;



class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //コンストラクタ
	~Quest();                              //デストラクタ
	void Quest_Input();                    //入力
	void Quest_Update();                   //更新
	void Quest_Render();                   //描画
	//void GetMoney(int& i);
	                

protected:
	Game& _game;
	SceneMgr& _scenemgr;
	Math& _math;


private:
	enum class MENU_NUM {
		  メニュー
		,クエスト1
		,クエスト2
		,クエスト3
		,クエスト4
		,クエスト5
		,クエスト6
		,QInside
		,QInside1
		,QInside2
		,クエスト開始
	};

	enum class Q {
		Qメニュー
		,Q1
		,Q2
		,Q3
		,Qクエスト判定
	};

	Q q;



	MENU_NUM scene{};
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _cg;
	int _BIGrHandle;
	int Q1GrHandle;
	int Q2GrHandle;
	int Q3GrHandle;
	int Q4GrHandle;
	int Q5GrHandle;
	int Q6GrHandle;
	int _cg1;
	int Q1;
	int Q2;
	int Q3;
	int menu;
	int clear;
	int failure;
};
