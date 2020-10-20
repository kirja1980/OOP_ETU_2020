#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "field.h"
#include "players.h"
#include "PlayerControl.h"


int main()

{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SRU.L.K.E.R. CALL FROM THE TOILET");

	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Green);

	field f;
	MyPerson pers;
	while (window.isOpen())

	{
		
		sf::Event event;

		while (window.pollEvent(event))

		{

			if (event.type == sf::Event::Closed)

				window.close();

		}

		window.clear();
		f.draw(window);
		PlayerControl(pers,f);
		pers.draw(window);

		//window.draw(shape);

		window.display();

	}

	return 0;

}