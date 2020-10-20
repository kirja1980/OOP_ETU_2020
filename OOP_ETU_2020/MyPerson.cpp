#include "players.h"
#include "Interface.h"

MyPerson::MyPerson() {
	color = { 66,170,255 };
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(5, 5));
	shape.setSize(MY_PLAYER_SIZE);
}

MyPerson::~MyPerson() {}


sf::Vector2f MyPerson::getCords() const {
	return cords;
}

void MyPerson::move(sf::Vector2f cords) {
	this->cords += cords;
	shape.setPosition(this->cords);
}

void MyPerson::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}

void MyPerson::setColor(sf::Color color) {
	this->color = color;
	shape.setFillColor(color);
}

void MyPerson::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

