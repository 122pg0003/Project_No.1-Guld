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
		�`����1
		,�`����2
		,�`����3
		,�`����4
		,�`����5
		,�`����6
	};

	MENU_NUM scene;
	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
};
