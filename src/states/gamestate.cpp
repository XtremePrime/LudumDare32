#include "gamestate.h"

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init()
{
	level.load_from_file("res/levels/level2.txt"); // Nu ma injura daca am uitat sa modific la loc, testing reasons
	music.openFromFile("res/bgm/POL-evil-throne-short.wav");

	music.setLoop(true);
	// music.play();

	view.setCenter(sf::Vector2f(128-32, 128-32));
	view.setSize(sf::Vector2f(256-64, 256-64));

	player.init(sf::Vector2f(2,3), level, rand()%3);

	enemies.push_back(new Mob(sf::Vector2f(10, 10), level));
	enemies.push_back(new Mob(sf::Vector2f(10, 11), level));
	enemies.push_back(new Mob(sf::Vector2f(11, 11), level));
	enemies.push_back(new Mob(sf::Vector2f(13, 14), level));
	enemies.push_back(new Mob(sf::Vector2f(15, 11), level));

	level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
}

void GameState::handle_events(Game* game, sf::Event event)
{
	//- Game controls
	if(!is_paused)
	{
		player.handle_events(event);
		if(entities.size() > 0){
			for(int i = 0; i < entities.size(); ++i)
				entities[i]->handle_events(event);
		}
		if(enemies.size() > 0){
			for(int i = 0; i < enemies.size(); ++i)
				enemies[i]->handle_events(event);
		}
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()-1))){
					//- Setting previous tile as not occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, -1));
					//- Making new tile occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, -32);
				}
			}
			else if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()+1))){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, 1));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, 32);
				}
			}


			if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
				if(!player.hasCollision(level.get_tile(player.get_x()+1,player.get_y()))){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(1, 0));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(32, 0);
				}

			}
			else if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
				if(!player.hasCollision(level.get_tile(player.get_x()-1,player.get_y()))){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(-1, 0));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(-32, 0);
				}

			}
		}
	}
	//- Controls in paused state
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::P)
		{
			is_paused = !is_paused;
			std::cout << "Paused state: " << is_paused << "\n";
		}
	}
}

void GameState::change_level()
{

}



void GameState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused && !has_popup)
	{
		player.update(deltaTime);

		if(entities.size() > 0){
			for(int i = 0; i < entities.size(); ++i)
				entities[i]->update(deltaTime);
		}
		if(enemies.size() > 0){
			for(int i = 0; i < enemies.size(); ++i)
				enemies[i]->update(deltaTime);
		}

		if(mob_timer.getElapsedTime().asMilliseconds() >= 1500)
		{
			if(enemies.size() > 0){
				for(int i = 0; i < enemies.size(); ++i){
					std::cout << "Locate: " << enemies[i]->canLocatePlayer(player);
					enemies[i]->set_chasing(enemies[i]->canLocatePlayer(player));
					if(!enemies[i]->get_chasing())
						enemies[i]->move(enemies[i]->generate_move(this->level));
					else{
						enemies[i]->move(sf::Vector2f(player.get_x()-enemies[i]->get_x(), player.get_y()-enemies[i]->get_y()));
					}
				}
			}
			mob_timer.restart();
		}

		game->get_window()->setView(view);
	}
}

void GameState::render(Game* game)
{
	if(!is_paused)
	{
		level.render(game->get_window());
		if(entities.size() > 0){
			for(int i = 0; i < entities.size(); ++i)
				entities[i]->render(game->get_window());
		}
		if(enemies.size() > 0){
			for(int i = 0; i < enemies.size(); ++i)
				enemies[i]->render(game->get_window());
		}
		player.render(game->get_window());
	}
}

void GameState::cleanup()
{

}

void GameState::pause()
{
	is_paused = true;
}

void GameState::resume()
{
	is_paused = false;
}
