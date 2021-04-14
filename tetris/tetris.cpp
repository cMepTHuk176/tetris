#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include "button.h"
#include <ctime>
using namespace sf;
using namespace std;
int score;
int lose = 0;
bool end1 = false;
int button_event = 0;
int gameField[5][5];
int R= 255,G = 210,B = 0;

void draw_window1();
void draw_window2();
void random_new();
int scores();
void newStep(int num);
void random(int x[5][5]);

// счет игры
int scores() { 
	score = 0;
		for (int s = 0; s < 5; s++) {
			for (int x = 0; x < 5; x++) {
				if (gameField[s][x] < 2049)
				score += gameField[s][x];
			}
		}
	return score;
}
// рандомит игровое поле !!! ВНИМАНИЕ !!! тут костыль при просмотре закрыть глоза ладошками
void random(int x[5][5]) {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x[i][j] = rand() % 100;
			if (x[i][j] <= 70)
				x[i][j] = 0;
			else
				x[i][j] = 2;

		}
	}
	if (button_event == 4) {
		for (int i = 0; i < 5; i++) {
			gameField[4][i] = 9990+i;
			gameField[i][4] = 9990+i;
		}
	}

}
// самый страшный кусок говнокода
void newStep(int num)
{
	int buf[5][5]{};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			buf[i][j] = gameField[i][j];

	/* ----------Это все складывает кубики если между ними расстояние---------------*/
	if (num == 1) {
		for (int s = 0; s <button_event; s++) {
			for (int i = 0; i <button_event; i++) {
				for (int x = 1; x <button_event; x++) {
					if (gameField[x - 1][i] == 0) {
						gameField[x - 1][i] = gameField[x - 1][i] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}
			}
		}
	}
	else if (num == 2) {
		for (int s = 0; s <= 5; s++) {
			for (int i = 0; i <button_event; i++) {
				for (int x = 3; x >= 0; x--) {
					if (gameField[x + 1][i] == 0) {
						gameField[x + 1][i] = gameField[x + 1][i] + gameField[x][i];
						gameField[x][i] = 0;

					}
				}
			}
		}
	}
	else if (num == 3) {
		for (int s = 0; s <button_event; s++) {
			for (int x = 0; x <button_event; x++) {
				for (int i = 1; i <button_event; i++) {
					if (gameField[x][i - 1] == 0) {
						gameField[x][i - 1] = gameField[x][i - 1] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}


			}
		}
	}
	else if (num == 4) {
		for (int s = 0; s <button_event; s++) {
			for (int x = 0; x <button_event; x++) {
				for (int i = 3; i >= 0; i--) {
					if (gameField[x][i + 1] == 0) {
						gameField[x][i + 1] = gameField[x][i + 1] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}
			}
		}
	}
	/* -----------Сложение кубика если они рядом--------------*/
	if (num == 1) {

		for (int i = 0; i <button_event; i++) {
			for (int x = 1; x <button_event; x++) {
				if (gameField[x][i] == gameField[x - 1][i]) {
					gameField[x - 1][i] = gameField[x - 1][i] + gameField[x][i];
					gameField[x][i] = 0;
				}
			}
		}

	}
	else if (num == 2) {

		for (int i = 0; i <button_event; i++) {
			for (int x = 3; x >= 0; x--) {
				if (gameField[x][i] == gameField[x + 1][i]) {
					gameField[x + 1][i] = gameField[x + 1][i] + gameField[x][i];
					gameField[x][i] = 0;
				}
			}
		}

	}
	else if (num == 3) {

		for (int x = 0; x <button_event; x++) {
			for (int i = 1; i <button_event; i++) {
				if (gameField[x][i] == gameField[x][i - 1]) {
					gameField[x][i - 1] = gameField[x][i - 1] + gameField[x][i];
					gameField[x][i] = 0;
				}
			}
		}

	}
	else if (num == 4) {

		for (int x = 0; x <button_event; x++) {
			for (int i = 3; i >= 0; i--) {
				if (gameField[x][i] == gameField[x][i + 1]) {
					gameField[x][i + 1] = gameField[x][i + 1] + gameField[x][i];
					gameField[x][i] = 0;
				}
			}
		}

	}
	/* ------------не дает складывать если ничаго нидвигаетсо-------------*/
	if (num == 1) {
		for (int s = 0; s <button_event; s++) {
			for (int i = 0; i <button_event; i++) {
				for (int x = 1; x <button_event; x++) {
					if (gameField[x - 1][i] == 0) {
						gameField[x - 1][i] = gameField[x - 1][i] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}
			}
		}
	}
	else if (num == 2) {
		for (int s = 0; s <button_event; s++) {
			for (int i = 0; i <button_event; i++) {
				for (int x = 3; x >= 0; x--) {
					if (gameField[x + 1][i] == 0) {
						gameField[x + 1][i] = gameField[x + 1][i] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}
			}
		}
	}
	else if (num == 3) {
		for (int s = 0; s <button_event; s++) {
			for (int x = 0; x <button_event; x++) {
				for (int i = 1; i <button_event; i++) {
					if (gameField[x][i - 1] == 0) {
						gameField[x][i - 1] = gameField[x][i - 1] + gameField[x][i];
						gameField[x][i] = 0;
					}
				}
			}
		}
	}
	else if (num == 4) {
		for (int s = 0; s <button_event; s++) {
			for (int x = 0; x <button_event; x++) {
				for (int i = 3; i >= 0; i--) {
					if (gameField[x][i + 1] == 0) {
						gameField[x][i + 1] = gameField[x][i + 1] + gameField[x][i];
						gameField[x][i] = 0;

					}
				}


			}
		}
	}
	/* ------------скорее всего комментарии не в том порядке (ну а хули нам)-------------*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			cout << " " << gameField[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	bool kost = false;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (buf[i][j] != gameField[i][j])
				kost = true;
	if (kost == true) {
		random_new();
		R = rand() % 256 + 50;
		G = rand() % 256 + 50;
		B = rand() % 256 + 50;
	}
	lose = 0;
	for (int i = 0; i < button_event; i++) {
		for (int x = 1; x < button_event; x++) {
			if (gameField[x][i] != gameField[x - 1][i] &&
				gameField[x - 1][i] != 0 &&
				gameField[x][i] != gameField[x + 1][i] &&
				gameField[x - 1][i] != 0 &&
				gameField[x][i] != gameField[x][i - 1] &&
				gameField[x - 1][i] != 0 &&
				gameField[x][i] != gameField[x][i + 1] &&
				gameField[x - 1][i] != 0 &&
				gameField[x][i] != 0)
				lose++;
		}
	}
}
// рандомно спавнит новый кубик (вроде всегда спавнит)
void random_new() {
	int a = rand() % 100 / 20;
	int b = rand() % 100 / 20;
	if (gameField[a][b] == 0)
		gameField[a][b] = 2;
	else
		random_new();
}

// окно игры
void draw_window2() {
	random(gameField);
	Clock clock;
	int q = 0;
	int w = 100, h = 100;
	if (button_event == 5) {
		w = 536; h = 640;
	}
	else if (button_event == 4)
	{
		w = 428; h = 600;
	}

	RenderWindow window(sf::VideoMode(w, h), "2048");
	Image heroimage;
	heroimage.loadFromFile("2048.png");
	Texture herotexture;
	herotexture.loadFromImage(heroimage);
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(20, 11, 104, 104));

	Font font;
	font.loadFromFile("times.ttf");
	Text text(" ", font, 30);
	text.setStyle(Text::Bold | Text::Underlined);
	Font font1;
	font1.loadFromFile("times.ttf");
	Text text1(" ", font, 30);
	text1.setStyle(Text::Bold | Text::Underlined);
	text1.setFillColor(Color(0, 0, 0));

	Button testButton;
	if (button_event == 5)
		testButton.newButton(100, 50, 350, 585);
	else
		testButton.newButton(100, 50, 310, 535);
	testButton.setLabel("exit", "times.ttf",Color(240,240,240), 20);

	Button testButton1;
	testButton1.newButton(300, 300, 100, 100);
	testButton1.setLabel("New Game", "times.ttf", Color(240, 240, 240), 20);

	while (window.isOpen()) {
		if (lose == 12 && button_event == 4)
			end1 = true;
		else if (lose == 20 && button_event == 5)
			end1 = true;

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) { 

				if (event.key.code == sf::Keyboard::Left)   newStep(3);
				if (event.key.code == sf::Keyboard::Right)  newStep(4);
				if (event.key.code == sf::Keyboard::Up)     newStep(1);
				if (event.key.code == sf::Keyboard::Down)   newStep(2);
			}
		}
		q = 0;
		window.setKeyRepeatEnabled(false);


		if ((testButton.isCursor(pos.x, pos.y,240,79,79)) && /*(sf::Mouse::isButtonPressed(sf::Mouse::Left))*/ (event.type == sf::Event::MouseButtonReleased)) {
			window.close();
			end1 = false;
			lose = 0;
			draw_window1();
		}
		if (button_event == 0)
			window.close();
		window.clear(Color(R, G, B));
		for (int i = 0; i < button_event; i++) {
			for (int w = 0; w < button_event; w++) {
				if (gameField[w][i] == 0) { herosprite.setTextureRect(IntRect(643, 140, 104, 104)); }
				if (gameField[w][i] == 2) { herosprite.setTextureRect(IntRect(20, 11, 104, 104)); }
				if (gameField[w][i] == 4) { herosprite.setTextureRect(IntRect(139, 12, 104, 104)); }
				if (gameField[w][i] == 8) { herosprite.setTextureRect(IntRect(262, 12, 104, 104)); }
				if (gameField[w][i] == 16) { herosprite.setTextureRect(IntRect(386, 12, 104, 104)); }
				if (gameField[w][i] == 32) { herosprite.setTextureRect(IntRect(518, 13, 104, 104)); }
				if (gameField[w][i] == 64) { herosprite.setTextureRect(IntRect(644, 15, 104, 104)); }
				if (gameField[w][i] == 128) { herosprite.setTextureRect(IntRect(19, 138, 104, 104)); }
				if (gameField[w][i] == 256) { herosprite.setTextureRect(IntRect(144, 136, 104, 104)); }
				if (gameField[w][i] == 512) { herosprite.setTextureRect(IntRect(266, 137, 104, 104)); }
				if (gameField[w][i] == 1024) { herosprite.setTextureRect(IntRect(392, 136, 104, 104)); }
				if (gameField[w][i] == 2048) { herosprite.setTextureRect(IntRect(521, 138, 104, 104)); }

				herosprite.setPosition(i * 108, w * 108);
				if (button_event == 5) {
					text.setPosition(150, 540);
					text1.setPosition(150, 542);
				}
				else {
					text.setPosition(130, 450);
					text1.setPosition(131, 452);
				}
				window.draw(herosprite);
				if (gameField[w][i] == 2048)
					end1 = true;
			}

		}
		if (end1) {
			window.draw(testButton1.button);
			window.draw(testButton1.shadow);
			if ((testButton1.isCursor(pos.x, pos.y, 240, 79, 79)) && (event.type == sf::Event::MouseButtonReleased)) {
				window.close();
				end1 = false;
				lose = 0;
				draw_window2();
			}
		}
		ostringstream strskr;
		strskr << scores();
		text.setString("Score:" + strskr.str());
		text1.setString("Score:" + strskr.str());
		window.draw(testButton.button);
		window.draw(testButton.shadow);
		window.draw(testButton.text);
		window.draw(text1);
		window.draw(text);
		window.display();



	}

}
// окно менюшки
void draw_window1() {
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(250, 500), "2048");

	Button testButton;
	testButton.newButton(150, 50, 40, 80);
	testButton.setLabel("exit", "times.ttf",Color(240, 240, 240), 20);
	Button testButton1;
	testButton1.newButton(150, 50, 40, 140);
	testButton1.setLabel("легко", "times.ttf",Color(240, 240, 240),20);
	Button testButton2;
	testButton2.newButton(150, 50, 40, 200);
	testButton2.setLabel("сложно", "times.ttf",Color(240,240,240), 20);

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				button_event = 0;
			}

		}
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

		if ((testButton.isCursor(pos.x, pos.y, 240, 79, 79)) && (event.type == sf::Event::MouseButtonReleased))
		{
			button_event = 0;
			end1 = false;
			lose = 0;
			window.close();
		}
		if ((testButton1.isCursor(pos.x, pos.y, 240, 79, 79)) && (event.type == sf::Event::MouseButtonReleased)) {
			button_event = 5;
			end1 = false;
			lose = 0;
			window.close();
			draw_window2();
		}
		if ((testButton2.isCursor(pos.x, pos.y, 240, 79, 79)) && (event.type == sf::Event::MouseButtonReleased)) {
			button_event = 4;
			end1 = false;
			lose = 0;
			window.close();
			draw_window2();
		}
		window.clear(Color(255, 210, 0));
		window.draw(testButton.button);
		window.draw(testButton.shadow);
		window.draw(testButton.text);
		window.draw(testButton1.button);
		window.draw(testButton1.shadow);
		window.draw(testButton1.text);
		window.draw(testButton2.button);
		window.draw(testButton2.shadow);
		window.draw(testButton2.text);

		window.display();

	}
}

int main()
{
	draw_window1();
	return 0;
}