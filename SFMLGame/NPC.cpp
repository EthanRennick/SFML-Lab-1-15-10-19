#include <NPC.h>

NPC::NPC() {};
NPC::~NPC(){};

void NPC::initialize()
{
	cout << "NPC initialize" << endl;

	if (!npcTexture.loadFromFile("moose.png"))
	{
		std::cout << "error with npc texture file left";
	}
	npcSprite.setTexture(npcTexture);
	std::cout << "Texture loaded for npc";
	npcSprite.setPosition(200, 0);
}

void NPC::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		npcSprite.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		npcSprite.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		npcSprite.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		npcSprite.move(1, 0);
	}
}

void NPC::draw()
{

}