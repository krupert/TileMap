#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

struct Input {
	bool up_arrow_released;
	bool up_arrow_pressed;
	bool down_arrow_released;
	bool down_arrow_pressed;

	std::vector<sf::Keyboard::Key> keys_pressed;
	std::vector<sf::Keyboard::Key> keys_released;
	std::vector<sf::Keyboard::Key> keys_held;
	
	Input() = default;

	void collect(sf::RenderWindow& window)
	{
		up_arrow_pressed = false;
		up_arrow_released = false;
		down_arrow_pressed = false;
		down_arrow_released = false;

		keys_pressed.clear();
		keys_released.clear();
		keys_held.clear();
		
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				keys_pressed.push_back(event.key.code);

				/*switch(event.key.code)
				{
				case sf::Keyboard::Up:
					up_arrow_pressed = true;
					printf("up \n");
					break;
				case sf::Keyboard::Down:
					down_arrow_pressed = true;
					printf("down \n");
					break;
				}*/

				break;
				//printf("|| \n");
			}
		}
	}

	//Function for finding whether a key has been pressed
	bool keyPressed(const sf::Keyboard::Key key) 
	{
		return std::find(keys_pressed.begin(), keys_pressed.end(), key) != keys_pressed.end();
	}


};