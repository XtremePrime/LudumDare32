#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"
// #include "mob.h"
#include <cstdlib>

class Player : public Entity
{
private:
    int score;
    int xp;
    bool is_dead = false;
    bool action = false;
public:
    void init(sf::Vector2f, Level, int);

    void move(sf::Vector2f);
    bool hasCollision(Tile*);
    // bool hitsEnemy(Tile*, Mob);

    void handle_events(sf::Event event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow*);

    int get_hp() { return this->hp; }
    int get_xp() { return this->xp; }
    int get_lvl() { return this->lvl; }
    int get_dmg() { return this->dmg; }
    bool get_death() { return this->is_dead; }
    void set_coord(sf::Vector2f c);
    void set_hp(int hp) { this->hp = hp; }
    bool get_action() { return this->action; }
};


#endif
