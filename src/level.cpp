#include "level.h"
#include <cstdlib>

typedef std::vector<std::vector<int>> vector2di;

//- Load map from files. Matrix based
void Level::load_from_file(std::string filename)
{
	std::ifstream file;
	file.open(filename);
	if(!file.is_open()){std::cout << "File couldn't be open.\n";return;}
	file >> rows >> cols;

	for(int i = 0; i < rows; ++i)
	{
		std::vector<int> row;
		for(int k = 0; k < cols; ++k)
		{
			int x;
			file >> x;
			row.push_back(x);
		}
		this->map.push_back(row);
	}
	file.close();

	print_map(this->map);
	convert(this->map);
}

//- Convert matrix into Tile* vector for use.
void Level::convert(vector2di vec)
{
	for(int y = 0; y < rows; ++y)
	{
		std::vector<Tile*> row;
		for(int x = 0; x < cols; ++x)
		{
			row.push_back(new Tile(vec[x][y]));
			row.back()->get_sprite()->setPosition(sf::Vector2f(y*32, x*32));
		}
		tiles.push_back(row);
	}
}

void Level::render(sf::RenderWindow* window)
{
	for(int y = 0; y < rows; ++y)
		for(int x = 0; x < cols; ++x)
			tiles[y][x]->render(window);
}

//- Debugging purposes.
void Level::print_map(std::vector<std::vector<int>> map)
{
	for(std::vector<std::vector<int>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(std::vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
		{
			std::cout << *jt << " ";
		}
		std::cout << "\n";
	}
}
