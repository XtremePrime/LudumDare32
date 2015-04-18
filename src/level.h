#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "tiles/tile.h"

class Level
{
private:
	typedef std::vector<std::vector<int>> vector2di;
	int x, y;
	static const int SIZE = 64;
	int map[SIZE][SIZE];
	Tile* tilemap[SIZE][SIZE];

	
	void convert();
public:
	void init(int map[][SIZE]);
	void render(sf::RenderWindow*);
};

#endif // LEVEL_H