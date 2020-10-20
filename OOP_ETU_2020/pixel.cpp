#include "pixel.h"

CellWall::CellWall() {
	color = { 152, 118, 84 };
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0,0));
	shape.setSize(PIXEL_SIZE);
}

CellWall::CellWall(sf::Vector2f& vec) {
	color = {152, 118, 84};
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellWall::~CellWall() {};//деструктор игровой клетки

sf::Vector2f CellWall::getCords() const {
	return sf::Vector2f(0,0);
}//получение координат клетки


char CellWall::getMarker() const {
	return ' ';
}//получение клетки как объекта

void CellWall::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//установить координаты клетки


void CellWall::setColor(sf::Color color) {
	this->color = color;
}//установить цвет клетки


void CellWall::draw(sf::RenderWindow& window) {
	window.draw(shape);
}//отрисовать клетку


CellLand::CellLand() {
	color = { 152, 118, 84 };
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0,0));
	shape.setSize(PIXEL_SIZE);
}

CellLand::CellLand(sf::Vector2f& vec) {
	color = { 152, 118, 84 };
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellLand::~CellLand() {};//деструктор игровой клетки

sf::Vector2f CellLand::getCords() const {
	return sf::Vector2f(0, 0);
}//получение координат клетки


char CellLand::getMarker() const {
	return ' ';
}//получение клетки как объекта

void CellLand::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//установить координаты клетки


void CellLand::setColor(sf::Color color) {
	this->color = color;
}//установить цвет клетки


void CellLand::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//отрисовать клетку