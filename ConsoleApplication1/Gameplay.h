#pragma once
//test
#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Map.h"

class Gameplay
{
public:
	Map map;
	sf::RectangleShape square;
	void GetGameInput(sf::RenderWindow& window, Input input);
	void drawGame(sf::RenderWindow& window);

	sf::Vector2f cameraPosition;

private:
	const int level[8][16] =
	{
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
		{1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3 },
		{0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0 },
		{0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0 },
		{0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0 },
		{2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1 },
		{0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1 }
	};
};
