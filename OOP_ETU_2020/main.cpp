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
	std::cout << "\tSRU.L.K.E.R. Call of toilet\n"
		"\t\t*����������*\n"
		"������ ���� �� ����� ������ ����-�� ������.\n"
		"��� ������� �������� ������������, ���������� ��������.\n"
		"���� ����� �������� ���������. ������������������� � �������. ���� ���������������, �� ������� ����� �� ����.\n"
		"���� ����� �������� ������� �������. ������������������� � �������. ���� ���������������, �� ������� ������ �� ���� �� 8 ����� �� ����.\n"
		"���� ����� �������� �������, ��� ��� ��������, ��� ��� ����. ������������������� � ��������������.\n";
	std::cout <<
		"\t1 - ����� ����\n"
		"\t2 - ��������� ����\n"
		"\t3 - ����� �� ����\n";
	std::cin >> k;
	if (k == 1 || k == 2) {
		Game game;
		std::string path;

		switch (k)
		{
		case 1:
			game.RenderGame();
			break;
		case 2:
			std::cout << "������� ���� �� ����������: ";
			std::cin >> path;
			game.LoadGame(path);
			game.RenderGame();
		case 3:
		default:
			game.GameOver();
			break;
		}
	}
	
	std::cout << "�����!\n";
	system("pause");
	return 0;

}