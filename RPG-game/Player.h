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

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Draw(sf::RenderWindow& window);
	void Update(Skeleton& skeleton);
};