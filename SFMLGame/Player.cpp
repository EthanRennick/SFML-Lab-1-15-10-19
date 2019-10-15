#include <Player.h>

Player::Player(){};
Player::~Player(){};

void Player::initialize()
{
	cout << "Player initialize" << endl;
	if (!playerTexture.loadFromFile("buffalo.png"))
	{
		cout << "error with player texture file left";
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(0, 0);
	std::cout << "Texture loaded\n";
}

void Player::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerSprite.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerSprite.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerSprite.move(1,0);
	}

}

void Player::draw()
{
	
}