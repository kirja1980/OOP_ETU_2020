#include "pixel.h"

CellWall::CellWall() {
	
}

CellWall::~CellWall() {};//���������� ������� ������

sf::Vector2f CellWall::getCords() const {
	return sf::Vector2f(0,0);
}//��������� ��������� ������


char CellWall::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellWall::setCords(sf::Vector2f cords) {

}//���������� ���������� ������


void CellWall::setColor(sf::Color color) {

}//���������� ���� ������


void CellWall::draw(sf::RenderWindow& window) {


}//���������� ������


CellLand::CellLand() {

}

CellLand::~CellLand() {};//���������� ������� ������

sf::Vector2f CellLand::getCords() const {
	return sf::Vector2f(0, 0);
}//��������� ��������� ������


char CellLand::getMarker() const {
	return ' ';
}//��������� ������ ��� �������

void CellLand::setCords(sf::Vector2f cords) {

}//���������� ���������� ������


void CellLand::setColor(sf::Color color) {

}//���������� ���� ������


void CellLand::draw(sf::RenderWindow& window) {


}//���������� ������