#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.h"
#include "../level.h"
#include "../entities/player.h"
#include "../entities/mob.h"
#include "../hud.h"

class GameState : public State
{
private:
	bool is_paused = false;
	bool has_popup = false;
	bool key_pressed = false;
	Level level;
	sf::View view;
	Player player;
	Hud hud;
	std::vector<Mob*> enemies;
	std::vector<Entity*> entities;

	//- Timers
	sf::Clock mob_timer;

	//- Music & sound
	sf::Music music;

	//- Notification
	sf::Font font;
	sf::Text notification;

	void change_level();
protected:
	static GameState* _instance;
	GameState(){}
public:
	static GameState* instance();
    ~GameState(){}
	void init();
	void cleanup();

	void handle_events(Game* game, sf::Event event);
	void update(Game* game, sf::Time deltaTime);
	void render(Game* game);

 	void pause();
 	void resume();
};

#endif // GAMESTATE_H
