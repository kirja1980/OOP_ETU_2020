#include "players.h"
#include "Interface.h"

MyPerson::MyPerson() {
	logging.open("LogMyPlayer.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	color = { 66,170,255 };
	cords = { 1 * PIXEL_SIZE.x,1 * PIXEL_SIZE.y};
	
	leg_shape.setFillColor(sf::Color(0, 0, 0, 255));
	leg_shape.setPosition(cords);
	leg_shape.setSize(MY_LEG_SIZE);

	shape.setFillColor(color);
	shape.setPosition(cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
	shape.setSize(MY_PLAYER_SIZE);
	hp = 100;
	damage = 30;

}

MyPerson::~MyPerson() {
	logging << "\n";
	logging.close();
}


sf::Vector2f MyPerson::getCords() const {
	return cords;
}

//sf::FloatRect MyPerson::GetGlobalBounds() const {
//	return leg_shape.getGlobalBounds();
//}

int MyPerson::getHP() const {
	return hp;
}

void MyPerson::loss(double damage) {
	hp += damage;
}

void MyPerson::logg() {
	logging << "(" << cords.x << ";" << cords.y << ") ";
}

bool MyPerson::isLive() {
	if (hp <= 0) return false;
	return true;
}

void MyPerson::shootform() {

}

void MyPerson::move(sf::Vector2f cords) {
	this->cords += cords;
	setCords(this->cords);
	/*
	leg_shape.setPosition(this->cords);
	shape.setPosition(this->cords - sf::Vector2f(0, 3 * PIXEL_SIZE.y));
	*/
}

void MyPerson::setCords(sf::Vector2f cords) {
	this->cords = cords;
	logg();
	leg_shape.setPosition(this->cords);
	shape.setPosition(this->cords - sf::Vector2f(0,3 * PIXEL_SIZE.y));
}

void MyPerson::setColor(sf::Color color) {
	this->color = color;
	shape.setFillColor(color);
}

void MyPerson::LoadGame(std::ifstream &path) {
	sf::Vector2f cord;
	path >> cord.x;
	path >> cord.y;
	setCords(cord);
	path >> hp;
}

void MyPerson::SaveGame(std::ofstream &path) {
	path << cords.x << ' ' << cords.y << ' ' << hp << '\n';
}

void MyPerson::draw(sf::RenderWindow& window) {
	window.draw(shape);
}