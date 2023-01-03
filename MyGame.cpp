#include "MyGame.h"
#include <random>
#include <time.h>
#include <cmath>
#include <vector>


MyGame::MyGame(int dif) {
	speed = 10;
	mode = dif;
	cnt_all = 0;
	cnt_ok = 0;
	if (dif == 0) {
		speed_boost = 1;
		max_speed = 20;
		delta = 220;
	}
	else if (dif == 1) {
		speed_boost = 2;
		max_speed = 30;
		delta = 200;
	}
	else {
		speed_boost = 3;
		max_speed = 40;
		delta = 180;
	}
	for (int i = 0; i < COL; ++i) my_obj[i].clear();
	for (int i = 0; i < COL; ++i) {
		buttons[i] = CircleShape(70);
		buttons[i].setOutlineThickness(5);
		buttons[i].setOutlineColor(Color::White);
		buttons[i].setFillColor(Color::Black);
	}
	buttons[0].setPosition(Vector2f(960 - 2 - 222 - 4 - 70 - 111, 900));
	buttons[1].setPosition(Vector2f(960 - 2 - 70 - 111, 900));
	buttons[2].setPosition(Vector2f(960 + (-1) * (-2 - 222 - 4 - 111 + 70), 900));
	buttons[3].setPosition(Vector2f(960 + (-1) * (-2 - 111 + 70), 900));
}

void MyGame::MoveDown() {
	for (int i = 0; i < COL; ++i) {
		for (int j = 0; j < my_obj[i].size(); ++j) {
			my_obj[i][j].move(0, speed);
		}
	}
}

void MyGame::Clear() {
	for (int i = 0; i < COL; ++i) {
		vector <int> ind;
		for (int j = 0; j < my_obj[i].size(); ++j) {
			if (my_obj[i][j].getPosition().y > 1150) ind.push_back(j);
		}
		while (!ind.empty()) {
			int v = ind.back();
			my_obj[i].erase(my_obj[i].begin() + v);
			ind.pop_back();
			++cnt_all;
		}
	}
}

void MyGame::Add() {
	int num_of_obj = (abs(rand()) % (mode + 2));
	int used[COL] = { 0, 0, 0, 0 };
	int nowe = 0;
	while (nowe != num_of_obj) {
		int ind = abs(rand()) % COL;
		if (used[ind] == 0) {
			++nowe;
			used[ind] = 1;
		}
	}
	for (int i = 0; i < COL; ++i) {
		if (used[i]) {
			CircleShape my_c(70);
			my_c.setFillColor(Color::White);
			if (i == 0) {
				my_c.setPosition(Vector2f(960 - 2 - 222 - 4 - 70 - 111, -100));
			}
			else if (i == 1) {
				my_c.setPosition(Vector2f(960 - 2 - 70 - 111, -100));
			}
			else if (i == 3) {
				my_c.setPosition(Vector2f(960 + (-1) * (-2 - 222 - 4 - 111 + 70), -100));
			}
			else {
				my_c.setPosition(Vector2f(960 + (-1) * (- 2 - 111 + 70), -100));
			}
			my_obj[i].push_back(my_c);
		}
	}
}

void MyGame::draw(RenderWindow& window) {
	int dii = 450;
	RectangleShape rec;
	rec.setOutlineColor(Color::White);
	rec.setFillColor(Color::Black);
	rec.setPosition(960 - dii, 0);
	rec.setSize(Vector2f(2 * dii, 1080));
	rec.setOutlineThickness(5);
	vector <RectangleShape> da(3);
	for (int i = 0; i < 3; ++i) {
		da[i].setFillColor(Color::White);
		da[i].setSize(Vector2f(4, 1080));
	}
	da[0].setPosition(960 - 222 - 4, 0);
	da[1].setPosition(960 - 2, 0);
	da[2].setPosition(960 + 2 + 222, 0);
	Font font;
	font.loadFromFile("fonts/main.ttf");
	Text sc;
	sc.setFont(font);
	sc.setString("Score: " + to_string(cnt_ok));
	sc.setFillColor(Color::White);
	sc.setOutlineThickness(2);
	sc.setOutlineColor(Color::Black);
	sc.setCharacterSize(70);
	sc.setPosition(Vector2f(1450, 100));
	window.draw(sc);
	Text sc1;
	sc1.setFont(font);
	sc1.setString("Missed: " + to_string(cnt_all - cnt_ok));
	sc1.setFillColor(Color::White);
	sc1.setOutlineThickness(2);
	sc1.setOutlineColor(Color::Black);
	sc1.setCharacterSize(70);
	sc1.setPosition(Vector2f(1450, 200));
	window.draw(sc1);
	window.draw(rec);
	for (int i = 0; i < 3; ++i) window.draw(da[i]);
	for (int i = 0; i < COL; ++i) window.draw(buttons[i]);
	for (int i = 0; i < COL; ++i) {
		for (int j = 0; j < my_obj[i].size(); ++j) {
			window.draw(my_obj[i][j]);
		}
	}
}

void MyGame::change_speed() {
	speed += speed_boost;
	if (speed > max_speed) speed = max_speed;
}

void MyGame::Pressed(int v) {
	bool fl = 0;
	for (int i = 0; i < my_obj[v].size(); ++i) {
		// abs(my_obj[v][i].getPosition().x - buttons[i].getPosition().x) + 
		if (abs(my_obj[v][i].getPosition().y - buttons[i].getPosition().y) <= delta) {
			fl = 1;
			my_obj[v].erase(my_obj[v].begin() + i);
			break;
		}
	}
	if (fl) {
		++cnt_all;
		++cnt_ok;
	}
	else ++cnt_all;
}