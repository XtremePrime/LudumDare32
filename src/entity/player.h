#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

class player{

private:
    int player_id;


    sf::Texture war_txr;
    sf::Sprite war_spr;

public:
    player();
    ~player();

    int coordinates(float,float);


};


#endif
