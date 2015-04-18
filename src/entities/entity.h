#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
private:
public:
	sf::Texture txr;
	sf::Sprite spr;

	virtual void handle_events(sf::Event event) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow*) = 0;
};

#endif // ENTITY_H