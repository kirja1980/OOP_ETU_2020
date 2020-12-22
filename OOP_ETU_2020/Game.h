#pragma once


#include "players.h"
#include "field.h"

class Game {
public:
	Game();
	void DrawInterface();
	void GameLogic();
	bool isMove(sf::Vector2f vec, sf::Vector2f delta);
	void PlayerControl();
	void RenderGame();
	void DrawGame();
	void LoadGame(std::string path);
	void SaveGame(std::string path);

	void GameOver();
	~Game();
private:
	sf::RenderWindow window;
	sf::RectangleShape hp;
	MyPerson pers;
	field f;
	Tank tank;
	sf::Text text;
	sf::Font font;//רנטפע 
	std::ofstream save;
	unsigned time;
};
const std::string currentDateTime();


bool isMove(sf::Vector2f vec, sf::Vector2f delta, field& f, sf::RenderWindow& window);