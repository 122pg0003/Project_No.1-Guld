#include"Collision.h"
#include"Game.h"

AABB::AABB(Game& game):
	_game(game){

}

AABB::~AABB() {

}

//Ž®‚É“–‚Ä‚Í‚Ü‚Á‚Ä‚¢‚½‚çHit
bool AABB::CheckHit() {
	//(_game.GetMouseX() < 170) && (_game.GetMouseX() > 40)) && (_game.GetMouseY() < 290) && (_game.GetMouseY() > 260)
	if (_game.GetMouseX() <  max.x && _game.GetMouseX() > min.x ) {
		return false;
	}
	if (_game.GetMouseY() <  max.y && _game.GetMouseY() > min.y) {
		return false;
	}
	return true;
}