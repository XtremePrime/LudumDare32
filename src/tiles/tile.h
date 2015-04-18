#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
	GROUND_0 ,
    GROUND_1 ,
    GROUND_2 ,
	WATER_TOP ,
	WATER_MID ,
	WATER_BOT ,
	LAVA ,
	SOIL_0 ,
	SOIL_1 ,
	SOIL_2 ,
	STONE ,
	STONE_DOOR0 ,
	STONE_DOOR1 ,
    STONE1 ,
    STONE2 ,
    STONE3
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
	void set_tile(TileType, bool, std::string);

	bool may_pass() { return this->walkable; }
	sf::Texture* get_texture(){ return &txr; }
	sf::Sprite* get_sprite(){ return &spr; }
};

#endif // TILE_H
