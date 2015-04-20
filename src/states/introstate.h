#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "state.h"
#include "../level.h"
#include <vector>
#include <SFML/Graphics.hpp>

class IntroState : public State
{
private:
	bool is_paused = false;
	bool rendering_text = true;
	sf::Texture logo_txr;
	sf::Sprite logo;
	sf::Text press_start;
	sf::Font font;
	sf::Clock flash_timer;
protected:
	static IntroState* _instance;
	IntroState(){}
public:
	static IntroState* instance();
    ~IntroState(){}
	void init();
	void cleanup();

	void handle_events(Game* game, sf::Event event);
	void update(Game* game, sf::Time deltaTime);
	void render(Game* game);

 	void pause();
 	void resume();
};

#endif // INTROSTATE_H
