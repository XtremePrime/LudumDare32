#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SFML/Graphics.hpp>


class Player{

private:
    int player_id;

    sf::Texture war_txr;
    sf::Sprite war_spr;

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

    int coordinates(float,float);

    void actions ();

};


#endif
