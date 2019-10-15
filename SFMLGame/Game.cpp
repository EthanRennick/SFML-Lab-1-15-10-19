#include <Game.h>
#include <SFML/Graphics.hpp>

using namespace sf;

sf::RenderWindow* window = new RenderWindow(sf::VideoMode(800, 600), "Launching...");;

Game::Game(){}

void Game::initialize()
{
	player = new Player();
	npc = new NPC();

	player->initialize();
	npc->initialize();

	window->setSize(sf::Vector2u(640, 480));
	window->setTitle("Game");
}

void Game::run()
{
	initialize();

	while (window->isOpen())
	{
		update();
		render();
	}
}

//void Game::update()
//{
//	sf::Event event;
//	while (window->pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window->close();
//
//		player->update();
//		npc->update();
//
//		buttonTouching();
//	}
//
//}

void Game::render()
{
	window->clear();

	window->draw(player->playerSprite);
	window->draw(npc->npcSprite);

	window->display();

}

void Game::collisionDetect()
{
	if (player->playerSprite.getGlobalBounds().intersects(npc->npcSprite.getGlobalBounds()))
	{
		std::cout << "Collision";
	}
}

void Game::update()
//This function is the most important function in the project. 
// This function contains the main game loop which controls the game. 
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;

	clock.restart();

	while (window->isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			player->update();
			npc->update();
			collisionDetect();
			render();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

} // end main