#include <SFML/Graphics.hpp>
#include <time.h>

int main() {
	srand(time(0));

	sf::RenderWindow app(sf::VideoMode(400, 400), "Start the Minesweeper");

	int w = 32;
	int grid[12][12];
	int showGrid[12][12]; //For showing the grid

	sf::Texture t;
	t.loadFromFile("images/tiles.jpg");


}
