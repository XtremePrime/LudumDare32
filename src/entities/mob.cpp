#include "mob.h"

#define TILESCALE 32

Mob::Mob(sf::Vector2f c, Level level, int type)
{
	init(c, level, type);
}

void Mob::init(sf::Vector2f c, Level level, int type)
{
	std::string enemymodel;
	switch(type){
		case 0: //- Jimmy
			enemymodel = "res/entities/Jimi.png";
		break;
		case 1: //- Liviu's Rat
			enemymodel = "res/entities/rat_liviu.png";
		break;
	}
    this->txr.loadFromFile(enemymodel);
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);

	dir = Direction::RIGHT;

	this->hp = 10;
	this->max_hp = 10;
	this->lvl = 1;
	this->dmg = 3;
}

bool Mob::hasCollision(Tile* tile)
{
	if(tile->may_pass() == true)
		return false;
	return true;
}

sf::Vector2f Mob::generate_move(Level level)
{
	sf::Vector2f c;
	do{
		c.x = rand()%3-1;
		c.y = rand()%3-1;
		// std::cout << "Attempted: " << c.x << "/" << c.y << "| hasCol: " << hasCollision(level.get_tile((int)(get_x()+c.x), (int)(get_y()+c.y))) << "\n";
	}while(hasCollision(level.get_tile((int)(get_x()+c.x), (int)(get_y()+c.y))));
	// std::cout << "Generated: " << c.x << "/" << c.y << "\n";
	return c;
}

bool Mob::canLocatePlayer(Player p)
{
	// std::cout << "p.get_x()-coord.x: " << p.get_x()-coord.x << "\n";
	if( (p.get_x()-coord.x >= -1 && p.get_x()-coord.x <= 1) ||
		(p.get_y()-coord.y >= -1 && p.get_y()-coord.y <= 1))
		return true;
	return false;
}

bool Mob::hitsPlayer(Tile* tile, Player p)
{

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
	if(this->hp <= 0){
		is_dead = true;
	}

	if(!is_dead)
		spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);
}

void Mob::render(sf::RenderWindow *window)
{
	if(!is_dead)
    	window->draw(spr);
}

