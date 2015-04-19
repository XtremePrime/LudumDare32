#include "mob.h"

#define TILESCALE 32

void Mob::init(sf::Vector2f c, Level level)
{
    this->txr.loadFromFile("res/entities/Jimi.png");
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);

	dir = Direction::RIGHT;
}

bool Mob::hasCollision(Tile* tile)
{
	if(tile->may_pass() == true)
		return false;
	return true;
}

void Mob::move(sf::Vector2f c)
{
	this->coord.x += c.x;
	this->coord.y += c.y;

	//- Set direction
	if(c.y == -1) 
		dir = Direction::UP;
	else if(c.y == 1) 
		dir = Direction::DOWN;
	if(c.x == -1)
		dir = Direction::LEFT;
	else if(c.x == 1)
		dir = Direction::RIGHT;

	//- Flip model if dir
	if(dir == Direction::LEFT)
		spr.setTextureRect(sf::IntRect(32, 0, -32, 32));
	else if(dir == Direction::RIGHT)
		spr.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Mob::handle_events(sf::Event event)
{

}

void Mob::update(sf::Time deltaTime)
{
	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);
}

void Mob::render(sf::RenderWindow *window)
{
    window->draw(spr);
}

