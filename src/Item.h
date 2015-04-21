#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

class Item
{
private:
public:
	sf::Text text;

	void handle_events(sf::Event event);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow*);
};

#endif // ENTITY_H
