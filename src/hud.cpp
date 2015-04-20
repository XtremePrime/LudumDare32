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
	// hearts.push_back(new Heart());

	// for(int i = 0; i < hearts.size(); ++i)
	// 	hearts[i]->setTexture(heart_txr);
}

void Hud::render(sf::RenderWindow* window)
{
	// for(this->player.get_hp();)
		window->draw(rect);
}

void Hud::update(sf::Time deltaTime)
{
	rect.setPosition((player->get_x()-2)*TILESCALE,(player->get_y()-3)*TILESCALE);
	for(int i = 0; i < hearts.size(); ++i)
	{

	}
}
