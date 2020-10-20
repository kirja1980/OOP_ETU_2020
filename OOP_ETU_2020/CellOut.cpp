#include "pixel.h"

// CELL_OUT--------------------

CellOut::CellOut() {
	color = { 255,255,255,255 };//Белый цвет
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setSize(PIXEL_SIZE);
}

CellOut::CellOut(sf::Vector2f& vec) {
	color = { 255,255,255,255 };//Белый цвет
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellOut& CellOut::operator=(const CellOut& cellout) {
	if (this != &cellout) {
		this->color = cellout.color;
		this->shape = cellout.shape;
		this->cords = cellout.cords;
	}
	return *this;
}

sf::Vector2f CellOut::getCords() const {
	return cords;
}//получение координат клетки


char CellOut::getMarker() const {
	return ' ';
}//получение клетки как объекта

void CellOut::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//установить координаты клетки


void CellOut::setColor(sf::Color color) {
	this->color = color;
}//установить цвет клетки


void CellOut::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//отрисовать клетку

CellOut::~CellOut() {};//деструктор игровой клетки