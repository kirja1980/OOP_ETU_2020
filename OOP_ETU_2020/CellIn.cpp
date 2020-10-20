#include "pixel.h"

// CELL_IN--------------------

CellIn::CellIn() {
	color = { 150,150,150,255 };//серый цвет
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setSize(PIXEL_SIZE);
}

CellIn::CellIn(sf::Vector2f& vec) {
	color = { 150,150,150,255 };//серый цвет
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellIn& CellIn::operator=(const CellIn& cellin) {
	if (this != &cellin) {
		this->color = cellin.color;
		this->shape = cellin.shape;
		this->cords = cellin.cords;
	}
	return *this;
}

sf::Vector2f CellIn::getCords() const {
	return cords;
}//получение координат клетки

char CellIn::getMarker() const {
	return '>';
}//получение клетки как объекта

void CellIn::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//установить координаты клетки


void CellIn::setColor(sf::Color color) {
	this->color = color;
}//установить цвет клетки


void CellIn::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//отрисовать клетку


CellIn::~CellIn() {};//деструктор игровой клетки