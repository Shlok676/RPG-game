#include <SFML\Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"
#include <math.h>

int main() {

	// --------------------------------------- Initialize ------------------------------------ //

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default, settings);

	window.setFramerateLimit(200);

	

	// --------------------------------------- Initialize ------------------------------------ //

	Player player;
	Skeleton skeleton;

	// --------------------------------------- Initialize ------------------------------------ //

	player.Initialize();
	skeleton.Initialize();

	// --------------------------------------- Initialize ------------------------------------ //
	
	
	// --------------------------------------- Load ------------------------------------------ //

	player.Load();
	skeleton.Load();
	
	// --------------------------------------- Load ------------------------------------------ //

	while (window.isOpen()) {

		// --------------------------------------- Update ------------------------------------ //
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		skeleton.Update();
		player.Update(skeleton);

		// --------------------------------------- Update ------------------------------------ //

		// --------------------------------------- Draw -------------------------------------- //

		window.clear(sf::Color::Black);

		skeleton.Draw(window);
		player.Draw(window);

		window.display();

		// --------------------------------------- Draw -------------------------------------- //
	}

	return 0;
}