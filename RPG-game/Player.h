#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.h"

class Player
{

private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.0;

	float playerSpeed = 2.0;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime, Skeleton& skeleton);
};