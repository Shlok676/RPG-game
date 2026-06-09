#include "Player.h"
#include "Math.h"

Player::Player() :
	playerSpeed(1.0f), maxFireRate(150), fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {

		sprite.setTexture(texture);
		std::cout << "Player texture loaded" << std::endl;

		int XIndex = 0;
		int YIndex = 0;
		 
		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(150, 100));
		sprite.scale(sf::Vector2f(3, 3));

		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
		boundingRectangle.setPosition(sf::Vector2f(150, 100));
	}
	else {
		std::cout << "Player texture failed to load" << std::endl;
	}
	
}


void Player::Update(float deltaTime, sf::Vector2f& mousePosition, Skeleton& skeleton)
{

	sf::Vector2f movement(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement.y += -1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x += -1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement.y += 1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += 1.0f;
	}

	sprite.move(movement * playerSpeed * (float)deltaTime);


	fireRateTimer += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {
		bullets.push_back(Bullet());

		int i = bullets.size() - 1;

		bullets[i].Initialize(sprite.getPosition(), mousePosition, 1.0f);

		fireRateTimer = 0;
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update(deltaTime);

		if (skeleton.health > 0) {
			if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
				skeleton.changeHealth(-10);
				bullets.erase(bullets.begin() + i);

			}
		}
	}
	boundingRectangle.setPosition(sprite.getPosition());
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}
}