#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
	sf::Vector2f position;

	sf::RectangleShape ballShape;

	float xVelocity = 0.2f;
	float yVelocity = 0.2f;

public:
	Ball(float startX, float startY)
	{
		position.x = startX;
		position.y = startY;

		ballShape.setSize(sf::Vector2f(10, 10));
		ballShape.setPosition(position);
	}

	sf::FloatRect getPosition()
	{
		return ballShape.getGlobalBounds();
	}

	sf::RectangleShape getShape()
	{
		return ballShape;
	}

	float getXVelocity()
	{
		return xVelocity;
	}

	void reboundSizes()
	{
		xVelocity = -xVelocity;
	}

	void reboundBatOrTop()
	{
		position.y -= (yVelocity * 30);
		yVelocity = -yVelocity;
	}

	void hitBottom()
	{
		position.y = 1;
		position.x = 500;
	}

	void update()
	{
		// Update the ball position variables
		position.x += xVelocity;
		position.y += yVelocity;

		// Move the ball and the bat
		ballShape.setPosition(position);
	}
};