#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

class Item
{
private:
public:
	sf::Text text;
	sf::
	
	virtual void handle_events(sf::Event event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow*) = 0;

	float get_x() { return coord.x; }
    float get_y() { return coord.y; }
};

#endif // ENTITY_H
