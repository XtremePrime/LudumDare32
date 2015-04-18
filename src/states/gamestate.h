#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../level.h"
#include <vector>
#include <SFML/Graphics.hpp>

class GameState : public State
{
private:
	bool is_paused = false;
	Level level;
	std::vector<std::vector<int>> map1;
	// int **map;
	// std::vector<Tile*> tiles;
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
