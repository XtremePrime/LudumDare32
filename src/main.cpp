#include <iostream>
#include "game.h"

/*
;;;;;;;;;;;;;;;;;;;;;;
;;; THINGS TO MAKE ;;;
;;;;;;;;;;;;;;;;;;;;;;

Doorways. Class with either one door to other or doorway to new level. SAme class
Player. Make an isEnemy func to detect enemy on tile.
Enemy. Make an isPlayer func to detect player on tile.
States. Work on the states. Intro state mainly. Change state if time.
Notification. Make text notification appear when you can go through door. Center-Bottom
HUD. Make HUD with lifebar.

Sound. Put sound effects in the game
Music. Start the music again
*/

int main()
{
	Game game;
	game.run();
	return 0;
}
