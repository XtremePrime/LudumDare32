#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SFML/Graphics.hpp>


class Player{

private:
    sf::Texture txr;
    sf::Sprite spr;

    std::string name;
    int max_hp;
    int hp;
    int xp;
    int lvl;
    int min_dmg;
    int max_dmg;

public:
    Player(int,int,int);
    ~Player();

    void handle_events(sf::Event event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow*);

    int get_hp() { return this->hp; }
    int get_xp() { return this->xp; }
    int get_lvl() { return this->lvl; }
};


#endif
