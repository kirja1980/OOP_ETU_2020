#pragma once
#include "players.h"
#include "field.h"

void PlayerControl(MyPerson &pers, field f, sf::RenderWindow& window);
bool isMove(sf::Vector2f vec, sf::Vector2f del, field& f, sf::RenderWindow& window);