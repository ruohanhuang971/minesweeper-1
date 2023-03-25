#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

int main() {
	srand(time(0));

	sf::RenderWindow app(sf::VideoMode(400, 400), "Start the Minesweeper");

	int w = 32;
	int grid[12][12];
	int showGrid[12][12]; //For showing the grid

	sf::Texture t;
	t.loadFromFile("C:\\Users\\theho\\source\\repos\\minesweeper-1\\x64\\Debug\\tiles.jpg");

	sf::Sprite s(t);

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			showGrid[i][j] = 10;

			if (rand() % 5 == 0) {
				grid[i][j] = 9;
			} else {
				grid[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			int n = 0;
			if (grid[i][j] == 9) {
				continue;
			}
			if (grid[i + 1][j - 1] == 9) n++;
			if (grid[i + 1][j] == 9) n++;
			if (grid[i + 1][j + 1] == 9) n++;
			if (grid[i][j - 1] == 9) n++;
			if (grid[i][j + 1] == 9) n++;
			if (grid[i - 1][j - 1] == 9) n++;
			if (grid[i - 1][j] == 9) n++;
			if (grid[i - 1][j + 1] == 9) n++;
			grid[i][j] = n;
		}
	}

			while (app.isOpen()) {
				sf::Vector2i pos = sf::Mouse::getPosition(app);
				int x = pos.x / w;
				int y = pos.y / w;

				sf::Event event;
				while (app.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						app.close();
					}

					if (event.type == sf::Event::MouseButtonPressed) {
						if (showGrid[x][y] != 11) {
							if (event.key.code == sf::Mouse::Left) {
							showGrid[x][y] = grid[x][y];
						}
							if (showGrid[x][y] == 10 && event.key.code == sf::Mouse::Right) {
								showGrid[x][y] = 11;
							}
						} else {
							if (event.key.code == sf::Mouse::Right) {
								showGrid[x][y] = 10;
							}
						}
					}
				}

				app.clear(sf::Color::White);
				for (int i = 1; i <= 10; i++) {
					for (int j = 1; j <= 10; j++) {

						if (showGrid[x][y] == 9) {
							showGrid[i][j] = grid[i][j];
						}
						
						s.setTextureRect(sf::IntRect(showGrid[i][j] * w, 0, w, w));
						s.setPosition(i * w, j * w);
						app.draw(s);
					}
				}

				app.display();
			}
		}
