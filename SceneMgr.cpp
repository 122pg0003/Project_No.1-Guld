#include"SceneMgr.h"
#include"DxLib.h"

//コンストラクタ
SceneMgr::SceneMgr()
  :adventurer(*this)
  ,menu(*this)
{

}

//デストラクタ
SceneMgr::~SceneMgr() {

}

void SceneMgr::Scene_Input() {
  menu.Menu_Input();
  adventurer.Adventurer_Input();
}

void SceneMgr::Scene_Update() {
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
  }
}

void SceneMgr::Scene_Render() {
  menu.Menu_Render();
}

void SceneMgr::SceneMgr_ChangeScene(eScene nextScene) {
 scene = nextScene;
}
