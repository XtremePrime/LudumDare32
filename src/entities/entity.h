#ifndef ENTITY_H
#define ENTITY_H


#include "../level.h"

class Entity
{
private:
public:
	enum Direction{UP,DOWN,LEFT,RIGHT};

	std::string name;
    int max_hp, hp, lvl, dmg;

	sf::Texture txr;
	sf::Sprite spr;
	sf::Vector2f coord;
	Direction dir;

	virtual void move(sf::Vector2f) = 0;
	virtual bool hasCollision(Tile*) = 0;

	virtual void handle_events(sf::Event event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow*) = 0;

	float get_x() { return coord.x; }
    float get_y() { return coord.y; }
    void set_hp(int hp) { this->hp = hp; }
};

#endif // ENTITY_H
