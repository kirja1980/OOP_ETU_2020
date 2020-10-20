#pragma once

#include <SFML/Graphics.hpp>
#define PIXEL_SIZE (sf::Vector2f(4,4))

class IGameCell
{
public:
	virtual ~IGameCell() = default;//деструктор игровой клетки

	virtual sf::Vector2f getCords() const = 0;//получение координат клетки
	virtual char getMarker() const = 0;//получение клетки как объекта

	virtual void setCords(sf::Vector2f cords) = 0;//установить координаты клетки
	virtual void setColor(sf::Color color) = 0;//установить цвет клетки

	virtual void draw(sf::RenderWindow& window) = 0;//отрисовать клетку
};