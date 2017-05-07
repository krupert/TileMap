// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game");


	//Necessary for proper key holding, releasing:
	window.setKeyRepeatEnabled(false);

	sf::Font defaultFont;
	if (!defaultFont.loadFromFile("resources/arial.ttf"))
	{
		return EXIT_FAILURE;
	}
	//sf::Text welcomeText("Welcome!", defaultFont, 10);
	//welcomeText.setColor(sf::Color::White);

	enum gameState {menu, game};
	gameState currentState = menu;

	Menu mainMenu(window.getSize().x, window.getSize().y);
	Gameplay mainGame;
	mainGame.cameraPosition = sf::Vector2f(10.0f, 10.0f);
	Input input;

	if (!mainGame.renderTexture.create(1000, 1000))
	{
		// error...
	}

	sf::View view(sf::FloatRect(0, 200, 800, 800));
	//window.setView(view);
	//view.setCenter(100, 100);
	//view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));


	while (window.isOpen())
	{
		
		input.collect(window);

		switch (currentState)
		{
		case menu:
			if (input.keyPressed(sf::Keyboard::Up) || input.keyPressed(sf::Keyboard::W))
			{
				mainMenu.arrowUp();
				printf("arrowUp \n");
			}
			else if (input.keyPressed(sf::Keyboard::Down) || input.keyPressed(sf::Keyboard::S))
			{
				mainMenu.arrowDown();
				printf("arrowDown \n");
			}
			else if (input.keyPressed(sf::Keyboard::Return))
			{
				if (mainMenu.getSelectedItem() == 0)
				{
					printf("play Game!");
					currentState = game;
				}

			}
			else {}
			break;
		case game:
			mainGame.GetGameInput(window, input);
			break;
		}
		


		//sf::Event event;
		//while (window.pollEvent(event))
		//{
		//	switch(event.type)
		//	{
		//	case sf::Event::KeyPressed:
		//		switch (event.key.code)
		//		{
		//		case sf::Keyboard::Up:
		//			menu.arrowUp();
		//			break;

		//		case sf::Keyboard::Down:
		//			menu.arrowDown();
		//			break;
		//		case sf::Keyboard::Return:
		//			//go to that menu item
		//			//menu.getSelectedItem();
		//			break;
		//		}
		//	}
		//	if (event.type == sf::Event::Closed)
		//		window.close();
		//}

		window.clear();
		switch (currentState)
		{
		case menu:
			mainMenu.draw(window);
			break;
		case game:
			//mainGame.drawGame(window);
			const sf::Texture& texture = mainGame.renderTexture.getTexture();

			// draw it to the window
			
			mainGame.drawGame(window);
			break;
		}

		
		window.display();
	}

	return 0;
}