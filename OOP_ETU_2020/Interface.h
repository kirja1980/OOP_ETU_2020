#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#define PIXEL_SIZE (sf::Vector2f(4,4))
#define MY_PLAYER_SIZE (sf::Vector2f(4*2,4*4))
#define MY_LEG_SIZE (sf::Vector2f(4*2,1*4))

class IGameCell
{
public:
	virtual ~IGameCell() = default;//деструктор игровой клетки

	virtual sf::Vector2f getCords() const = 0;//получение координат клетки
	virtual char getMarker() const = 0;//получение клетки как объекта
	virtual sf::Color GetColor() const = 0;

	virtual void setCords(sf::Vector2f cords) = 0;//установить координаты клетки
	virtual void setColor(sf::Color color) = 0;//установить цвет клетки

	virtual void draw(sf::RenderWindow& window) = 0;//отрисовать клетку
};

class IPerson {
public:
	virtual ~IPerson() = default;

	virtual sf::Vector2f getCords() const = 0;
	/*virtual sf::FloatRect GetGlobalBounds() const = 0;*/
	virtual int getHP() const = 0;
	virtual void loss(double damage) = 0;
	virtual void logg() = 0;
	virtual bool isLive() = 0;

	virtual int shootform(unsigned random) = 0;
	virtual void move(sf::Vector2f cords) = 0;
	virtual void setCords(sf::Vector2f cords) = 0;
	virtual void setColor(sf::Color color) = 0;

	virtual void draw(sf::RenderWindow& window) = 0;
};