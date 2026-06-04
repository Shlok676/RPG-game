#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Draw(sf::RenderWindow& window);
	void Update();
};