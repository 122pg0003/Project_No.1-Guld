#pragma once
#include<array>

class SceneMgr;
class Game;

class Guild {
public:
	Guild(SceneMgr& scenemgr, Game& game);
	~Guild();
	void Guild_Input();
	void Guild_Update();
	void Guild_Render();
	//�{�݂��Ƃ̃��x��
	std::array<int, 14> Lv{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0 };

protected:
	Game& _game;
	SceneMgr& _scenemgr;
	

private:
	enum class MENU_NUM {
		Return,  //���j���[�ɖ߂�
		GuildMenu,  //���j���[
		Up, //����
		Down,  //�����
		Set,  //�ݒu
		Guild,  //�M���h�g��
		Bar,  //����
		Theater,  //������
		Bath,  //�嗁��
		Dining,  //�H��
		Newspaper,  //�V�����s��
		Weapon,  //���퉮
		Armor,  //�h�
		Church,  //����
		Rifle,  //�ˌ���
		Sword,  //���p��
		Training,  //�b�B��
		Atelier,  //�A�g���G
		Library,  //�}����
		Null = -1,  //���I��

	};

	MENU_NUM pattern;
	MENU_NUM oldpattern;
	MENU_NUM nowSelectedPattern;

	void GetMenuPosition(MENU_NUM menuIndex, int& max_x, int& min_x, int& max_y, int& min_y);
	int _BIGrHandle{ -1 };
	int _BuildingSlotGrHandle{ -1 };
	int _BuildingGrHandle{ -1 };
	int _ButtonGrHandle{ -1 };

	int upGrHandle{ -1 };  //����
	int downGrHandle{ -1 };  //�����
	int setGrHandle{ -1 };  //�ݒu�{�^��
	int g_0GrHandle{ -1 };  //�I��g

	int g_1GrHandle{ -1 };  //1�̓M���h����
	int g_1_1GrHandle{ -1 };
	int g_1_2GrHandle{ -1 };
	int g_1_3GrHandle{ -1 };

	int g_2GrHandle{ -1 };  //2�͎���
	int g_2_1GrHandle{ -1 };
	int g_2_2GrHandle{ -1 };
	int g_2_3GrHandle{ -1 };

	int g_3GrHandle{ -1 };  //3�͉�����
	int g_3_1GrHandle{ -1 };
	int g_3_2GrHandle{ -1 };
	int g_3_3GrHandle{ -1 };

	int g_4GrHandle{ -1 };  //4�͑嗁��
	int g_4_1GrHandle{ -1 };
	int g_4_2GrHandle{ -1 };
	int g_4_3GrHandle{ -1 };

	int g_5GrHandle{ -1 };  //5�͐H��
	int g_5_1GrHandle{ -1 };
	int g_5_2GrHandle{ -1 };
	int g_5_3GrHandle{ -1 };

	int g_6GrHandle{ -1 };  //6�͐V�����s��
	int g_6_1GrHandle{ -1 };
	int g_6_2GrHandle{ -1 };
	int g_6_3GrHandle{ -1 };

	int g_7GrHandle{ -1 };  //7�͕��퉮�@�����܂�1�y�[�W��
	int g_7_1GrHandle{ -1 };
	int g_7_2GrHandle{ -1 };
	int g_7_3GrHandle{ -1 };

	int g_8GrHandle{ -1 };  //8�͖h�
	int g_8_1GrHandle{ -1 };
	int g_8_2GrHandle{ -1 };
	int g_8_3GrHandle{ -1 };

	int g_9GrHandle{ -1 };  //9�͋���
	int g_9_1GrHandle{ -1 };
	int g_9_2GrHandle{ -1 };
	int g_9_3GrHandle{ -1 };

	int g_10GrHandle{ -1 };  //10�͎ˌ���
	int g_10_1GrHandle{ -1 };
	int g_10_2GrHandle{ -1 };
	int g_10_3GrHandle{ -1 };

	int g_11GrHandle{ -1 };  //11�͌��p��
	int g_11_1GrHandle{ -1 };
	int g_11_2GrHandle{ -1 };
	int g_11_3GrHandle{ -1 };

	int g_12GrHandle{ -1 };  //12�͒b�B��
	int g_12_1GrHandle{ -1 };
	int g_12_2GrHandle{ -1 };
	int g_12_3GrHandle{ -1 };

	int g_13GrHandle{ -1 };  //13�̓A�g���G
	int g_13_1GrHandle{ -1 };
	int g_13_2GrHandle{ -1 };
	int g_13_3GrHandle{ -1 };

	int g_14GrHandle{ -1 };  //14�͐}����
	int g_14_1GrHandle{ -1 };
	int g_14_2GrHandle{ -1 };
	int g_14_3GrHandle{ -1 };

	int ScreenNo;
};