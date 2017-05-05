//test

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Gameplay.h"

#define TILE_SIZE 50

void Gameplay::GetGameInput(sf::RenderWindow& window, Input input)
{
	if (input.keyPressed(sf::Keyboard::Up) || input.keyPressed(sf::Keyboard::W))
	{
		cameraPosition.y += 10.0f;
	}
	else if (input.keyPressed(sf::Keyboard::Down) || input.keyPressed(sf::Keyboard::S))
	{
		cameraPosition.y -= 10.0f;
	}
	else if (input.keyPressed(sf::Keyboard::Left) || input.keyPressed(sf::Keyboard::A))
	{
		cameraPosition.x -= 10.0f;
	}
	else if (input.keyPressed(sf::Keyboard::Right) || input.keyPressed(sf::Keyboard::D))
	{
		cameraPosition.x += 10.0f;
		
		
	}
	else {}

	if (!map.load(sf::Vector2f(TILE_SIZE, TILE_SIZE), level, static_cast<sf::Vector2f>(window.getSize()), 16, 8, cameraPosition))
	{
		//return -1;
	}
}

void Gameplay::drawGame(sf::RenderWindow& window)
{

	
}