#include "hud.h"

#define GAME_WIDTH 860
#define GAME_HEIGHT 640
#define TILESCALE 32

void Hud::init(Player* player, int* c)
{
	this->player = player;
	this->count = c;

	rect.setPosition((player->get_x()-2)*TILESCALE,(player->get_y()-3)*TILESCALE);
	rect.setSize(sf::Vector2f(6*TILESCALE, TILESCALE));
	rect.setFillColor(sf::Color(000, 000, 000, 155));

	font.loadFromFile("res/font/PressStart2P.ttf");

	health.setCharacterSize(10);
	health.setFont(font);
	health.setPosition(30, 40);
	health.setColor(sf::Color::White);
}

void Hud::render(sf::RenderWindow* window)
{
	window->draw(rect);
	window->draw(health);
}

void Hud::update(sf::Time deltaTime)
{
	std::stringstream ss;
	ss.str(std::string());
	ss << "Health: " << player->get_hp() << "%";
	health.setString(ss.str());

	health.setPosition((player->get_x()-2)*TILESCALE,(player->get_y()-3)*TILESCALE);
	rect.setPosition((player->get_x()-2)*TILESCALE,(player->get_y()-3)*TILESCALE);
}
