#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text frameRateText;
	sf::Font font;

	double timer;

public:
	FrameRate();
	~FrameRate();

	void Initialize();
	void Load();
	void Draw(sf::RenderWindow& window);
	void Update(double deltaTime);
};

