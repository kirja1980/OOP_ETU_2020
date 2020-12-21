#pragma once
#include "players.h"
#include "field.h"

class Game {
public:
	Game();
	void DrawInterface();
	void GameLogic();
	void PlayerControl();
	void RenderGame();
	void DrawGame();
	void LoadGame(std::string path);
	void SaveGame(std::string path);

	~Game();
private:
	sf::RenderWindow window;
	sf::RectangleShape hp;
	MyPerson pers;
	field f;
	Tank tank;
	sf::Text text;
	sf::Font font;//רנטפע 
};

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	std::string path = buf;
	path.append(".txt");
	return path;
}

bool isMove(sf::Vector2f vec, sf::Vector2f delta, field& f, sf::RenderWindow& window);