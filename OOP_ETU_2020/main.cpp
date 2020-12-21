#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "field.h"
#include "players.h"
#include "Game.h"

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[40];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d:%X", &tstruct);
	std::string path = buf;
	path.append(".txt");
	return path;
}

int main()

{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int k = 0;
	std::cout << "SRU.L.K.E.R. Call of toilet\n"
				"1 - Новая игра\n"
				"2 - Загрузить игру\n";
	std::cin >> k;
	Game game;
	std::string path;
	
	switch (k)
	{
	case 1:
		game.RenderGame();
		break;
	case 2:
		std::cout << "Введите путь до сохранения: ";
		std::cin >> path;
		game.LoadGame(path);
		game.RenderGame();
	default:
		break;
	}
	system("pause");
	return 0;

}