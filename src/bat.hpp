#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
	sf::Vector2f position;
	sf::RectangleShape batShape;
	float batSpeed = 0.3f;

public:
	Bat(float startX, float startY)
	{
		position.x = startX;
		position.y = startY;

		// Initialize batShape by setting its size and position
		batShape.setSize(sf::Vector2f(50, 5));
		batShape.setPosition(position);
	}

	sf::FloatRect getPosition()
	{
		return batShape.getGlobalBounds();
	}

	sf::RectangleShape getShape()
	{
		return batShape;
	}

	void moveLeft()
	{
		position.x -= batSpeed;
	}

	void moveRight()
	{
		position.x += batSpeed;
	}

	void update()
	{
		batShape.setPosition(position);
	}
};