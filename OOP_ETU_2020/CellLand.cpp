#include "pixel.h"

CellLand::CellLand() {
	double r = std::rand() % 100;
	if (r >= 50 && r < 60)
		color = { 0,10,150,64 };
	else if (r >= 60 && r < 100)
		color = { 0,144,238,144 };
	else
		color = { 0,100,0,255 };//зеленый цвет
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setSize(PIXEL_SIZE);
}

CellLand::CellLand(sf::Vector2f& vec) {
	color = { 60,60,60,255 };//зеленый цвет
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellLand& CellLand::operator=(const CellLand& cellland) {
	if (this != &cellland) {
		this->color = cellland.color;
		this->shape = cellland.shape;
		this->cords = cellland.cords;
	}
	return *this;
}

sf::Color CellLand::GetColor() const {
	return color;
}

sf::Vector2f CellLand::getCords() const {
	return cords;
}//получение координат клетки


char CellLand::getMarker() const {
	return '0';
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

CellLand::~CellLand() {};//деструктор игровой клетки