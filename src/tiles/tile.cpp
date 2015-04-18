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
			tileType = TileType::GROUND;
			walkable = true;
			txr.loadFromFile("res/Tiles/Ground1_0.png");
			spr.setTexture(txr);
		}
		break;
		case 1:
		{

		}
		break;
	}
}