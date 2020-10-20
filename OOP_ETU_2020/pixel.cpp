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

CellWall::~CellWall() {};//���������� ������� ������

sf::Vector2f CellWall::getCords() const {
	return sf::Vector2f(0,0);
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

CellLand::~CellLand() {};//���������� ������� ������

sf::Vector2f CellLand::getCords() const {
	return sf::Vector2f(0, 0);
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