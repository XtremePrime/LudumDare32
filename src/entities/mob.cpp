#include "mob.h"

#define TILESCALE 32

Mob::Mob(sf::Vector2f c, Level level)
{
	this->txr.loadFromFile("res/entities/rat_liviu.png"); // also for testing pourpose
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);

	dir = Direction::RIGHT;
}

void Mob::init(sf::Vector2f c, Level level)
{
    this->txr.loadFromFile("res/entities/rat_liviu.png"); // yeah ... this one too
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

sf::Vector2f Mob::generate_move(Level level)
{
	sf::Vector2f c;
	do{
		c.x = rand()%3-1;
		c.y = rand()%3-1;
		std::cout << "Attempted: " << c.x << "/" << c.y << "| hasCol: " << hasCollision(level.get_tile((int)(get_x()+c.x), (int)(get_y()+c.y))) << "\n";
	}while(hasCollision(level.get_tile((int)(get_x()+c.x), (int)(get_y()+c.y))));
	std::cout << "Generated: " << c.x << "/" << c.y << "\n";
	return c;
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

