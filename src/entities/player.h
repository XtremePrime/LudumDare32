#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include <cstdlib>

class Player : public Entity
{
private:
    int score;
    int xp;
public:
    void init(sf::Vector2f, Level, int);

    void move(sf::Vector2f);
    bool hasCollision(Tile*);

    void handle_events(sf::Event event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow*);

    int get_hp() { return this->hp; }
    int get_xp() { return this->xp; }
    int get_lvl() { return this->lvl; }
};


#endif
