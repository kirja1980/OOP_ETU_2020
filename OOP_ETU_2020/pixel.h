#pragma once
#include "Interface.h"

class CellWall : IGameCell
{
public:
	CellWall();
	

	virtual sf::Vector2f getCords()  const override;//��������� ��������� ������
	virtual char getMarker() const override;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) override;//���������� ���������� ������
	virtual void setColor(sf::Color color) override;//���������� ���� ������
	sf::Vector2f a;
	virtual void draw(sf::RenderWindow& window) override;//���������� ������

	virtual ~CellWall() override;//���������� ������� ������
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};

class CellLand : IGameCell
{
public:
	CellLand();

	virtual sf::Vector2f getCords()  const override;//��������� ��������� ������
	virtual char getMarker() const override;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) override;//���������� ���������� ������
	virtual void setColor(sf::Color color) override;//���������� ���� ������
	sf::Vector2f a;
	virtual void draw(sf::RenderWindow& window) override;//���������� ������

	virtual ~CellLand() override;//���������� ������� ������
private:
	sf::RectangleShape shape;
	sf::Color color;
};