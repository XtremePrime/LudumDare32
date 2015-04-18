#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType { 
	GROUND = 0, 
	WATER = 1 
};

class Tile
{
private:
	
	bool walkable;

	sf::Texture txr;
	sf::Sprite spr;

	void init();
public:
	int id;
	Tile();
	Tile(int id);
	TileType tileType;

	void render(sf::RenderWindow*);

	bool may_pass() { return this->walkable; }
	sf::Texture* get_texture(){ return &txr; }
	sf::Sprite* get_sprite(){ return &spr; }
};

#endif // TILE_H
