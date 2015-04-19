#ifndef CHANGESTATE_H
#define CHANGESTATE_H

#include "state.h"

class ChangeState : public State
{
private:
public:
    void init();
    void cleanup();

    void handle_events(sf::Event event);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow*);

    void pause();
    void resume();
};

#endif // CHANGESTATE_H
