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
		cameraPosition.y -= moveSpeed;
	}
	else if (input.keyPressed(sf::Keyboard::Down) || input.keyPressed(sf::Keyboard::S))
	{
		cameraPosition.y += moveSpeed;
	}
	else if (input.keyPressed(sf::Keyboard::Left) || input.keyPressed(sf::Keyboard::A))
	{
		cameraPosition.x -= moveSpeed;
	}
	else if (input.keyPressed(sf::Keyboard::Right) || input.keyPressed(sf::Keyboard::D))
	{
		cameraPosition.x += moveSpeed;
	}
	else {}

	if (input.keyHeld(sf::Keyboard::Space)) {
		printf("Space Held \n");
	}
	if (input.keyReleased(sf::Keyboard::Space)) {
		printf("Space Released \n");
	}
	if (input.keyReleased(sf::Keyboard::LShift)) {
		printf("SHIFT Released \n");
	}


	if (!map.load(sf::Vector2f(TILE_SIZE, TILE_SIZE), level, 16, 8))
	{
		//return -1;
	}

	renderTexture.clear();
	renderTexture.draw(map);
	renderTexture.display();

	
}

void Gameplay::drawGame(sf::RenderWindow& window)
{
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	view.setCenter(cameraPosition);
	renderTexture.setView(view);
	
	const sf::Texture& texture = renderTexture.getTexture();

	sf::Sprite testSprite(texture);
	window.draw(testSprite);


}