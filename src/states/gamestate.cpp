#include "gamestate.h"

#include <sstream>
#include "introstate.h"
#include "gameoverstate.h"

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init()
{
	level.load_from_file("res/levels/level3.txt");
	music.openFromFile("res/bgm/POL-evil-throne-short.wav");

	music.setLoop(true);
	music.play();

	pdamage_buf.loadFromFile("res/sfx/hurt.wav");
	pdamage_snd.setBuffer(pdamage_buf);
	pdamage_snd.setVolume(1000);
	edamage_buf.loadFromFile("res/sfx/attack.wav");
	edamage_snd.setBuffer(edamage_buf);


	view.setCenter(sf::Vector2f(128-32, 128-32));
	view.setSize(sf::Vector2f(256-64, 256-64));

	player.init(sf::Vector2f(2,3), level, rand()%3);
	

	//- Level 1 pushback
	enemies.push_back(new Mob(sf::Vector2f(4, 2), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(13, 8), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(6, 8), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(5, 8), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(9, 17), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(17, 17), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(4, 22), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(8, 21), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(12, 26), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(20, 30), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(23, 29), level, 0));
	enemies.push_back(new Mob(sf::Vector2f(25, 23), level, 0));

	hud.init(&player, enemies.size());

	level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
}

bool GameState::check_for_attack(Player p, Mob* m, int x, int y)
{
	if(p.get_x()+x == m->get_x() && p.get_y()+y+1 == m->get_y()){
		return true;
	}

	return false;
}

bool GameState::check_for_attack(Mob* m, Player p, int x, int y)
{
	if(p.get_x() == m->get_x()+x && p.get_y() == m->get_y()+y){
		return true;
	}

	return false;
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

		//- Handle player movements
		if(event.type == sf::Event::KeyPressed)
		{
			bool attacked = false;
			if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
				for(int i = 0; i < enemies.size(); ++i)
				{
					if(check_for_attack(player, enemies[i], 0, -1))
					{
						enemies[i]->set_hp(enemies[i]->get_hp()-player.get_dmg());
						edamage_snd.play();
						attacked = true;
					}
				}
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()-1)) && !attacked){
					//- Setting previous tile as not occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, -1));
					//- Making new tile occupied
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, -32);
				}
			}
			else if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
				for(int i = 0; i < enemies.size(); ++i)
				{
					if(check_for_attack(player, enemies[i], 0, -1))
					{
						enemies[i]->set_hp(enemies[i]->get_hp()-player.get_dmg());
						edamage_snd.play();
						attacked = true;
					}
				}
				if(!player.hasCollision(level.get_tile(player.get_x(),player.get_y()+1)) && !attacked){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(0, 1));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(0, 32);
				}
			}


			if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
				for(int i = 0; i < enemies.size(); ++i)
				{
					if(check_for_attack(player, enemies[i], 0, -1))
					{
						enemies[i]->set_hp(enemies[i]->get_hp()-player.get_dmg());
						edamage_snd.play();
						attacked = true;
					}
				}
				if(!player.hasCollision(level.get_tile(player.get_x()+1,player.get_y())) && !attacked){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(1, 0));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(32, 0);
				}

			}
			else if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
				for(int i = 0; i < enemies.size(); ++i)
				{
					if(check_for_attack(player, enemies[i], 0, -1))
					{
						enemies[i]->set_hp(enemies[i]->get_hp()-player.get_dmg());
						edamage_snd.play();
						attacked = true;
					}
				}
				if(!player.hasCollision(level.get_tile(player.get_x()-1,player.get_y())) && !attacked){
					level.get_tile(player.get_x(), player.get_y())->set_occupied(false);
					player.move(sf::Vector2f(-1, 0));
					level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
					view.move(-32, 0);
				}
			}

			std::cout << player.get_x() << "/" << player.get_y() << "\n";

			if(event.key.code == sf::Keyboard::T){

				game->get_window()->setView(view);
			}


			if(level.get_tile(player.get_x(),player.get_y())->is_hazardous())
				player.hp-=15;
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
	level.cleanup();
	enemies.clear();
	entities.clear();

	view.setCenter(sf::Vector2f(128-32, 128-32));
	view.setSize(sf::Vector2f(256-64, 256-64));

	player.set_coord(sf::Vector2f(2,3));

	level.get_tile(player.get_x(), player.get_y())->set_occupied(true);
}


