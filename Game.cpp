#include"Game.h"
#include"DxLib.h"

//�R���X�g���N�^
Game::Game() {

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
