#pragma once
#include "Interface.h"

class CellWall : IGameCell
{
public:
	CellWall();
	

	virtual sf::Vector2f getCords()  const override;//получение координат клетки
	virtual char getMarker() const override;//получение клетки как объекта

	virtual void setCords(sf::Vector2f cords) override;//установить координаты клетки
	virtual void setColor(sf::Color color) override;//установить цвет клетки
	sf::Vector2f a;
	virtual void draw(sf::RenderWindow& window) override;//отрисовать клетку

	virtual ~CellWall() override;//деструктор игровой клетки
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};

class CellLand : IGameCell
{
public:
	CellLand();

	virtual sf::Vector2f getCords()  const override;//получение координат клетки
	virtual char getMarker() const override;//получение клетки как объекта

	virtual void setCords(sf::Vector2f cords) override;//установить координаты клетки
	virtual void setColor(sf::Color color) override;//установить цвет клетки
	sf::Vector2f a;
	virtual void draw(sf::RenderWindow& window) override;//отрисовать клетку

	virtual ~CellLand() override;//деструктор игровой клетки
private:
	sf::RectangleShape shape;
	sf::Color color;
};