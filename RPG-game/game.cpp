#include <SFML\Graphics.hpp>
#include <iostream>

int main() {

	// --------------------------------------- Initialize ------------------------------------ //

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Default, settings);

	window.setFramerateLimit(200);

	

	// --------------------------------------- Initialize ------------------------------------ //

	// --------------------------------------- Load ------------------------------------------ //

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {

		playerSprite.setTexture(playerTexture);
		std::cout << "Player image loaded" << std::endl;

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(sf::Vector2f(3, 3));
	}
	else{
		std::cout << "Player image failed to load" << std::endl;
	}
	

	// --------------------------------------- Load ------------------------------------------ //

	while (window.isOpen()) {

		// --------------------------------------- Update ------------------------------------ //
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::F) {

					sf::Vector2f position = playerSprite.getPosition();
					playerSprite.setPosition(position + sf::Vector2f(10, 0));
				}

			}
		}

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerSprite.setPosition(position + sf::Vector2f(0, -1));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		}

		// --------------------------------------- Update ------------------------------------ //

		// --------------------------------------- Draw -------------------------------------- //

		window.clear(sf::Color::Black);

		window.draw(playerSprite);

		window.display();

		// --------------------------------------- Draw -------------------------------------- //
	}

	return 0;
}