#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp"

class Map : public sf::Drawable, public sf::Transformable
{
public:
	Map();

	~Map();

	//static const int Tile_Width = 10;
	//static const int Tile_Height = 10;
	
	bool load(sf::Vector2f tileSize, const int tiles[][16], sf::Vector2f WindowSize,  int width, int height, sf::Vector2f Camera)
	{
		
		unsigned int displayWidth = ceil(2 + (WindowSize.x)/tileSize.x);
		unsigned int displayHeight = ceil(2 +(WindowSize.y)/tileSize.y);
		int startCoordX = static_cast<int>(ceil(0.1f + (Camera.x  - WindowSize.x / 2) / tileSize.x));
		int startCoordY = static_cast<int>(ceil(0.1f + (Camera.y  - WindowSize.y / 2) / tileSize.y));

		mapVertices.setPrimitiveType(sf::Quads);
		mapVertices.resize(displayWidth*displayHeight * 4);

		for (int i = 0; i < displayHeight; i++)
		{
			for (int j = 0; j < displayWidth; j++)
			{
				int tileID;

				if ((startCoordX+j) >= 0 && (startCoordX+j) < width && (startCoordY+i) >= 0 && (startCoordY+i) < height)
				{
					tileID = tiles[(startCoordY + i)][startCoordX + j];
				}
				else
				{
					tileID = 4;			
					
				}


				//int tileID = tiles[startCoordX + j + (startCoordY + i)*width];

				sf::Vertex* quad = &mapVertices[(j + i * displayWidth )* 4];
				

				

				quad[0].position = sf::Vector2f((j * tileSize.x - static_cast<int>(Camera.x) % 50), (i * tileSize.y - static_cast<int>(Camera.y) % 50));
				quad[1].position = sf::Vector2f(((j + 1 ) * tileSize.x - static_cast<int>(Camera.x) % 50), (i * tileSize.y) - static_cast<int>(Camera.y) % 50);
				quad[2].position = sf::Vector2f((j + 1 )* tileSize.x - static_cast<int>(Camera.x) % 50, (i + 1 ) * tileSize.y - static_cast<int>(Camera.y) % 50);
				quad[3].position = sf::Vector2f((j* tileSize.x - static_cast<int>(Camera.x) % 50), (i + 1 ) * tileSize.y - static_cast<int>(Camera.y) % 50);

				
				switch (tileID)
				{
				case 0:
					quad[0].color = sf::Color::Blue;
					quad[1].color = sf::Color::Blue;
					quad[2].color = sf::Color::Blue;
					quad[3].color = sf::Color::Blue;
					break;

				case 1:
					quad[0].color = sf::Color::Yellow;
					quad[1].color = sf::Color::Yellow;
					quad[2].color = sf::Color::Yellow;
					quad[3].color = sf::Color::Yellow;
					break;
				case 2:
					quad[0].color = sf::Color::Green;
					quad[1].color = sf::Color::Green;
					quad[2].color = sf::Color::Green;
					quad[3].color = sf::Color::Green;
					break;
				case 3:
					quad[0].color = sf::Color::White;
					quad[1].color = sf::Color::White;
					quad[2].color = sf::Color::White;
					quad[3].color = sf::Color::White;
					break;
				case 4:
					quad[0].color = sf::Color::Black;
					quad[1].color = sf::Color::Black;
					quad[2].color = sf::Color::Black;
					quad[3].color = sf::Color::Black;
					break;
				}

			}

		}
		return true;
	}


private:

	sf::VertexArray mapVertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		//states.texture = &m_tileset;

		// draw the vertex array
		target.draw(mapVertices, states);
	}

	
};

