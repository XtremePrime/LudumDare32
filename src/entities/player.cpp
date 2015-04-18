#include "player.h"

// Player::Player(int mh,int md,int Md){
//     this->max_hp = mh;
//     this->min_dmg = md;
//     this->max_dmg = Md;

//     this->lvl = 1;
//     this->xp = 0;
//     this->hp = max_hp;
// }

void Player::init()
{
	this->txr.loadFromFile("res/Tiles/warr_bow.png");
}
