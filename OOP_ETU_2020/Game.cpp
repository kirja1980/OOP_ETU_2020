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
}

void Game::DrawInterface() {
	font.loadFromFile("times-new-roman.ttf");//передаем нашему шрифту файл шрифта
	
	text.setPosition(sf::Vector2f(100, 100));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
	text.setString("Собрано камней:");//задает строку тексту
	window.draw(text);//рисую этот текст
	hp.setSize(sf::Vector2f(pers.getHP(), 20));
	hp.setFillColor(sf::Color(60, pers.getHP(), 22, 255));
}

void Game::PlayerControl() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { std::string p = currentDateTime(); SaveGame(p); std::cout << "Название сохранения: " << p << "\n"; }
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

void Game::GameLogic() {
	if (!pers.isLive()) {
		window.close();
		return;
	}
	if(pers.leg_shape.getGlobalBounds().intersects(tank.leg_shape.getGlobalBounds()))
		pers.loss(-1);
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

}

void Game::SaveGame(std::string path) {
	std::ofstream save(path);
	f.SaveField(save);

	save.close();
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