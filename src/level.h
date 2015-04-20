#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "tiles/tile.h"
#include "door.h"

typedef std::vector<std::vector<Tile*>> tilevector;
typedef std::vector<std::vector<int>> vector2di;

class Level
{
private:
	tilevector tiles;
	vector2di map;
	int rows, cols;
	std::vector<Door*> doors;

	void print_map(vector2di);
	void convert(vector2di);
public:
	void cleanup();
	void render(sf::RenderWindow*);
	void load_from_file(std::string);

	tilevector get_tilemap() { return this->tiles; }
	std::vector<Door*> get_doors() { return this->doors; }
	Tile* get_tile(int x, int y) { return this->tiles[x][y]; }
	Door* get_door(float x) { return this->doors[x]; }
};

#endif // LEVEL_H
