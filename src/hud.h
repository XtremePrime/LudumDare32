#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "entities/player.h"

class Hud
{
private:
	sf::RectangleShape rect;
	sf::Texture heart_txr;
	std::vector<sf::Sprite> hearts;
	Player* player;
	sf::Font font;
	// sf::Text time;
	sf::Text kills;
public:
	void init(Player*);
	void update(sf::Time);
	void render(sf::RenderWindow*);
};
#endif // HUD_H