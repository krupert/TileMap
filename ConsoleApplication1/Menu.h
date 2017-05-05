#pragma once
#include "SFML/Graphics.hpp"
#include "Input.h"
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void arrowUp();
	void arrowDown();
	//void menuNav(sf::RenderWindow &window, Input input, Menu mainMenu);
	int getSelectedItem()
	{
		return selectedItemIndex;
	}
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

