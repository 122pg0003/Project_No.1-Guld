#include"Game.h"
#include"DxLib.h"

//�R���X�g���N�^
Game::Game() :
	scenemgr(*this)
	, mouse(*this)
	, aabb(*this) 
	
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
	mouse.M();

}
