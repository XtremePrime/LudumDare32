#include "hud.h"

#define GAME_WIDTH 860
#define GAME_HEIGHT 640
#define TILESCALE 32

void Hud::init(Player* player)
{
	this->player = player;

	rect.setSize(sf::Vector2f(6*TILESCALE, TILESCALE));
	rect.setFillColor(sf::Color(000, 000, 000, 155));

	font.loadFromFile("res/PressStart2P.ttf");

	//- Hardcoded hearts. I have disappointed you, master
}

void Hud::render(sf::RenderWindow* window)
{
	// for(this->player.get_hp();)
		window->draw(rect);
}

void Hud::update(sf::Time deltaTime)
{
	std::cout << player->get_x() << "/" << player->get_y() << "/" << "render\n";
	rect.setPosition((player->get_x()-2)*TILESCALE,(player->get_y()-3)*TILESCALE);
}
