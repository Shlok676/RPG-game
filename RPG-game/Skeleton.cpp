#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
		sprite.setTexture(texture);
		std::cout << "Skeleton texture loaded" << std::endl;

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(400, 100));
	}
	else {
		std::cout << "Skeleton texture failed to load" << std::endl;
	}
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Skeleton::Update()
{

}
