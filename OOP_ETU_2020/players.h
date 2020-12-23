#pragma once
#include "Interface.h"

class MyPerson : public IPerson{
public:
	MyPerson();

	virtual ~MyPerson() override;

	virtual sf::Vector2f getCords() const override;
	/*virtual sf::FloatRect GetGlobalBounds() const override;*/
	virtual int getHP() const override;
	virtual void loss(double damage) override;
	virtual void logg() override;
	virtual bool isLive() override;

	void operator--(int);
	virtual int shootform(unsigned random) override;
	virtual void move(sf::Vector2f cords) override;
	virtual void setCords(sf::Vector2f cords) override;
	virtual void setColor(sf::Color color) override;

	void LoadGame(std::ifstream &path);
	void SaveGame(std::ofstream &path);
	virtual void draw(sf::RenderWindow& window) override;
//private:
	sf::RectangleShape shape;
	sf::RectangleShape leg_shape;
	sf::Color color;
	sf::Vector2f cords;
	std::fstream logging;
	int hp;
	int damage;
};


class Tank : public IPerson {
public:
	Tank();

	virtual ~Tank() override;

	virtual sf::Vector2f getCords() const override;
	/*virtual sf::FloatRect GetGlobalBounds() const override;*/
	virtual int getHP() const override;
	virtual void loss(double damage) override;
	virtual void logg() override;
	virtual bool isLive() override;

	void operator--(int);
	virtual int shootform(unsigned random) override;
	void shoot();
	virtual void move(sf::Vector2f cords) override;
	virtual void setCords(sf::Vector2f cords) override;
	virtual void setColor(sf::Color color) override;

	void LoadGame(std::ifstream &path);
	void SaveGame(std::ofstream &path);
	virtual void draw(sf::RenderWindow& window) override;
//private:
	sf::RectangleShape shape;
	sf::RectangleShape leg_shape;
	sf::Color color;
	sf::Vector2f cords;
	std::fstream logging;
	int hp;
	int damage;
	sf::RectangleShape attack;
	int type_attack;
};