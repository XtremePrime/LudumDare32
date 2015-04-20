#include "player.h"

#define TILESCALE 32

void Player::init(sf::Vector2f c, Level level, int charclass)
{
	std::string playermodel;
	int randop = rand()%2;
	switch(charclass){
		case 0: //- Warrior
			playermodel = (randop == 0 ? "res/entities/warr_bow.png" : "res/entities/warr_staff.png");
		break;
		case 1: //- Archer
			playermodel = (randop == 0 ? "res/entities/archer_sword.png" : "res/entities/archer_wand.png");
		break;
		case 2: //- Wizard
			playermodel = (randop == 0 ? "res/entities/wizard_sword.png" : "res/entities/wizard_bow.png");
		break;
	}
	this->txr.loadFromFile(playermodel);
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);

	dir = Direction::RIGHT;

	this->hp = 10;
	this->max_hp = 10;
	this->lvl = 1;
	this->dmg = 1;
}

bool Player::hasCollision(Tile* tile)
{
	if(tile->may_pass() == true)
		return false;
	return true;
}

void Player::move(sf::Vector2f c)
{
	//- Update coords
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

void Player::handle_events(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::E || event.key.code == sf::Keyboard::Return){
			std::cout << "Action!\n";
		}
	}
}

void Player::update(sf::Time deltaTime)
{
	if(this->hp <= 0)
		is_dead = true;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(spr);
}
