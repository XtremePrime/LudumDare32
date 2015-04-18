#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "tiles/tile.h"

class Level
{
private:
	typedef std::vector<std::vector<int>> vector2di;
	int x, y;
	vector2di map;

	void convert();
public:

	static Tile

	Level(vector2di map, int xx, int yy);
};

#endif // LEVEL_H