void GameState::update(Game* game, sf::Time deltaTime)
{
	for(int i = 0; i < enemies.size(); ++i)
		std::cout << "id " << i << ": " << enemies[i]->get_hp() << "\n";
	if(!is_paused && !has_popup)
	{
		player.update(deltaTime);
		if(player.get_death()){
			std::cout << "You died!\n";
			view.reset(sf::FloatRect(0, 0, 860, 640));
			game->get_window()->setView(view);

			player.set_hp(100);

			game->change_state(IntroState::instance());
			return;
		}

		if(entities.size() > 0){
			for(int i = 0; i < entities.size(); ++i)
				entities[i]->update(deltaTime);
		}
		if(enemies.size() > 0){
			for(int i = 0; i < enemies.size(); ++i)
				if(!enemies[i]->get_death())
					enemies[i]->update(deltaTime);
		}

		if(enemies.size() > 0){
			for(int i = 0; i < enemies.size(); ++i)
				if(enemies[i]->get_death()){
					enemies.erase(enemies.begin()+i);
				}
		}

		if(enemies.size() <= 0){
			std::cout << "But also won?\n";
			view.reset(sf::FloatRect(0, 0, 860, 640));
			game->get_window()->setView(view);

			game->change_state(GameOverState::instance());
		}

		if(mob_timer.getElapsedTime().asMilliseconds() >= 750)
		{
			if(enemies.size() > 0){
				for(int i = 0; i < enemies.size(); ++i){
					// std::cout << "Locate: " << enemies[i]->canLocatePlayer(player) << "\n";
					enemies[i]->set_chasing(enemies[i]->canLocatePlayer(player));
					if(!enemies[i]->get_chasing())
						enemies[i]->move(enemies[i]->generate_move(this->level));
					else{
						float vx, vy;
						if(player.get_x()-enemies[i]->get_x() < 0) vx = -1;
						else if(player.get_x()-enemies[i]->get_x() > 0) vx = 1;
						else vx = 0;

						// std::cout << "player.get_x()-enemies[i]->get_x(): " << player.get_x()-enemies[i]->get_x() << "\n";

						if(player.get_y()-enemies[i]->get_y() < 0) vy = -1;
						else if(player.get_y()-enemies[i]->get_y() == 0) vy = 0;
						else vy = 1;

						// std::cout << "player.get_y()-enemies[i]->get_y(): " << player.get_y()-enemies[i]->get_y() << "\n";

						// std::cout << player.get_y() << "\n";

						// game->quit();

						bool attacked = false;
						if(check_for_attack(enemies[i], player, vx, vy)){
							player.set_hp(player.get_hp()-enemies[i]->get_dmg());
							pdamage_snd.play();
							attacked = true;
							// std::cout << "Attacked! HP left: " << player.get_hp() << "\n";
						}
						if(!enemies[i]->hasCollision(level.get_tile( (int)(enemies[i]->get_x()+vx), (int)(enemies[i]->get_y()+vy) )) && !attacked)
							enemies[i]->move(sf::Vector2f(vx, vy));
						// std::cout << "Moved: " << vx << "/" << vy << " | " << "New pos: " << enemies[i]->get_x() << "/" << enemies[i]->get_y() << "\n";
					}
				}
			}
			mob_timer.restart();
		}

		hud.update(deltaTime, enemies.size());
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
				if(!enemies[i]->get_death())
					enemies[i]->render(game->get_window());
		}
		player.render(game->get_window());
		hud.render(game->get_window());
	}
}

void GameState::cleanup()
{
	level.cleanup();
	enemies.clear();
	entities.clear();
}

void GameState::pause()
{
	is_paused = true;
}

void GameState::resume()
{
	is_paused = false;
}