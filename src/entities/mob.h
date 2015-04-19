#ifndef MOB_H
#define MOB_H
#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"

class Mob : public Entity
{

private:
    std::string name;
    int dmg;
    int hp;
public:
    virtual void init();

    virtual void move();

    virtual void render(sf::RenderWindow*);

    int get_hp() { return this->hp; }

};
#endif // MOB_H
