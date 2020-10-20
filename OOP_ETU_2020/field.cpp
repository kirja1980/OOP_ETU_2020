#include "field.h"


field::field() {
	field_vec = sf::Vector2f(100, 100);
	arr = new IGameCell**[field_vec.y];
	for (size_t j = 0; j < field_vec.y; j++) {
		arr[j] = new IGameCell*[field_vec.x];
		for (size_t i = 0; i < field_vec.x; i++) {
			arr[j][i] = new CellLand;
			arr[j][i]->setCords(sf::Vector2f(j*PIXEL_SIZE.y, i*PIXEL_SIZE.x));
		}
	}
}

field::field(sf::Vector2f vec) {

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