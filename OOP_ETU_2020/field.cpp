#include "field.h"


field::field() {
	field_vec = sf::Vector2f(200, 200);
	arr = new IGameCell**[field_vec.y];
	for (size_t j = 0; j < field_vec.y; j++) {
		arr[j] = new IGameCell*[field_vec.x];
		for (size_t i = 0; i < field_vec.x; i++) {
			if (j == 0 || j == field_vec.y - 1 || i == 0 || i == field_vec.x - 1) {
				arr[j][i] = new CellWall;
				arr[j][i]->setCords(sf::Vector2f(j*PIXEL_SIZE.y, i*PIXEL_SIZE.x));
			}
			else if ((i == 1 && j == 1) || (i == 2 && j == 1)|| (i == 1 && j == 2)|| (i == 2 && j == 2)) {
				arr[j][i] = new CellIn;
				arr[j][i]->setCords(sf::Vector2f(j*PIXEL_SIZE.y, i*PIXEL_SIZE.x));
			}
			else if ((i == field_vec.x - 3 && j == field_vec.y - 3) || (i == field_vec.x - 3 && j == field_vec.y - 2) || (i == field_vec.x - 2 && j == field_vec.y - 3) || (i == field_vec.x - 2 && j == field_vec.y - 2)) {
				arr[j][i] = new CellOut;
				arr[j][i]->setCords(sf::Vector2f(j*PIXEL_SIZE.y, i*PIXEL_SIZE.x));
			}
			else {
				arr[j][i] = new CellLand;
				arr[j][i]->setCords(sf::Vector2f(j*PIXEL_SIZE.y, i*PIXEL_SIZE.x));
			}
		}
	}
}

field::field(sf::Vector2f vec) {

}

void field::SaveField(std::ofstream &save) {
	save << field_vec.y << field_vec.x;
	for (int i = 0; i < field_vec.y; i++) {
		for (int j = 0; j < field_vec.x; j++) {
			save << arr[i][j].;
		}
	}
}

char field::getMarker(sf::Vector2f vec) {
	int x = vec.x / PIXEL_SIZE.x;
	int y = vec.y / PIXEL_SIZE.y;
	return arr[y][x]->getMarker();
}



sf::Vector2f field::getSize() {
	return field_vec;
}


void field::draw(sf::RenderWindow& window) {
	for (size_t j = 0; j < field_vec.y; j++) {
		for (size_t i = 0; i < field_vec.x; i++) {
			arr[j][i]->draw(window);
		}
	}
}

field::~field() {

}