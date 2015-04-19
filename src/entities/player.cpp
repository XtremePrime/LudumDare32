#include "player.h"

#define TILESCALE 32

void Player::init(sf::Vector2f c, Level level)
{
	this->txr.loadFromFile("res/Tiles/warr_bow.png");
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);

	dir = Direction::RIGHT;
}

bool Player::hasCollision(Tile* tile)
{
	if(tile->may_pass() == true)
		return false;
	return true;
}

void Player::move(sf::Vector2f c)
{
	this->coord.x += c.x;
	this->coord.y += c.y;
}

void Player::handle_events(sf::Event event)
{
		// if(event.type == sf::Event::KeyPressed)
		// {
		// 	if(event.key.code == sf::Keyboard::W){
		// 		coord.y -= 1;
		// 		if(dir != Direction::UP){
		// 			dir = Direction::UP;
		// 		}
		// 	}
		// 	else if(event.key.code == sf::Keyboard::S){
		// 	    coord.y += 1;
  //               if(dir != Direction::DOWN){
		// 			dir = Direction::DOWN;
		// 		}
		// 	}


		// 	if(event.key.code == sf::Keyboard::D){
		// 		coord.x += 1;
		// 		if(dir != Direction::RIGHT){
		// 			dir = Direction::RIGHT;
		// 			spr.setTextureRect(sf::IntRect(0, 0, 32, 32));
		// 		}
		// 	}
		// 	else if(event.key.code == sf::Keyboard::A){
		// 		coord.x -= 1;
		// 		if(dir != Direction::LEFT){
		// 			dir = Direction::LEFT;
		// 			spr.setTextureRect(sf::IntRect(32, 0, -32, 32));
		// 		}
		// 	}
		// }
}

void Player::update(sf::Time deltaTime)
{
	spr.setPosition(coord.x*TILESCALE, coord.y*TILESCALE);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(spr);
}
