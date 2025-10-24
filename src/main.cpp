#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <iostream>
int main(int argc, char** argv)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> degree_range(0, 360);

	auto window = sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "sfml.dvd", sf::State::Fullscreen);

	sf::Texture dvdTexture;

	if (!dvdTexture.loadFromFile(argv[1] ? argv[1] : "dvd.png")) {
		std::cerr << argv[0] << " <dvd.png>\n";
		std::cerr << "Either put a dvd.png image in current directory or provide the path\n";
	}

	sf::Sprite dvd(dvdTexture);
	auto [screenX, screenY] = window.getSize();
	dvd.setPosition({ static_cast<float>(screenX / 2), static_cast<float>(screenY / 2) });
	dvd.setScale({ 0.2, 0.2 });

	sf::Vector2f velocity{ 500.f, sf::Angle(sf::degrees(degree_range(gen))) };
	sf::Clock clock;
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
		}

		float dvdX = dvd.getGlobalBounds().position.x;
		float dvdY = dvd.getGlobalBounds().position.y;


		if (dvdX > screenX - dvd.getGlobalBounds().size.x || dvdX < 0) {
			dvd.setColor(sf::Color(degree_range(gen) % 255, degree_range(gen) % 255, degree_range(gen) % 255));
			velocity.x = -velocity.x;
		}

		if (dvdY > screenY - dvd.getGlobalBounds().size.y || dvdY < 0) {
			dvd.setColor(sf::Color(degree_range(gen) % 255, degree_range(gen) % 255, degree_range(gen) % 255));
			velocity.y = -velocity.y;
		}

		dvd.move(velocity * dt);

		window.clear();
		window.draw(dvd);
		window.display();
	}
}
