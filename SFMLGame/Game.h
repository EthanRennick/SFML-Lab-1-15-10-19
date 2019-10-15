#include "Player.h"
#include "NPC.h"

class Game
{
	public:
		Game();
		void run();
	private:
		void initialize();
		void update();
		void render();
		void collisionDetect();
		Player* player;
		NPC* npc;
};