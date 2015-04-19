#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.h"
#include "../level.h"
#include "../entities/player.h"
#include "../entities/mob.h"
#include <cstdlib>

class GameState : public State
{
private:
	bool is_paused = false;
	Level level;
	sf::View view;
	Player player;
	std::vector<Mob*> enemies;
	std::vector<Entity*> entities;

	//- Timers
	sf::Clock mob_timer;

	//- Music & sound
	sf::Music music;

	// sf::Vector2f generate_move(Level);

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
