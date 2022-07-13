#include"SceneMgr.h"
#include"DxLib.h"

//�R���X�g���N�^
SceneMgr::SceneMgr(Game& game)
  :_game(game)
  ,adventurer(*this,_game)
  ,menu(*this,_game)
  ,quest(*this,_game)
  ,guild(*this,_game)
  ,trede(*this, _game)
  ,investment(*this, _game)
  ,nextmonth(*this, _game)
{
  //_bg = LoadGraph("images/Scene_Config.png");
  _bg = LoadGraph("images/back_Full.png");
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
  case eScene::Quest:
    quest.Quest_Input();
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


//�X�V
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
 // DrawGraph(0, 0, _bg, TRUE);
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
