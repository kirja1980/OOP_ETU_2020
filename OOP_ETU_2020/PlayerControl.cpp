#include "PlayerControl.h"
#define DELTA_SPEED (1)
#define MULTY_SPEED (3)

void PlayerControl(MyPerson &pers, field f) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0), f)) {
			pers.move(sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0), f)) {
			pers.move(sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED), f)) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED), f)) {
			pers.move(sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED)); 
		}
	}
	else {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED, 0), f)) {
			pers.move(sf::Vector2f(-DELTA_SPEED, 0)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED, 0), f)) {
			pers.move(sf::Vector2f(DELTA_SPEED, 0)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED), f)) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED)); 
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED), f)) {
			pers.move(sf::Vector2f(0, DELTA_SPEED)); 
		}
	}
}

bool isMove(sf::Vector2f vec, sf::Vector2f del, field& f) {
	bool b = false;
	char c = ' ';
	if ((vec.x + del.x) >= 0 && (vec.y + del.y) >= 0 && (vec.x + del.x) + MY_PLAYER_SIZE.x < (f.getSize().x) * 4 && (vec.y + del.y) + MY_PLAYER_SIZE.y < (f.getSize().y) * 4 ) {
		c = f.getMarker(vec + del);
		switch (c)
		{
		case '#':
			b = true;
			break;
		default:
			b = true;
			break;
		}
	}
	return b;
}