// #include "Platform/Platform.hpp"
#include "PCH.hpp"
#include "ball.hpp"
#include "bat.hpp"

// Where the game starts from
int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	// Make a window that is 1024 x 768 pixels ...
	// and has the title "Pong"
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

	int lives = 0;
	int score = 3;

	// Create a bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	// Create a ball
	Ball ball(windowWidth / 2, 1);

	// Create a "Text" object called "message"
	sf::Text hud;

	// Set font
	sf::Font font;
	font.loadFromFile("content/DS-DIGIT.ttf");

	// Set the font to our message
	hud.setFont(font);

	// Set text size
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(sf::Color::White);

	// Runs forever, while window is open
	while (window.isOpen())
	{
		/*
			Handle the player input
			**************************************
			**************************************
			**************************************
		*/

		sf::Event event;

		while (window.pollEvent(event))
		{
			// Someone closed the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Left key is pressed: move bat left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bat.moveLeft();
		}
		// Right key is pressed: move bat right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bat.moveRight();
		}
		// Escape key is pressed: close the window
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		/*
			Update the frame
			**************************************
			**************************************
			**************************************
		*/

		// Handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			// Reverse ball direction
			ball.hitBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1)
			{
				// Reset the score
				score = 0;
				// Reset the lives
				lives = 3;
			}
		}

		// Handle ball hitting the top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			// Add a point to player's score
			score++;
		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSizes();
		}

		// Check if the ball hit the bat
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected, so reverse the ball and score a ponint
			ball.reboundBatOrTop();
		}

		// Update ball and bat
		ball.update();
		bat.update();

		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << "    Lives: " << lives;
		hud.setString(ss.str());

		/*
			Update the frame
			**************************************
			**************************************
			**************************************
		*/

		// Clear evertying from the last frame
		window.clear(sf::Color(26, 128, 182, 255));

		// Draw bat and ball
		window.draw(bat.getShape());
		window.draw(ball.getShape());

		// Draw score
		window.draw(hud);

		// Show everything we drew
		window.display();
	} // End of the while loop

	return 0;
}
