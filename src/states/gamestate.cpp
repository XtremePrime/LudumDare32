#include "gamestate.h"

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init()
{

}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{
	if(!is_paused)
	{

	}
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused)
	{
		
	}
}

void GameState::render(Game* game)
{
	if(!is_paused)
	{
		
	}
}

void GameState::pause()
{
	is_paused = true;
}

void GameState::resume()
{
	is_paused = false;
}