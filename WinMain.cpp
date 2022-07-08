#include <memory>
#include "DxLib.h"
#include "Game.h"


// �v���O������WinMain ����n�܂�܂�
int WINAPI WinMain(
  HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow) {
  ChangeWindowMode(TRUE);    // �E�C���h�E���[�h�ɕύX
  SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);    // ��ʂ̉𑜓x(��,����)�ƐF��(32bit)���w��
  DxLib_Init();    // Dx���C�u����������
  //SetDrawScreen(DX_SCREEN_BACK);    // �`����ʂ𗠂ɂ���

  
  auto game = std::make_unique<Game>();


  while (ProcessMessage() != -1) {
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
      break;
    }
    // �Q�[���̏���
    game->Input();    // ����
    game->Update();   // �X�V
    game->Render();   // �`��
   //game->M();
  }

  // Dx���C�u�����I��
  DxLib_End();

  return 0;
}
