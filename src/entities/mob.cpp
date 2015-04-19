#include "mob.h"

void Mob::init(){

    this->txr.loadFromFile("res/Tiles/Jimi.png");
	this->spr.setTexture(txr);
}

void Mob::move(){


}

void Mob::render(sf::RenderWindow *window){

    window->draw(spr);
}

