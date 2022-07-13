#pragma once

class SceneMgr;
class Game;

class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //コンストラクタ
	~Quest();                              //デストラクタ
	void Quest_Input();                    //入力
	void Quest_Update();                   //更新
	void Quest_Render();                   //描画

protected:
	Game& _game;
	SceneMgr& _scenemgr;

private:
	enum class MENU_NUM {
		  メニュー
		,クエスト1
		,クエスト2
		,クエスト3
		,クエスト4
		,クエスト5
		,クエスト6
	};

	enum class Q {
		Q1
	 ,Q2
	 ,Q3
	 ,Q4
	 ,Q5
   ,Q6
	};
	Q  q;

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _cg;
	int _BIGrHandle;
	int Q1GrHandle;
	int Q2GrHandle;
	int Q3GrHandle;
	int Q4GrHandle;
	int Q5GrHandle;
	int Q6GrHandle;
 
};
