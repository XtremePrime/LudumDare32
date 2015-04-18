#include "level.h"

void Level::init(int map[][SIZE])
{
	// this->map = map;
	for(int i = 0; i < SIZE; ++i)
	{
		for(int k = 0; k < SIZE; ++i)
		{
			this->map[i][k] = map[i][k];
		}
	}	
	// this->x = xx;
	// this->y = yy;
}


void Level::convert()
{
	for(int i = 0; i < SIZE; ++i)
	{
		for(int k = 0; k < SIZE; ++k)
		{
			tilemap[i][k] = new Tile(map[i][k]);
		}
	}
}

void Level::render(sf::RenderWindow* window)
{
	for(int i = 0; i < SIZE; ++i)
	{
		for(int k = 0; k < SIZE; ++k)
		{
			tilemap[i][k]->render(window);
		}
	}
}