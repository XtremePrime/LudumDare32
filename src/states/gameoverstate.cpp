#include "gameoverstate.h"

GameOverState* GameOverState::_instance;

GameOverState* GameOverState::instance(){
	if(_instance == NULL)
		_instance = new GameOverState();
	return _instance;
}

void GameOverState::init()
{
	screen_txr.loadFromFile("res/Screens/");
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
		game->quit();
	}
}

void GameOverState::update(Game* game, sf::Time deltaTime)
{

}

void GameOverState::render(Game* game)
{
	game->get_window()->draw(screen);
}

void GameOverState::pause()
{

}

void GameOverState::resume()
{
	
}
