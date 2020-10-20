#include "pixel.h"

// CELL_WALL--------------------

CellWall::CellWall() {
	color = { 152, 118, 84 };
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setSize(PIXEL_SIZE);
}

CellWall::CellWall(sf::Vector2f& vec) {
	color = { 152, 118, 84 };
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

CellWall& CellWall::operator=(const CellWall& cellwall) {
	if (this != &cellwall) {
		this->color = cellwall.color;
		this->shape = cellwall.shape;
		this->cords = cellwall.cords;
	}
	return *this;
}

CellWall::~CellWall() {};//���������� ������� ������

sf::Vector2f CellWall::getCords() const {
	return cords;
}//��������� ��������� ������


char CellWall::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellWall::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//���������� ���������� ������


void CellWall::setColor(sf::Color color) {
	this->color = color;
}//���������� ���� ������


void CellWall::draw(sf::RenderWindow& window) {
	window.draw(shape);
}//���������� ������