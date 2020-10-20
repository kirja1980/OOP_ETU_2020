#pragma once
#include "Interface.h"

class CellWall : public IGameCell
{
public:
	CellWall();
	CellWall(sf::Vector2f& vec);
	
	CellWall& operator= (const CellWall& callwall);

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

	CellLand& operator= (const CellLand& cellland);

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

class CellIn : public IGameCell
{
public:
	CellIn();
	CellIn(sf::Vector2f& vec);

	CellIn& operator= (const CellIn& cellin);

	virtual sf::Vector2f getCords()  const override;//��������� ��������� ������
	virtual char getMarker() const override;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) override;//���������� ���������� ������
	virtual void setColor(sf::Color color) override;//���������� ���� ������
	virtual void draw(sf::RenderWindow& window) override;//���������� ������

	virtual ~CellIn() override;//���������� ������� ������
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};

class CellOut : public IGameCell
{
public:
	CellOut();
	CellOut(sf::Vector2f& vec);

	CellOut& operator= (const CellOut& cellout);

	virtual sf::Vector2f getCords()  const override;//��������� ��������� ������
	virtual char getMarker() const override;//��������� ������ ��� �������

	virtual void setCords(sf::Vector2f cords) override;//���������� ���������� ������
	virtual void setColor(sf::Color color) override;//���������� ���� ������
	virtual void draw(sf::RenderWindow& window) override;//���������� ������

	virtual ~CellOut() override;//���������� ������� ������
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};