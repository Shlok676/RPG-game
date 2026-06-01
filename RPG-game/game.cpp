#include <SFML\Graphics.hpp>

int main() {

	// --------------------------------------- Initialize ------------------------------------ //

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Default, settings);

	window.setFramerateLimit(120);

	sf::CircleShape circle(50.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(400 - 50, 300 - 50));
	circle.setOutlineThickness(5.0f);
	circle.setOutlineColor(sf::Color::Green);

	sf::RectangleShape rectangle(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(sf::Vector2f(150 - 100, 150 - 50));
	rectangle.setOutlineThickness(3.0f);
	rectangle.setOutlineColor(sf::Color::Cyan);
	// rectangle.setOrigin(rectangle.getSize() / 2.0f);
	// rectangle.setRotation(45);

	sf::CircleShape triangle(70.0f, 3);
	triangle.setFillColor(sf::Color::Magenta);
	triangle.setPosition(sf::Vector2f(700 - 70, 500 - 70));
	triangle.setOutlineColor(sf::Color::Yellow);
	triangle.setOutlineThickness(3.0f);

	sf::CircleShape pentagon(60.0f, 5);
	pentagon.setFillColor(sf::Color::Green);
	pentagon.setPosition(sf::Vector2f(700 - 60, 150 - 60));
	pentagon.setOutlineColor(sf::Color(139, 69, 19, 255));
	pentagon.setOutlineThickness(3.0f);

	sf::CircleShape octagon(50.0f, 8);
	octagon.setFillColor(sf::Color(192, 41, 43));
	octagon.setPosition(sf::Vector2f(100 - 50, 500 - 50));
	octagon.setOutlineColor(sf::Color(241, 196, 15));
	octagon.setOutlineThickness(3.0f);

	// --------------------------------------- Initialize ------------------------------------ //

	while (window.isOpen()) {

		// --------------------------------------- Update ------------------------------------ //
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// --------------------------------------- Update ------------------------------------ //

		// --------------------------------------- Draw -------------------------------------- //

		window.clear(sf::Color::Black);

		window.draw(circle);
		window.draw(rectangle);
		window.draw(triangle);
		window.draw(pentagon);
		window.draw(octagon);

		window.display();

		// --------------------------------------- Draw -------------------------------------- //
	}

	return 0;
}