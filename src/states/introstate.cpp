#include "introstate.h"
#include "gamestate.h"

#define GAME_WIDTH 860
#define GAME_HEIGHT 640

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL)
		_instance = new IntroState();
	return _instance;
}

void IntroState::init()
{
	logo_txr.loadFromFile("res/Screens/1.png");
	logo.setTexture(logo_txr);
	logo.setPosition(sf::Vector2f(0,0));

	font.loadFromFile("res/font/PressStart2P.ttf");

	press_start.setCharacterSize(35);
	press_start.setFont(font);
	press_start.setPosition(90, GAME_HEIGHT-75);
	press_start.setColor(sf::Color::White);
	press_start.setString("Press enter to play!");
}

void IntroState::cleanup()
{

}

void IntroState::handle_events(Game* game, sf::Event event)
{
	if(!is_paused)
	{
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::Return){
				game->change_state(GameState::instance());
			}
		}
	}
}

void IntroState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused)
	{
		if(flash_timer.getElapsedTime().asMilliseconds() >= 1500){
			rendering_text = !rendering_text;
			flash_timer.restart();
		}
	}
}

void IntroState::render(Game* game)
{
	if(!is_paused)
	{
		if(rendering_text)
			game->get_window()->draw(press_start);
		game->get_window()->draw(logo);
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
