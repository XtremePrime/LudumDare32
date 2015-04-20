#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "entities/player.h"

class Hud
{
private:
	sf::RectangleShape rect;
	sf::Texture heart_txr;	sf::Sprite heart;
	Player p;
	sf::Text time;
	sf::Text kills;
public:
	
};
#endif // HUD_H