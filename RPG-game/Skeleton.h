#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

private:
	sf::Texture texture;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
};