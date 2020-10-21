#pragma once

#include <SFML/Graphics.hpp>
#define PIXEL_SIZE (sf::Vector2f(4,4))
#define MY_PLAYER_SIZE (sf::Vector2f(4*2,4*4))
#define MY_LEG_SIZE (sf::Vector2f(4*2,1*4))

class IGameCell
{
public:
	virtual ~IGameCell() = default;//���������� ������� ������

	virtual sf::Vector2f getCords() const = 0;//��������� ��������� ������
	virtual char getMarker() const = 0;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) = 0;//���������� ���������� ������
	virtual void setColor(sf::Color color) = 0;//���������� ���� ������

	virtual void draw(sf::RenderWindow& window) = 0;//���������� ������
};

class IPerson {
public:
	virtual ~IPerson() = default;

	virtual sf::Vector2f getCords() const = 0;
	
	virtual void move(sf::Vector2f cords) = 0;
	virtual void setCords(sf::Vector2f cords) = 0;
	virtual void setColor(sf::Color color) = 0;

	virtual void draw(sf::RenderWindow& window) = 0;
};