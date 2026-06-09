#include <SFML\Graphics.hpp>

#include "FrameRate.h"
#include "Map.h"
#include "MapLoader.h"
#include "Player.h"
#include "Skeleton.h"

int main() {

	// --------------------------------------- Initialize ------------------------------------ //

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default, settings);
	window.setFramerateLimit(360);

	// --------------------------------------- Initialize ------------------------------------ //

	FrameRate frameRate;
	Map map;
	MapLoader mapLoader;
	Player player;
	Skeleton skeleton;

	// --------------------------------------- Initialize ------------------------------------ //

	frameRate.Initialize();
	map.Initialize();
	player.Initialize();
	skeleton.Initialize();

	// --------------------------------------- Initialize ------------------------------------ //
	
	
	// --------------------------------------- Load ------------------------------------------ //

	frameRate.Load();
	map.Load();
	mapLoader.Load("Assets/Maps/Level-1.rmap");
	player.Load();
	skeleton.Load();
	
	// --------------------------------------- Load ------------------------------------------ //

	sf::Clock clock;

	// main game loop
	while (window.isOpen()) {

		// --------------------------------------- Update ------------------------------------ //
		sf::Event event;

		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}	

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		frameRate.Update(deltaTime);
		map.Update(deltaTime);
		skeleton.Update(deltaTime);
		player.Update(deltaTime, mousePosition, skeleton);

		// --------------------------------------- Update ------------------------------------ //

		// --------------------------------------- Draw -------------------------------------- //

		window.clear(sf::Color::Black);

		map.Draw(window);
		skeleton.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);

		window.display();

		// --------------------------------------- Draw -------------------------------------- //
	}

	return 0;
}