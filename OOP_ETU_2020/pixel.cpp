#include "pixel.h"

CellWall::CellWall() {
	
}

CellWall::~CellWall() {};//деструктор игровой клетки

sf::Vector2f CellWall::getCords() const {
	return sf::Vector2f(0,0);
}//получение координат клетки


char CellWall::getMarker() const {
	return ' ';
}//получение клетки как объекта

void CellWall::setCords(sf::Vector2f cords) {

}//установить координаты клетки


void CellWall::setColor(sf::Color color) {

}//установить цвет клетки


void CellWall::draw(sf::RenderWindow& window) {


}//отрисовать клетку


CellLand::CellLand() {

}

CellLand::~CellLand() {};//деструктор игровой клетки

sf::Vector2f CellLand::getCords() const {
	return sf::Vector2f(0, 0);
}//получение координат клетки


char CellLand::getMarker() const {
	return ' ';
}//получение клетки как объекта

void CellLand::setCords(sf::Vector2f cords) {

}//установить координаты клетки


void CellLand::setColor(sf::Color color) {

}//установить цвет клетки


void CellLand::draw(sf::RenderWindow& window) {


}//отрисовать клетку