#pragma once

class SceneMgr;
class Game;

class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //�R���X�g���N�^
	~Quest();                              //�f�X�g���N�^
	void Quest_Input();                    //����
	void Quest_Update();                   //�X�V
	void Quest_Render();                   //�`��

protected:
	Game& _game;
	SceneMgr& _scenemgr;

private:
	enum class MENU_NUM {
		 �N�G�X�g1
		,�N�G�X�g2
		,�N�G�X�g3
		,�N�G�X�g4
		,�N�G�X�g5
		,�N�G�X�g6
	};

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _cg;
};
