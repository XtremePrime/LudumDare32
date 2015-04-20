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
    STONE3 ,
    GROUND_3 ,
    STONE_DOOR2 ,
    STONE_DOOR3 ,
    STONE_DOOR4 ,
    GROUND_4 ,
    GROUND_5 ,
    GROUND_6 ,
    GROUND_7 ,
    GROUND_8 ,
    GROUND_9 ,
    GROUND_10 ,
    GROUND_11 ,
    GROUND_12 ,
    GROUND_13 ,
    GROUND_14 ,
    STAIRS ,
    STAIRS1 ,
    STAIRS2,
    WATER1_LVL2 ,
    WATER2_LVL2 ,
    WATER3_LVL2 ,
    WATER4_LVL2 ,
    WATER5_LVL2 ,
    WATER6_LVL2 ,
    WATER7_LVL2 ,
    ACID1 ,
    ACID2 ,
    ACID3
};

class Tile
{
private:

	bool walkable;
	bool occupied;
	bool hazardous;

	sf::Texture txr;
	sf::Sprite spr;

	void init();
public:
	int id;
	Tile();
	Tile(int id);
	TileType tileType;

	void render(sf::RenderWindow*);
	void set_tile(TileType, bool, bool, bool, std::string);

	bool may_pass() { return this->walkable; }
	bool get_occupied() { return this->occupied; }
	void set_occupied(bool occ) { this->occupied = occ; }
	sf::Texture* get_texture(){ return &txr; }
	sf::Sprite* get_sprite(){ return &spr; }
};

#endif // TILE_H
