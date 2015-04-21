#include "gameoverstate.h"

#include <iostream>

GameOverState* GameOverState::_instance;

GameOverState* GameOverState::instance(){
	if(_instance == NULL)
		_instance = new GameOverState();
	return _instance;
}

void GameOverState::init()
{
	std::cout << "REACHED!\n";
	screen_txr.loadFromFile("res/Screens/Win.png");
	screen.setTexture(screen_txr);

	screen.setPosition(0, 0);
}

void GameOverState::cleanup()
{

}

void GameOverState::handle_events(Game* game, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Return:
			case sf::Keyboard::Escape:
			case sf::Keyboard::Space:
				game->quit();
			default:
			break;
		}
	}
}

void GameOverState::update(Game* game, sf::Time deltaTime)
{

}

void GameOverState::render(Game* game)
{
	// std::cout << "Render!!!\n";
	game->get_window()->draw(screen);
}

void GameOverState::pause()
{

}

void GameOverState::resume()
{
	
}
