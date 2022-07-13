#include"SceneMgr.h"
#include"DxLib.h"

//コンストラクタ
SceneMgr::SceneMgr(Game& game)
  :_game(game)
  ,adventurer(*this,_game)
  ,menu(*this,_game)
  ,quest(*this,_game)
  ,guild(*this,_game)
{
  _bg = LoadGraph("images/Scene_Config.png");
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
  // Config_Update();
    break;
  case eScene::Investment:
   // Config_Update();
    break;
  case eScene::NextMonth:
   // Config_Update();
    break;
  }
}

void SceneMgr::Scene_Render() {
  switch (scene) {
  case eScene::Menu:
  menu.Menu_Render();
    break;
  case eScene::Quest:
    quest.Quest_Render();
    break;
 /*case eScene::Adventurer:
    adventurer.Adventurer_Render();
    break;*/
  }
}

void SceneMgr::SceneMgr_ChangeScene(eScene nextScene) {
 scene = nextScene;
}
