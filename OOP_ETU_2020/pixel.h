#pragma once
#include "Interface.h"

class CellWall : public IGameCell
{
public:
	CellWall();
	CellWall(sf::Vector2f& vec);
	

	virtual sf::Vector2f getCords()  const override;//��������� ��������� ������
	virtual char getMarker() const override;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) override;//���������� ���������� ������
	virtual void setColor(sf::Color color) override;//���������� ���� ������
	virtual void draw(sf::RenderWindow& window) override;//���������� ������

	virtual ~CellWall() override;//���������� ������� ������
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
	sf::Vector2f cords;
};