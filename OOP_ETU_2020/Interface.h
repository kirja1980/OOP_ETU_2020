#pragma once

#include <SFML/Graphics.hpp>

class IGameCell
{
public:
	virtual ~IGameCell() = default;

	virtual sf::Vector2f getCords() const = 0;
	virtual char getMarker() const = 0;
	virtual bool getGlobalCords(sf::Vector2f pos, size_t i, size_t j) const = 0;

	virtual void setCords(sf::Vector2f cords) = 0;
	virtual void setColor(sf::Color color) = 0;

	virtual void draw(sf::RenderWindow& window) = 0;
};