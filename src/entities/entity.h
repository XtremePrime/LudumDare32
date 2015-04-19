#ifndef ENTITY_H
#define ENTITY_H


#include "../level.h"

class Entity
{
private:
public:
	enum Direction{UP,DOWN,LEFT,RIGHT};

	sf::Texture txr;
	sf::Sprite spr;
	sf::Vector2f coord;
	Direction dir;

	virtual void handle_events(sf::Event event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow*) = 0;
};

#endif // ENTITY_H
