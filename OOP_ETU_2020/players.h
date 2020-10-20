#pragma once
#include "Interface.h"

class MyPerson : public IPerson{
public:
	MyPerson();

	virtual ~MyPerson() override;

	virtual sf::Vector2f getCords() const override;

	virtual void move(sf::Vector2f cords) override;
	virtual void setCords(sf::Vector2f cords) override;
	virtual void setColor(sf::Color color) override;

	virtual void draw(sf::RenderWindow& window) override;
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f cords;
};