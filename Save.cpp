#include"Save.h"
#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"


Save::Save(SceneMgr& scenemgr,Game& game): 
	_scenemgr(scenemgr),
		_game(game)
{
	
}

Save::~Save() {

}

	//FILE* fp;
	char ch[50] = "ABCDEFGH";
	int money = 1000000;
void Save::Info_Save() {

	
	FILE* fp;
	fopen_s(&fp, "�Z�[�u�f�[�^.dat", "wb"); // �t�@�C�����J��
	if (fp == NULL) { // NULL���Ԃ��Ă�����G���[����
		return ;
	}
	fwrite(&math.mymoney, sizeof(int), 1, fp); // �t�@�C����money�̒l���o�͂���
	fclose(fp); //�t�@�C�������
	
}

void Save::Info_Load() {
	FILE* fp;
	
	fopen_s(&fp, "�Z�[�u�f�[�^.dat", "rb");

	if (fp == NULL) {
		DrawString(100, 100, "�N�G�X�g2", TRUE);
		printf("�t�@�C�����J���܂���ł���");
	}
	
	fread(&math.mymoney, sizeof(int),1, fp);
		fclose(fp);
//	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%s\n",ch);
	DrawFormatString(1000, 100, GetColor(255, 255, 255), "%d\n",math.mymoney);
	//printf("�������܂ꂽ�����́�%s\n", ch);
}
