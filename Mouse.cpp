#include"Mouse.h"
#include"DxLib.h"

Mouse::Mouse(Game& game) :
_game(game)
{

}

Mouse::~Mouse() {

}

void Mouse::M() {
  // �}�E�X��\����Ԃɂ���
  SetMouseDispFlag(TRUE);

  // ���F�̒l���擾
  StringCr = GetColor(255, 255, 255);

  // ���̒l���擾
  BoxCr = GetColor(0, 0, 0);

  // �}�E�X�̈ʒu���擾
  GetMousePoint(&MouseX, &MouseY);

  // ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
  DrawBox(0, 0, 640, 32, BoxCr, TRUE);

  // ���W�������`��
  DrawFormatString(1000, 50, StringCr, "���W�w %d�@�@���W�x %d", MouseX, MouseY);
 // DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", Rot);
  // ���b�Z�[�W����


  // ��莞�ԑ҂�
  //WaitTimer(100);
}

