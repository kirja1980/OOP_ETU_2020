#include "players.h"

Tank::Tank() {
	logging.open("LogTank.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	color = { 120,120,120 };
	cords = { 10 * PIXEL_SIZE.x,10 * PIXEL_SIZE.y };

	leg_shape.setFillColor(sf::Color(0, 0, 0, 255));
	leg_shape.setPosition(cords);
	leg_shape.setSize(MY_LEG_SIZE);

	shape.setFillColor(color);
	shape.setPosition(cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
	shape.setSize(MY_PLAYER_SIZE);
	hp = 100;
	damage = 30;
	unsigned random = rand() % 100;
	type_attack = shootform(random);
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

void Tank::operator--(int) {
	this->loss(-3);
}

int Tank::shootform(unsigned random) {
	
	
	attack.setFillColor(sf::Color(255,0,0));
	if (random < 34) {
		attack.setPosition(cords - sf::Vector2f(2 * PIXEL_SIZE.x, 5 * PIXEL_SIZE.y));
		attack.setSize(sf::Vector2f(30,30));
		return 1;
	}
	else if (random < 67) {
		attack.setPosition(cords);
		attack.setSize(sf::Vector2f(40, 5));
		return 2;
	}
	else {
		attack.setPosition(cords);
		attack.setSize(sf::Vector2f(5, 40));
		return 3;
	}
	
}

void Tank::shoot() {
	
	if(type_attack == 2)
		attack.rotate(5);
	else if(type_attack == 3)
	{
		attack.rotate(-5);
	}
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
	if (type_attack == 1) {
		attack.setPosition(cords - sf::Vector2f(2 * PIXEL_SIZE.x, 5 * PIXEL_SIZE.y));
	}
	else {
		attack.setPosition(cords);
	}
}

void Tank::setColor(sf::Color color) {
	this->color = color;
	shape.setFillColor(color);
}



void Tank::LoadGame(std::ifstream &path) {
	int rotat = 0;
	sf::Vector2f cord;
	path >> cord.x;
	path >> cord.y;
	setCords(cord);
	path >> hp;
	path >> rotat;
	attack.setRotation(rotat);
}

void Tank::SaveGame(std::ofstream &path) {
	path << cords.x << ' ' << cords.y << ' ' << hp << ' '<< attack.getRotation() <<'\n';
}

void Tank::draw(sf::RenderWindow& window) {
	window.draw(attack);
	window.draw(shape);
}