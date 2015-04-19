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

	view.setCenter(sf::Vector2f(128-32, 128-32));
	view.setSize(sf::Vector2f(256-64, 256-64));

	player.init(sf::Vector2f(2,2), level, rand()%3);
	testmob.init(sf::Vector2f(5,5), level);
	level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{
	//- Game controls
	if(!is_paused)
	{
		player.handle_events(event);
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::W){
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()-1))){
					//- Setting previous tile as not occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, -1));
					//- Making new tile occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, -32);
				}
			}
			else if(event.key.code == sf::Keyboard::S){
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()+1))){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, 1));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, 32);
				}
			}


			if(event.key.code == sf::Keyboard::D){
				if(!player.hasCollision(level.get_tile(player.get_x()+1,player.get_y()))){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(1, 0));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(32, 0);
				}

			}
			else if(event.key.code == sf::Keyboard::A){
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

sf::Vector2f GameState::generate_move(Level level)
{
	sf::Vector2f c;
	do{
		c.x = rand()%3-1;
		c.y = rand()%3-1;
		std::cout << "Attempted: " << c.x << "/" << c.y << "| hasCol: " << testmob.hasCollision(level.get_tile((int)(testmob.get_x()+c.x), (int)(testmob.get_y()+c.y))) << "\n";
	}while(testmob.hasCollision(level.get_tile((int)(testmob.get_x()+c.x), (int)(testmob.get_y()+c.y))));
	std::cout << "Generated: " << c.x << "/" << c.y << "\n";
	return c;
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	if(!is_paused)
	{
		player.update(deltaTime);
		testmob.update(deltaTime);

		if(mob_timer.getElapsedTime().asMilliseconds() >= 1000)
		{
			std::cout << "Move time!\n";
			testmob.move(generate_move(this->level));
			mob_timer.restart();
		}

		//level.get_tile(player.get_x(), player.get_y())->setOccupied = true;

		game->get_window()->setView(view);
	}
}

void GameState::render(Game* game)
{
	if(!is_paused)
	{
		level.render(game->get_window());
		player.render(game->get_window());
		testmob.render(game->get_window());
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
