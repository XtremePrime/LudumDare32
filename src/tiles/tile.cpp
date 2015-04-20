#include "tile.h"

Tile::Tile()
{
	id = 0;
	init();
}

Tile::Tile(int id)
{
	this->id = id;
	init();
}

void Tile::render(sf::RenderWindow* window)
{
	window->draw(this->spr);
}

void Tile::set_tile(TileType tt, bool walk, bool occ, bool haz, std::string url)
{
	this->tileType = tt;
	this->walkable = walk;
    this->occupied = occ;
    this->hazardous = haz;
	this->txr.loadFromFile(url);
	this->spr.setTexture(txr);
}

void Tile::init()
{
	switch(this->id)
	{
		case 0:
			set_tile(TileType::GROUND_0, true, false, false, "res/Tiles/Ground1_0.png");
		break;
		case 1:
			set_tile(TileType::GROUND_1, true, false, false, "res/Tiles/Ground1_1.png");
		break;
		case 2:
			set_tile(TileType::GROUND_2, true, false, false, "res/Tiles/Ground1_2.png");
        break;
        case 3:
        	set_tile(TileType::WATER_TOP, true, false, false, "res/Tiles/Water1_0.png");
        break;
        case 4:
        	set_tile(TileType::WATER_MID, true, false, false, "res/Tiles/Water1_1.png");
        break;
        case 5:
        	set_tile(TileType::WATER_BOT, true, false, false, "res/Tiles/Water1_2.png");
        break;
        case 6:
        	set_tile(TileType::LAVA, false, false, true, "res/Tiles/lava.png");
        break;
        case 7:
        	set_tile(TileType::SOIL_0, true, false, false, "res/Tiles/soil1_0.png");
        break;
        case 8:
        	set_tile(TileType::SOIL_1, true, false, false, "res/Tiles/soil1_1.png");
        break;
        case 9:
        	set_tile(TileType::SOIL_2, true, false, false, "res/Tiles/soil1_2.png");
        break;
        case 10:
            set_tile(TileType::STONE, false, false, false, "res/Tiles/stone.png");
        break;
        case 11:
            set_tile(TileType::STONE_DOOR0, false, false, false, "res/Tiles/stone_door.png");
        break;
        case 12:
            set_tile(TileType::STONE_DOOR1, false, false, false, "res/Tiles/stone_door1.png");
        break;
        case 13:
            set_tile(TileType::STONE1, false, false, false, "res/Tiles/stone1.png");
        break;
        case 14:
            set_tile(TileType::STONE2, false, false, false, "res/Tiles/stone2.png");
        break;
        case 15:
            set_tile(TileType::STONE3, false, false, false, "res/Tiles/stone3.png");
        break;
        case 16:
            set_tile(TileType::GROUND_3, true, false, false, "res/Tiles/Ground1_3.png");
        break;
        case 17:
            set_tile(TileType::STONE_DOOR2, true, false, false, "res/Tiles/stone_door2.png");
        break;
        case 18:
            set_tile(TileType::STONE_DOOR3, true, false, false, "res/Tiles/stone_door3.png");
        break;
        case 19:
            set_tile(TileType::STONE_DOOR4, true, false, false, "res/Tiles/stone_door4.png");
        break;
        case 20:
            set_tile(TileType::GROUND_4, true, false, false, "res/Tiles/green_walkable_stone.png");
        break;
        case 21:
            set_tile(TileType::GROUND_5, true, false, false, "res/Tiles/Ground1_4.png");
        break;
        case 22:
            set_tile(TileType::GROUND_6, true, false, false, "res/Tiles/Ground1_5.png");
        break;
        case 23:
            set_tile(TileType::GROUND_7, true, false, false, "res/Tiles/Ground1_6.png");
        break;
        case 24:
            set_tile(TileType::GROUND_8, true, false, false, "res/Tiles/Ground1_7.png");
        break;
        case 25:
            set_tile(TileType::GROUND_9, true, false, false, "res/Tiles/Ground1_8.png");
        break;
        case 26:
            set_tile(TileType::GROUND_10, true, false, false, "res/Tiles/Ground1_9.png");
        break;
        case 27:
            set_tile(TileType::GROUND_11, true, false, false, "res/Tiles/Ground1_10.png");
        break;
        case 28:
            set_tile(TileType::GROUND_12, true, false, false, "res/Tiles/Ground1_11.png");
        break;
        case 29:
            set_tile(TileType::GROUND_13, true, false, false, "res/Tiles/Ground1_12.png");
        break;
        case 30:
            set_tile(TileType::GROUND_14, true, false, false, "res/Tiles/Ground1_13.png");
        break;
        case 31:
            set_tile(TileType::STAIRS, true, false, false, "res/Tiles/stairs.png");
        break;
        case 32:
            set_tile(TileType::STAIRS1, true, false, false, "res/Tiles/static_stairs.png");
        break;
        case 33:
            set_tile(TileType::STAIRS2, true, false, false, "res/Tiles/stairs_down.png");
        break;
        case 34:
            set_tile(TileType::WATER1_LVL2, true, false, false, "res/Tiles/water1_lvl2.png");
        break;
        case 35:
            set_tile(TileType::WATER2_LVL2, true, false, false, "res/Tiles/water2_lvl2.png");
        break;
        case 36:
            set_tile(TileType::WATER3_LVL2, true, false, false, "res/Tiles/water3_lvl2.png");
        break;
        case 37:
            set_tile(TileType::WATER4_LVL2, true, false, false, "res/Tiles/lvl2_water1.png");
        break;
        case 38:
            set_tile(TileType::WATER5_LVL2, true, false, false, "res/Tiles/lvl2_water2.png");
        break;
        case 39:
            set_tile(TileType::WATER6_LVL2, true, false, false, "res/Tiles/lvl2_water3.png");
        break;
        case 40:
            set_tile(TileType::WATER7_LVL2, true, false, false, "res/Tiles/lvl2_water4.png");
        break;

	}
}
