#include"SceneMgr.h"
#include"DxLib.h"
//#include"Math.h"



//コンストラクタ
SceneMgr::SceneMgr(Game& game)
	:_game(game)
	, adventurer(*this, _game)
	, menu(*this, _game)
	, quest(*this, _game)
	, guild(*this, _game)
	, trede(*this, _game)
	, investment(*this, _game)
	, nextmonth(*this, _game)
	//, title(*this, _game)
	, save(*this, _game)
	//,math(*this)


{
	//_bg = LoadGraph("images/Scene_Config.png");
	_bg = LoadGraph("images/back_Full.png");
	_bg1 = LoadGraph("images/gi_001.png");  //ホーム画面
	_bg2 = LoadGraph("images/topber_red.png");
}

//デストラクタ
SceneMgr::~SceneMgr() {

}

//入力
void SceneMgr::Scene_Input() {
	switch (scene) {
	case eScene::Menu:
		menu.Menu_Input();
		break;
	case eScene::Adventurer:
		adventurer.Adventurer_Input();
		break;
	case eScene::Quest:
		quest.Quest_Input();
		break;
	case eScene::QuestEnd:  //クエスト完了時のリザルト画面
		quest.Quest_Result();
		break;
	case eScene::Guild:
		guild.Guild_Input();
		break;
	case eScene::Trede:
		trede.Trede_Input();
		break;
	case eScene::Investment:
		investment.Investment_Input();
		break;
	case eScene::NextMonth:
		nextmonth.NextMonth_Input();
		break;
		/*case eScene::Quest:
			quest.Quest_Input();
			break;*/
	}
}


//更新
void SceneMgr::Scene_Update() {
	switch (scene) {
	case eScene::Menu:
		menu.Menu_Update();
		break;
	case eScene::Quest:
		quest.Quest_Update();
		break;
	case eScene::Adventurer:
		adventurer.Adventurer_Update();
		break;
	case eScene::Guild:
		guild.Guild_Update();
		break;
	case eScene::Trede:
		trede.Trede_Update();
		break;
	case eScene::Investment:
		investment.Investment_Update();
		break;
	case eScene::NextMonth:
		nextmonth.NextMonth_Update();
		break;
	}
}

void SceneMgr::Scene_Render() {

	DrawGraph(0, 0, _bg1, TRUE);
	DrawGraph(0, 0, _bg2, TRUE);
	switch (scene) {
	case eScene::Menu:
		menu.Menu_Render();
		break;
	case eScene::Quest:
		quest.Quest_Render();
		break;
	case eScene::Adventurer:
		adventurer.Adventurer_Render();
		break;
	case eScene::Guild:
		guild.Guild_Render();
		break;
	case eScene::Trede:
		save.Info_Save();
		//trede.Trede_Render();
		break;
	case eScene::Investment:
		save.Info_Load();
		//investment.Investment_Render();
		break;

	}
	math.Math_Render();
	menu.HomeMenu_Render();
}

void SceneMgr::SceneMgr_ChangeScene(eScene nextScene) {
	scene = nextScene;
}
