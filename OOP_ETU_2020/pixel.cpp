#include "pixel.h"

// CELL_WALL--------------------

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


CellLand::CellLand() {
	double r = std::rand() % 100;
	if (r >= 50 && r < 60)
		color = { 0,10,150,64 };
	else if (r >= 60 && r < 100)
		color = { 0,144,238,144 };
	else
		color = { 0,100,0,255 };//������� ����
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0,0));
	shape.setSize(PIXEL_SIZE);
}

// CELL_LAND--------------------

CellLand::CellLand(sf::Vector2f& vec) {
	color = { 60,60,60,255 };//������� ����
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

sf::Vector2f CellLand::getCords() const {
	return cords;
}//��������� ��������� ������


char CellLand::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellLand::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//���������� ���������� ������


void CellLand::setColor(sf::Color color) {
	this->color = color;
}//���������� ���� ������


void CellLand::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//���������� ������

CellLand::~CellLand() {};//���������� ������� ������

// CELL_IN--------------------

CellIn::CellIn() {
	color = { 150,150,150,255 };//����� ����
	shape.setFillColor(color);
	shape.setPosition(sf::Vector2f(0,0));
	shape.setSize(PIXEL_SIZE);
}

CellIn::CellIn(sf::Vector2f& vec) {
	color = { 150,150,150,255 };//����� ����
	shape.setFillColor(color);
	shape.setPosition(vec);
	shape.setSize(PIXEL_SIZE);
}

sf::Vector2f CellIn::getCords() const {
	return cords;
}//��������� ��������� ������

char CellIn::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellIn::setCords(sf::Vector2f cords) {
	this->cords = cords;
	shape.setPosition(this->cords);
}//���������� ���������� ������


void CellIn::setColor(sf::Color color) {
	this->color = color;
}//���������� ���� ������


void CellIn::draw(sf::RenderWindow& window) {
	window.draw(shape);

}//���������� ������


CellIn::~CellIn() {};//���������� ������� ������


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