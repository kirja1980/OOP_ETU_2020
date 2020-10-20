#include "pixel.h"

// CELL_OUT--------------------

CellOut::CellOut() {
	color = { 255,255,255,255 };//����� ����
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0, 0));
	shape.setSize(PIXEL_SIZE);
}

CellOut::CellOut(sf::Vector2f& vec) {
	color = { 255,255,255,255 };//����� ����
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
}//��������� ��������� ������


char CellOut::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellOut::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//���������� ���������� ������


void CellOut::setColor(sf::Color color) {
	this->color = color;
}//���������� ���� ������


void CellOut::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//���������� ������

CellOut::~CellOut() {};//���������� ������� ������