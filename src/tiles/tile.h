#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
	GROUND_0 = 1,
    GROUND_1 = 2,
    GROUND_2 = 3,
	WATER_TOP = 4,
	WATER_MID = 5,
	WATER_BOT = 6,
	LAVA = 7,
	SOIL_0 = 8,
	SOIL_1 = 9,
	SOIL_2 = 10
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
