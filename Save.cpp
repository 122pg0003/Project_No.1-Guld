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
		DrawString(100, 100, "クエスト2", TRUE);
		printf("ファイルを開けませんでした");
	}
	else {
		while ((a = fgetc(fp)) != EOF)
			putchar(a);
		putchar('\n');
		fclose(fp);
	}

	
	

	//FILE* fp;
	//char ch[50] = "ABCDEFGH";
	//// ハイスコアセーブ用ファイルを開く
	//// (２番目の引数の"wb"の'w'は「書きこみ」の意味
	//// 'b'はバイナリの意味(逆はテキスト))
	//fp = fopen("test.txt", "wb");

	//// オープンできなかったらここで終了
	//if (fp == NULL) return;

	//// ハイスコアデータの書き出し
	//fwrite(ch, 1, 6, fp);

	//// ファイルを閉じる
	//fclose(fp);


}

void Save::Info_Load() {
	
	errno_t error;

	error = fopen_s(&fp, "save.txt", "rb");

	fgets(ch, 50, fp);

	DrawFormatString(1000, 45, GetColor(255, 255, 255), "%s\n",ch);
	//printf("書き込まれた文字は→%s\n", ch);

	fclose(fp);

}
