#pragma once
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "pixel.h"

class field {
public:
	field();
	field(sf::Vector2f vec);

	void draw(sf::RenderWindow& window);//отрисовать поле
	~field();

private:
	sf::Vector2f field_vec;
	IGameCell*** arr;
};