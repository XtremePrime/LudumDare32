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

void Tile::set_tile(TileType tt, bool walk, std::string url)
{
	this->tileType = tt;
	this->walkable = walk;
	this->txr.loadFromFile(url);
	this->spr.setTexture(txr);
}

void Tile::init()
{
	switch(this->id)
	{
		case 0:
			set_tile(TileType::GROUND_0, true, "res/Tiles/Ground1_0.png");
		break;
		case 1:
			set_tile(TileType::GROUND_1, true, "res/Tiles/Ground1_1.png");
		break;
		case 2:
			set_tile(TileType::GROUND_2, true, "res/Tiles/Ground1_2.png");
        break;
        case 3:
        	set_tile(TileType::WATER_TOP, true, "res/Tiles/Water1_0.png");
        break;
        case 4:
        	set_tile(TileType::WATER_MID, true, "res/Tiles/Water1_1.png");
        break;
        case 5:
        	set_tile(TileType::WATER_BOT, true, "res/Tiles/Water1_2.png");
        break;
        case 6:
        	set_tile(TileType::LAVA, false, "res/Tiles/lava.png");
        break;
        case 7:
        	set_tile(TileType::SOIL_0, true, "res/Tiles/soil1_0.png");
        break;
        case 8:
        	set_tile(TileType::SOIL_1, true, "res/Tiles/soil1_1.png");
        break;
        case 9:
        	set_tile(TileType::SOIL_2, true, "res/Tiles/soil1_2.png");
        break;
        case 10:
            set_tile(TileType::STONE, false, "res/Tiles/stone.png");
        break;
        case 11:
            set_tile(TileType::STONE_DOOR0, false, "res/Tiles/stone_door.png");
        break;
        case 12:
            set_tile(TileType::STONE_DOOR1, false, "res/Tiles/stone_door1.png");
        break;
        case 13:
            set_tile(TileType::STONE1, false, "res/Tiles/stone1.png");
        break;
        case 14:
            set_tile(TileType::STONE2, false, "res/Tiles/stone2.png");
        break;
        case 15:
            set_tile(TileType::STONE3, false, "res/Tiles/stone3.png");
        break;
        case 16:
            set_tile(TileType::GROUND_3, true, "res/Tiles/ground1_3.png");
        break;
        case 17:
            set_tile(TileType::STONE_DOOR2, false, "res/Tiles/stone_door2.png");
        break;
        case 18:
            set_tile(TileType::STONE_DOOR3, false, "res/Tiles/stone_door3.png");
        break;
        case 19:
            set_tile(TileType::STONE_DOOR4, false, "res/Tiles/stone_door4.png");
        break;
	}
}
