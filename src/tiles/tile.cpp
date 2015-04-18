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

void Tile::init()
{
	switch(this->id)
	{
		case 0:
		{
			tileType = TileType::GROUND_0;
			walkable = true;
			txr.loadFromFile("res/Tiles/Ground1_0.png");
			spr.setTexture(txr);
		}
		break;
		case 1:
		{
			tileType = TileType::GROUND_1;
			walkable = true;
			txr.loadFromFile("res/Tiles/Ground1_1.png");
			spr.setTexture(txr);
		}
		break;
		case 2:
        {
            tileType = TileType::GROUND_2;
			walkable = true;
			txr.loadFromFile("res/Tiles/Ground1_2.png");
			spr.setTexture(txr);
        }
        break;
        case 3:
        {
            tileType = TileType::WATER_TOP;
			walkable = true;
			txr.loadFromFile("res/Tiles/Water1_0.png");
			spr.setTexture(txr);
        }
        break;
        case 4:
        {
            tileType = TileType::WATER_MID;
			walkable = true;
			txr.loadFromFile("res/Tiles/Water1_1.png");
			spr.setTexture(txr);
        }
        break;
        case 5:
        {
            tileType = TileType::WATER_BOT;
			walkable = true;
			txr.loadFromFile("res/Tiles/Water1_2.png");
			spr.setTexture(txr);
        }
        break;
        case 6:
        {
            tileType = TileType::LAVA;
			walkable = true;
			txr.loadFromFile("res/Tiles/lava.png");
			spr.setTexture(txr);
        }
        break;
        case 7:
        {
            tileType = TileType::SOIL_0;
			walkable = true;
			txr.loadFromFile("res/Tiles/soil1_0.png");
			spr.setTexture(txr);
        }
        break;
        case 8:
        {
            tileType = TileType::SOIL_1;
			walkable = true;
			txr.loadFromFile("res/Tiles/soil1_1.png");
			spr.setTexture(txr);
        }
        break;
        case 9:
        {
            tileType = TileType::SOIL_2;
			walkable = true;
			txr.loadFromFile("res/Tiles/soil1_2.png");
			spr.setTexture(txr);
        }
        break;
	}
}
