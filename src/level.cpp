#include "level.h"

typedef std::vector<std::vector<int>> vector2di;

//- Load map from files. Matrix based
void Level::load_from_file(std::string filename)
{
	std::ifstream file;
	file.open(filename);
	if(!file.is_open()){std::cout << "File couldn't be open.\n";return;}
	file >> size;
	std::cout << size;

	for(int i = 0; i < size; ++i)
	{
		std::vector<int> row;
		for(int k = 0; k < size; ++k)
		{
			int x;
			file >> x;
			row.push_back(x); 
		}
		this->map.push_back(row);
	}
	file.close();

	print_map(this->map);
	convert();
}

//- Convert matrix into Tile* vector for use.
void Level::convert()
{
	int i = 0, k = 0;
	for(int i = 0; i < size; ++i)
	{
		std::vector<Tile*> row;
		for(int k = 0; k < size; ++k)
		{
			row.push_back(new Tile(map[i][k]));
			row.back()->get_sprite()->setPosition(sf::Vector2f(i*32, k*32));
			std::cout << "Info: " << map[i][k] << " | " << i << " | " << k << "\n";
		}
		tiles.push_back(row);
	}
}

void Level::render(sf::RenderWindow* window)
{
	// for(std::vector<std::vector<Tile*>>::iterator it = tiles.begin(); it != tiles.end(); ++it)
		// for(std::vector<Tile*>::iterator jt = it->begin(); jt != it->end(); ++jt)
	for(int i = 0; i < size; ++i)
		for(int k = 0; k < size; ++k)
			tiles[i][k]->render(window);
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