#include "Game.h"
#define DELTA_SPEED (1)
#define MULTY_SPEED (3)

Game::Game() {

	window.create(sf::VideoMode(1000, 1000), "SRU.L.K.E.R. CALL FROM THE TOILET");

	sf::Text text;
}

void Game::PlayerControl() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0), f, window)) {
			pers.move(sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0), f, window)) {
			pers.move(sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED), f, window)) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED), f, window)) {
			pers.move(sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED));
		}
	}
	else {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED, 0), f, window)) {
			pers.move(sf::Vector2f(-DELTA_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED, 0), f, window)) {
			pers.move(sf::Vector2f(DELTA_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED), f, window)) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED), f, window)) {
			pers.move(sf::Vector2f(0, DELTA_SPEED));
		}
	}
}

void Game::RenderGame() {
	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)

				window.close();

		}

		DrawGame();
		PlayerControl();

		window.display();

	}
}

void Game::DrawGame() {
	window.clear();
	f.draw(window);
	pers.draw(window);
}

Game::~Game() {

}

bool isMove(sf::Vector2f vec, sf::Vector2f delta, field& f, sf::RenderWindow& window) {
	bool b = false;
	char c = ' ';
	if ((vec.x + delta.x) >= 0 && (vec.y + delta.y) >= 0 && (vec.x + delta.x) + MY_LEG_SIZE.x <= (f.getSize().x) * 4 && (vec.y + delta.y) + MY_LEG_SIZE.y * 1 <= (f.getSize().y) * 4) {
		if (delta.x > 0 || delta.y > 0)
			c = f.getMarker(vec + delta + MY_LEG_SIZE - sf::Vector2f(1, 1));
		else
			c = f.getMarker(vec + delta);
		switch (c)
		{
		case '#':
			b = false;
			break;
		case '<':
			window.close();
			break;
		default:
			b = true;
			break;
		}
	}
	return b;
}