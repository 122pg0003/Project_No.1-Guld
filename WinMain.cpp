#include <memory>
#include "DxLib.h"
#include "Game.h"
#include"Audio.h"
#include"Ending.h"

enum GameMode
{
  MODE_TITLE,
  MODE_GAME,
  MODE_ENDING,
};



// �v���O������WinMain ����n�܂�܂�
int WINAPI WinMain(
  HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow) {
  ChangeWindowMode(TRUE);    // �E�C���h�E���[�h�ɕύX
  SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);    // ��ʂ̉𑜓x(��,����)�ƐF��(32bit)���w��
  DxLib_Init();    // Dx���C�u����������
  SetDrawScreen(DX_SCREEN_BACK);    // �`����ʂ𗠂ɂ���

  GameMode nowSelectGameMode = MODE_TITLE;

  //���j�[�N�|�C���^������Ă���
  auto game = std::make_unique<Game>();

  auto title = std::make_unique<Title>(*game);
  auto ending = std::make_unique<Ending>(*game);
  auto audio = std::make_unique<Audio>();

  if (nowSelectGameMode == GameMode::MODE_GAME) {
    audio->Main_Audio();
  }

  //game->SetRandom();

  //���C�����[�v
  while (ProcessMessage() != -1) {
    //ESCAPE�ŏI��
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
      break;
    }

    switch (nowSelectGameMode)
    {
    case MODE_TITLE:
    {
      if (title->Title_Update() == 1)
      {
        nowSelectGameMode = MODE_GAME;
      }
      title->Title_Render();
      break;
    }
    case MODE_GAME:
    {
      // �Q�[���̏���
      game->Input();    // ����
      game->Update();   // �X�V
      game->Clear();    //�z��̏�����
      ending->Render();
      //game->Render();   // �`��
      game->Check();    //�G�ꂽ���̃`�F�b�N
      if (game->EndingFlag == 1) {
        nowSelectGameMode = MODE_ENDING;
      }
      break;
    }
    case MODE_ENDING:
    { 
      ending->Update();
     ending->Render();
    if (game->_mousetrg != 0 && ending->EDcount == 9) {
      nowSelectGameMode = MODE_GAME;
      ending->EDcount = 1;
    }

    if (game->_mousetrg != 0 && game->EndingFlag == 2) {
      title->_isSelectGameMode = false;

      nowSelectGameMode = MODE_TITLE;
    }

    break;
    }
    default:
      break;
    }
  }

  // Dx���C�u�����I��
  DxLib_End();

  return 0;
}
