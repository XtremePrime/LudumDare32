#ifndef STATE_H
#define STATE_H

#include "../game.h"

#include "tiles/groundtile.h"
#include "tiles/watertile.h"

enum class TileType { GROUND, WATER };

class Tile
{
private:
public:
	const TileType tile_type;

	virtual bool may_pass() = 0;
};

#endif // STATE_H
