#include <SFML/Graphics.hpp>
#include <C:\Users\kirja\source\repos\OOP_ETU_2020\OOP_ETU_2020\Interface.h>

int main()

{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFMLworks");

	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())

	{
		
		sf::Event event;

		while (window.pollEvent(event))

		{

			if (event.type == sf::Event::Closed)

				window.close();

		}

		window.clear();

		window.draw(shape);

		window.display();

	}

	return 0;

}