#ifndef MOB_H
#define MOB_H

#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "player.h"

class Mob : public Entity
{
private:
	bool is_chasing = false;
public:
	Mob(sf::Vector2f, Level);

    void init(sf::Vector2f, Level, int);

    void move(sf::Vector2f);
    bool hasCollision(Tile*);
    bool canLocatePlayer(Player);
    bool hitsPlayer(Tile*, Player);
    sf::Vector2f generate_move(Level);

	void handle_events(sf::Event event);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow*);

	bool get_chasing() { return this->is_chasing; }
	void set_chasing(bool chase) { this->is_chasing = chase; }

    int get_hp() { return this->hp; }
    int get_dmg() { return this->dmg; }
};
#endif // MOB_H
