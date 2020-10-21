#include "players.h"
#include "Interface.h"

MyPerson::MyPerson() {
	color = { 66,170,255 };
	cords = { 1 * PIXEL_SIZE.x,1 * PIXEL_SIZE.y};

	leg_shape.setFillColor(sf::Color(0, 0, 0, 255));
	leg_shape.setPosition(cords);
	leg_shape.setSize(MY_LEG_SIZE);

	shape.setFillColor(color);
	shape.setPosition(cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
	shape.setSize(MY_PLAYER_SIZE);


}

MyPerson::~MyPerson() {}


sf::Vector2f MyPerson::getCords() const {
	return cords;
}

void MyPerson::move(sf::Vector2f cords) {
	this->cords += cords;
	leg_shape.setPosition(this->cords);
	shape.setPosition(this->cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
}

void MyPerson::setCords(sf::Vector2f cords) {
	this->cords = cords;
	leg_shape.setPosition(this->cords);
	shape.setPosition(this->cords - sf::Vector2f(0,3 * PIXEL_SIZE.y));
}

void MyPerson::setColor(sf::Color color) {
	this->color = color;
	shape.setFillColor(color);
}

void MyPerson::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

