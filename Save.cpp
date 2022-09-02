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
	fopen_s(&fp, "セーブデータ.dat", "wb"); // ファイルを開く
	if (fp == NULL) { // NULLが返ってきたらエラー発生
		return ;
	}
	fwrite(&math.mymoney, sizeof(int), 1, fp); // ファイルにmoneyの値を出力する
	fclose(fp); //ファイルを閉じる
	
}

void Save::Info_Load() {
	FILE* fp;
	
	fopen_s(&fp, "セーブデータ.dat", "rb");

	if (fp == NULL) {
		DrawString(100, 100, "クエスト2", TRUE);
		printf("ファイルを開けませんでした");
	}
	
	fread(&math.mymoney, sizeof(int),1, fp);
		fclose(fp);
//	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%s\n",ch);
	DrawFormatString(1000, 100, GetColor(255, 255, 255), "%d\n",math.mymoney);
	//printf("書き込まれた文字は→%s\n", ch);
}
