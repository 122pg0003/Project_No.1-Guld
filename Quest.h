#pragma once
#include"Math.h"

class SceneMgr;
class Game;



class Quest {
public:
	Quest(SceneMgr& scenemgr,Game& game);  //�R���X�g���N�^
	~Quest();                              //�f�X�g���N�^
	void Quest_Input();                    //����
	void Quest_Update();                   //�X�V
	void Quest_Render();                   //�`��
	//void GetMoney(int& i);
	                

protected:
	Game& _game;
	SceneMgr& _scenemgr;
	Math& _math;


private:
	enum class MENU_NUM {
		  ���j���[
		,�N�G�X�g1
		,�N�G�X�g2
		,�N�G�X�g3
		,�N�G�X�g4
		,�N�G�X�g5
		,�N�G�X�g6
		,QInside
		,QInside1
		,QInside2
		,�N�G�X�g�J�n
	};

	enum class Q {
		Q���j���[
		,Q1
		,Q2
		,Q3
		,Q�N�G�X�g����
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
