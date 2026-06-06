#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

private:
	sf::Texture texture;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	sf::Text healthText;
	sf::Font font;

public:
	sf::Sprite sprite;

	int health;

public:
	Skeleton();
	~Skeleton();

	void changeHealth(int hp);

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};