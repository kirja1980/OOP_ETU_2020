#include "Game.h"
#include <iostream>
#include <string>
#define DELTA_SPEED (1)
#define MULTY_SPEED (3)

Game::Game() {

	window.create(sf::VideoMode(1000, 1000), "SRU.L.K.E.R. CALL FROM THE TOILET");
	hp.setFillColor(sf::Color(60, 150, 22, 255));
	hp.setPosition(10, 900);
	hp.setSize(sf::Vector2f(100,20));
	
	sf::Text text;
	time = 0;
}

void Game::DrawInterface() {
	hp.setSize(sf::Vector2f(pers.getHP(), 20));
	hp.setFillColor(sf::Color(60, pers.getHP(), 22, 255));
}

void Game::PlayerControl() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !save.is_open()) {
		std::string p = "save.txt"/*currentDateTime()*/;
		std::cout << "Название сохранения: " << p << "\n";
		SaveGame(p);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0))) {
			pers.move(sf::Vector2f(-DELTA_SPEED * MULTY_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0))) {
			pers.move(sf::Vector2f(DELTA_SPEED * MULTY_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED))) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED * MULTY_SPEED));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED))) {
			pers.move(sf::Vector2f(0, DELTA_SPEED * MULTY_SPEED));
		}
	}
	else {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) && isMove(pers.getCords(), sf::Vector2f(-DELTA_SPEED, 0))) {
			pers.move(sf::Vector2f(-DELTA_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) && isMove(pers.getCords(), sf::Vector2f(DELTA_SPEED, 0))) {
			pers.move(sf::Vector2f(DELTA_SPEED, 0));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) && isMove(pers.getCords(), sf::Vector2f(0, -DELTA_SPEED))) {
			pers.move(sf::Vector2f(0, -DELTA_SPEED));
		}
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) && isMove(pers.getCords(), sf::Vector2f(0, DELTA_SPEED))) {
			pers.move(sf::Vector2f(0, DELTA_SPEED));
		}
	}
}

void Game::GameLogic() {
	if (!pers.isLive()) {
		window.close();
		return;
	}
	if (!tank.isLive()) {
		if (rand() % 2 == 1 && tank.getCords().x < f.field_vec.x && tank.getCords().y < f.field_vec.x) {
			tank.hp = 150;
			tank.shape.setFillColor(sf::Color::Yellow);
			tank.setCords(sf::Vector2f(((rand() % (int)f.field_vec.x - 1) + 1) * PIXEL_SIZE.x, ((rand() % (int)f.field_vec.y-1) + 1) * PIXEL_SIZE.x));
		}
		else {
			tank.setCords(sf::Vector2f(900, 0));
			tank.shape.setFillColor(sf::Color::Black);
			tank.attack.setFillColor(sf::Color::Black);
		}
		
	}
	else {
		if (pers.leg_shape.getGlobalBounds().intersects(tank.attack.getGlobalBounds())) {
			pers.loss(-2);
		}
		if (tank.leg_shape.getGlobalBounds().intersects(pers.leg_shape.getGlobalBounds()))
			tank.loss(-3);

		if (tank.attack.getRotation() != 0) {
			tank.shoot();
		}
		else {
			if (tank.type_attack == 1 && time != 15) {
				time++;
			}
			else {
				time = 0;
				unsigned random = rand() % 100;
				tank.type_attack = tank.shootform(random);
				tank.shoot();
			}
		}
	}
	
	DrawInterface();
	DrawGame();
	PlayerControl();
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

		GameLogic();

		window.display();

	}
}

void Game::DrawGame() {
	window.clear();
	f.draw(window);
	
	tank.draw(window);
	window.draw(hp);
	pers.draw(window);
}

void Game::LoadGame(std::string path){
	std::ifstream in(path);
	if (in.is_open()) {
		pers.LoadGame(in);
		tank.LoadGame(in);
	}
	else {
		std::cout << "Ошибка открытия файла!";
	}
}

void Game::SaveGame(std::string path) {
	
	path = "save.txt";
	save.open(path);
	if (save.is_open()) {
		pers.SaveGame(save);
		tank.SaveGame(save);
	}
	else {
		std::cout << "Ошибка открытия файла!";
	}
	

	
}


void Game::GameOver() {
	window.close();
}

Game::~Game() {
	window.close();
	save.close();
}

bool Game::isMove(sf::Vector2f vec, sf::Vector2f delta) {
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
			if (!tank.isLive())
				window.close();
			else
				b = false;
			break;
		default:
			b = true;
			break;
		}
	}
	return b;
}