#include"SceneMgr.h"
#include"DxLib.h"

//�R���X�g���N�^
SceneMgr::SceneMgr(Game& game)
  :_game(game)
  ,adventurer(*this,_game)
  ,menu(*this,_game)
  
{
  _bg = LoadGraph("images/Scene_Config.png");
}

//�f�X�g���N�^
SceneMgr::~SceneMgr() {

}

//����
void SceneMgr::Scene_Input() {
  switch (scene) {
  case eScene::Menu:
    menu.Menu_Input();
    break;
  case eScene::Adventurer:
    adventurer.Adventurer_Input();
    break;
  }
}

//�X�V
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
  switch (scene) {
  case eScene::Menu:
  menu.Menu_Render();
    break;
  /*case eScene::Adventurer:
    adventurer.Adventurer_Input();
    break;*/
  }
}

void SceneMgr::SceneMgr_ChangeScene(eScene nextScene) {
 scene = nextScene;
}
