#include"Game.h"
#include"DxLib.h"

//�R���X�g���N�^
Game::Game() :
scenemgr(*this)
,mouse(*this)
{

}

//�f�X�g���N�^
Game::~Game() {

}

//����
void Game::Input() {
	scenemgr.Scene_Input();
}

//�X�V
void Game::Update() {
	scenemgr.Scene_Update();

}

//�`��
void Game::Render() {
	DrawString(0, 20, "G�L�[�ŃQ�[����ʁAC�L�[�Őݒ�AM�L�[�Ń��j���[��ʂɂȂ�܂��B", GetColor(255, 255, 255));
}

//
//void Game::M(){
//  // �}�E�X��\����Ԃɂ���
//  SetMouseDispFlag(TRUE);
//
//  // ���F�̒l���擾
//  StringCr = GetColor(255, 255, 255);
//
//  // ���̒l���擾
//  BoxCr = GetColor(0, 0, 0);
//
//    // �}�E�X�̈ʒu���擾
//    GetMousePoint(&MouseX, &MouseY);
//
//    // ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
//    DrawBox(0, 0, 640, 32, BoxCr, TRUE);
//
//    // ���W�������`��
//    DrawFormatString(0, 0, StringCr, "���W�w %d�@�@���W�x %d", MouseX, MouseY);
//
//    // ���b�Z�[�W����
//  
//
//    // ��莞�ԑ҂�
//    WaitTimer(100);
//}

