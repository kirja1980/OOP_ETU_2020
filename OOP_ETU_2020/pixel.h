#pragma once
#include "Interface.h"

class CellWall : public IGameCell
{
public:
	CellWall();
	CellWall(sf::Vector2f& vec);
	

	virtual sf::Vector2f getCords()  const override;//получение координат клетки
	virtual char getMarker() const override;//получение клетки как объекта

	virtual void setCords(sf::Vector2f cords) override;//установить координаты клетки
	virtual void setColor(sf::Color color) override;//установить цвет клетки
	virtual void draw(sf::RenderWindow& window) override;//отрисовать клетку

	virtual ~CellWall() override;//деструктор игровой клетки
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};

class CellLand : public IGameCell
{
public:
	CellLand();
	CellLand(sf::Vector2f& vec);

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
	sf::Vector2f cords;
};