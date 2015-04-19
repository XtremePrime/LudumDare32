#include "player.h"

// Player::Player(int mh,int md,int Md){
//     this->max_hp = mh;
//     this->min_dmg = md;
//     this->max_dmg = Md;

//     this->lvl = 1;
//     this->xp = 0;
//     this->hp = max_hp;
// }

void Player::init(sf::Vector2f c, Level level)
{
	this->txr.loadFromFile("res/Tiles/warr_bow.png");
	this->spr.setTexture(txr);

	this->coord.x = c.x;
	this->coord.y = c.y;

	spr.setPosition(coord.x*32, coord.y*32);

	dir = Direction::RIGHT;
}

void move(sf::Vector2f c, Level level)
{

}

void Player::handle_events(sf::Event event)
{
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::W){
				coord.y -= 1;
				if(dir != Direction::UP){
					dir = Direction::UP;
				}
			}
			else if(event.key.code == sf::Keyboard::S){
			    coord.y += 1;
                if(dir != Direction::DOWN){
					dir = Direction::DOWN;
				}
			}


			if(event.key.code == sf::Keyboard::D){
				coord.x += 1;
				if(dir != Direction::RIGHT){
					dir = Direction::RIGHT;
					spr.setTextureRect(sf::IntRect(0, 0, 32, 32));
				}
			}
			else if(event.key.code == sf::Keyboard::A){
				coord.x -= 1;
				if(dir != Direction::LEFT){
					dir = Direction::LEFT;
					spr.setTextureRect(sf::IntRect(32, 0, -32, 32));
				}
			}
		}
}

void Player::update(sf::Time deltaTime)
{
	spr.setPosition(coord.x*32, coord.y*32);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(spr);
}
