#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :
	timer(0)
{
}

FrameRate::~FrameRate() {

}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "arial.ttf Font in assets loaded sucessfully" << std::endl;
		frameRateText.setFont(font);

	}
	else {
		std::cout << "arial.ttf font in assets failed to load" << std::endl;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}

void FrameRate::Update(double deltaTime)
{
	timer += deltaTime;

	if (timer >= 100.0f) {
		double frameRate = 1000.0f / deltaTime;
		std::string frameRateString = "FPS: " + std::to_string((int)frameRate) +
			"   Frame time: " +
			std::to_string(deltaTime);

		frameRateText.setString(frameRateString);

		timer = 0;
	}
}
