#pragma once
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "pixel.h"

class field {
public:
	field();
	field(sf::Vector2f vec);

	char getMarker(sf::Vector2f vec);
	sf::Vector2f getSize();

	void draw(sf::RenderWindow& window);//отрисовать поле
	~field();

private:
	sf::Vector2f field_vec;
	IGameCell*** arr;
};