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
		 クエスト1
		,クエスト2
		,クエスト3
		,クエスト4
		,クエスト5
		,クエスト6
	};

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _cg;
};
