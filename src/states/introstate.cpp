#include "introstate.h"

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL)
		_instance = new IntroState();
	return _instance;
}

void IntroState::init()
{

}

void IntroState::cleanup()
{

}

void IntroState::handle_events(Game* game, sf::Event event)
{
	if(!is_paused)
	{
		
	}
}

void IntroState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused)
	{
		
	}
}

void IntroState::render(Game* game)
{
	if(!is_paused)
	{

	}
}

void IntroState::pause()
{
	is_paused = true;
}

void IntroState::resume()
{
	is_paused = false;
}