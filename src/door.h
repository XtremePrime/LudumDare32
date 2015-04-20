#ifndef DOOR_H
#define DOOR_H

class Door
{
private:
	bool same_level_entry = true;

	sf::Vector2f entry_coord;
	sf::Vector2f exit_coord;
public:
	void init(bool sle, sf::Vector2f coord);
	void init(bool sle, sf::Vector2f entry, sf::Vector2f exit);
};

#endif // DOOR_H