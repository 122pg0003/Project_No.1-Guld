#include"SceneMgr.h"
#include"DxLib.h"

//コンストラクタ
SceneMgr::SceneMgr(Game& game)
  :_game(game)
  ,adventurer(*this,_game)
  ,menu(*this)
  
{
  _bg = LoadGraph("images/Scene_Config.png");
}

//デストラクタ
SceneMgr::~SceneMgr() {

}

void SceneMgr::Scene_Input() {
}

void SceneMgr::Scene_Update() {
  menu.Menu_Input();
  adventurer.Adventurer_Input();
  switch (scene) {       
  case eScene::Menu:   
    menu.Menu_Update();   
    break;
  case eScene::Adventurer:
    adventurer.Adventurer_Update();
    break;
  case eScene::Guild:
   // Config_Update();
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
  case eScene::Game:
    DrawGraph(0, 0, _bg, FALSE);

  }
}

void SceneMgr::Scene_Render() {
  menu.Menu_Render();
}

void SceneMgr::SceneMgr_ChangeScene(eScene nextScene) {
 scene = nextScene;
}
