#ifndef MOB_H
#define MOB_H

#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"

class Mob : public Entity
{
private:
public:
	Mob(sf::Vector2f, Level);

    void init(sf::Vector2f, Level);

    void move(sf::Vector2f);
    bool hasCollision(Tile*);
    sf::Vector2f generate_move(Level);

	void handle_events(sf::Event event);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow*);

    int get_hp() { return this->hp; }
    int get_dmg() { return this->dmg; }
};
#endif // MOB_H
