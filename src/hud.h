#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "entities/player.h"
#include <vector>

class Hud
{
private:
	sf::RectangleShape rect;
	sf::Texture heart_txr;

	sf::Text health;
	Player* player;
	sf::Font font;
	sf::Text left;
	int count;

	#define TILESCALE 32
	int get_rect_x() { return (player->get_x()-2)*TILESCALE; }
	int get_rect_y() { return (player->get_y()-3)*TILESCALE; }
	#undef TILESCALE
public:
	void init(Player*, int);
	void update(sf::Time, int);
	void render(sf::RenderWindow*);
};

#endif // HUD_H