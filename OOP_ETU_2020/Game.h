#pragma once
#include "players.h"
#include "field.h"

class Game {
public:
	Game();
	void PlayerControl();
	void RenderGame();
	void DrawGame();

	~Game();
private:
	sf::RenderWindow window;
	MyPerson pers;
	field f;
};

bool isMove(sf::Vector2f vec, sf::Vector2f delta, field& f, sf::RenderWindow& window);