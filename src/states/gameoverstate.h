#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "state.h"

class GameOverState : public State
{
private:
	sf::Texture screen_txr;
	sf::Sprite screen;
protected:
	static GameOverState* _instance;
	GameOverState(){}
public:
	static GameOverState* instance();
    ~GameOverState(){}
    void init();
    void cleanup();

    void handle_events(Game* game, sf::Event event);
    void update(Game* game, sf::Time deltaTime);
    void render(Game* game);

    void pause();
    void resume();
};

#endif // GAMEOVERSTATE_H
