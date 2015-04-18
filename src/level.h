#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "tiles/tile.h"

typedef std::vector<std::vector<Tile*>> tilevector;
typedef std::vector<std::vector<int>> vector2di;

class Level
{
private:
	tilevector tiles;
	vector2di map;
	int size;

	void print_map(vector2di);
	void convert();
public:
	void render(sf::RenderWindow*);
	void load_from_file(std::string);
};

#endif // LEVEL_H