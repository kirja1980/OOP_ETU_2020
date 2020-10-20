#pragma once

#include <SFML/Graphics.hpp>
#define PIXEL_SIZE (sf::Vector2f(4,4))

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