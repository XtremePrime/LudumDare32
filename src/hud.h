#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "entities/player.h"



class Hud
{
private:
	sf::RectangleShape rect;
	sf::Texture heart_txr;

	// struct Heart
	// {
	// 	sf::Sprite sprite;
	// 	bool render = true;
	// 	Heart(float x, float y){
	// 		sprite.setPosition(sf::Vector2f(get_rect_y()+x, get_rect_y()+y));
	// 	}
	// };

	std::vector<int> hearts;
	Player* player;
	sf::Font font;
	// sf::Text time;
	sf::Text kills;

	#define TILESCALE 32
	int get_rect_x() { return (player->get_x()-2)*TILESCALE; }
	int get_rect_y() { return (player->get_y()-3)*TILESCALE; }
	#undef TILESCALE
public:
	void init(Player*);
	void update(sf::Time);
	void render(sf::RenderWindow*);
};

#endif // HUD_H