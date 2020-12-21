#include "players.h"

Tank::Tank() {
	logging.open("LogTank.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	color = { 0,0,0 };
	cords = { 10 * PIXEL_SIZE.x,10 * PIXEL_SIZE.y };

	leg_shape.setFillColor(sf::Color(0, 0, 0, 255));
	leg_shape.setPosition(cords);
	leg_shape.setSize(MY_LEG_SIZE);

	shape.setFillColor(color);
	shape.setPosition(cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
	shape.setSize(MY_PLAYER_SIZE);
	hp = 100;
	damage = 30;
	shootform();
}

Tank::~Tank() {
	logging << "\n";
	logging.close();
}

sf::Vector2f Tank::getCords() const {
	return cords;
}

int Tank::getHP() const {
	return hp;
}

void Tank::loss(double damage) {
	hp += damage;
}

void Tank::logg() {
	logging << "(" << cords.x << ";" << cords.y << ") ";
}

bool Tank::isLive() {
	if (hp <= 0) return false;
	return true;
}

void Tank::shootform() {
	unsigned random = rand() % 100;
	
	attack.setFillColor(sf::Color(255,0,0));
	if (random < 134) {
		attack.setPosition(cords - sf::Vector2f(2 * PIXEL_SIZE.x, 5 * PIXEL_SIZE.y));
		attack.setSize(sf::Vector2f(30,30));
		
	}
	else if (random < 67) {
		attack.setSize(sf::Vector2f(40, 5));
	}
	else {
		attack.setSize(sf::Vector2f(5, 40));
	}
	
}

void Tank::shoot() {
	attack.setRotation(5);
}

void Tank::move(sf::Vector2f cords) {
	this->cords += cords;
	setCords(this->cords);
}

void Tank::setCords(sf::Vector2f cords) {
	this->cords = cords;
	logg();
	leg_shape.setPosition(this->cords);
	shape.setPosition(this->cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
}

void Tank::setColor(sf::Color color) {
	this->color = color;
	shape.setFillColor(color);
}

void Tank::draw(sf::RenderWindow& window) {
	window.draw(attack);
	window.draw(shape);
}