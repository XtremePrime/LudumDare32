#include "gamestate.h"

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init()
{
	level.load_from_file("res/levels/level1.txt");
	music.openFromFile("res/bgm/POL-evil-throne-short.wav");

	music.setLoop(true);
	// music.play();

	view.setCenter(sf::Vector2f(128, 128));
	view.setSize(sf::Vector2f(256, 256));
}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{
	if(!is_paused)
	{
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::W)
				view.move(0, -32);
			else if(event.key.code == sf::Keyboard::S)
				view.move(0, 32);
			

			if(event.key.code == sf::Keyboard::D)
				view.move(32, 0);
			else if(event.key.code == sf::Keyboard::A)
				view.move(-32, 0);
		}
	}
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused)
	{
		game->get_window()->setView(view);
	}
}

void GameState::render(Game* game)
{
	if(!is_paused)
	{
		level.render(game->get_window());
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
