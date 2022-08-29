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

	FILE* fp;
	char ch[50] = "ABCDEFGH";
void Save::Info_Save() {
	
	int a;
	FILE* fp;
	errno_t error;

	error = fopen_s(&fp, "save.txt", "wb");

	fwrite(ch, 1, 6, fp);

	if (error != 0) {
		DrawString(100, 100, "�N�G�X�g2", TRUE);
		printf("�t�@�C�����J���܂���ł���");
	}
	else {
		while ((a = fgetc(fp)) != EOF)
			putchar(a);
		putchar('\n');
		fclose(fp);
	}

	
	

	//FILE* fp;
	//char ch[50] = "ABCDEFGH";
	//// �n�C�X�R�A�Z�[�u�p�t�@�C�����J��
	//// (�Q�Ԗڂ̈�����"wb"��'w'�́u�������݁v�̈Ӗ�
	//// 'b'�̓o�C�i���̈Ӗ�(�t�̓e�L�X�g))
	//fp = fopen("test.txt", "wb");

	//// �I�[�v���ł��Ȃ������炱���ŏI��
	//if (fp == NULL) return;

	//// �n�C�X�R�A�f�[�^�̏����o��
	//fwrite(ch, 1, 6, fp);

	//// �t�@�C�������
	//fclose(fp);


}

void Save::Info_Load() {
	
	errno_t error;

	error = fopen_s(&fp, "save.txt", "rb");

	fgets(ch, 50, fp);

	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%s\n",ch);
	//printf("�������܂ꂽ�����́�%s\n", ch);

	fclose(fp);

}
