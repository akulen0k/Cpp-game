#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MainMenu::MainMenu(float width, float height) {
	mode = 0;
	int delta_y = 90;
	font.loadFromFile("fonts/main.ttf");
	Button_now = 0;
	cur_setting = 0;
	FloatRect textRect;
	ifstream file("data/statistics.txt");
	int st[MAX_STAT];
	for (int i = 0; i < MAX_STAT; ++i) st[i] = 0;
	if (file.is_open()) {
		for (int i = 0; i < MAX_STAT; ++i) file >> st[i];
		for (int i = 0; i < MAX_SETTINGS; ++i) file >> settings[i];
		max_settings[0] = 3;
		show_settings[0].setFont(font);
		show_settings[0].setString("Difficulty: " + dif[settings[0]]);
		show_settings[0].setFillColor(Color(125, 125, 125));
		show_settings[0].setOutlineThickness(2);
		show_settings[0].setOutlineColor(Color::Black);
		show_settings[0].setCharacterSize(70);
		textRect = show_settings[0].getLocalBounds();
		show_settings[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		show_settings[0].setPosition(Vector2f(960, 540));
	}
	stat[0].setFont(font);
	stat[0].setString("Games played: " + to_string(st[0]));
	stat[0].setFillColor(Color(175, 175, 175));
	stat[0].setOutlineThickness(2);
	stat[0].setOutlineColor(Color::Black);
	stat[0].setCharacterSize(70);
	textRect = stat[0].getLocalBounds();
	stat[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	stat[0].setPosition(Vector2f(960, 540 - delta_y - (delta_y / 2)));
	stat[1].setFont(font);
	stat[1].setString("Total points(easy): " + to_string(st[1]));
	stat[1].setFillColor(Color(175, 175, 175));
	stat[1].setOutlineThickness(2);
	stat[1].setOutlineColor(Color::Black);
	stat[1].setCharacterSize(70);
	textRect = stat[1].getLocalBounds();
	stat[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	stat[1].setPosition(Vector2f(960, 540 - (delta_y / 2)));
	stat[2].setFont(font);
	stat[2].setString("Total points(medium): " + to_string(st[2]));
	stat[2].setFillColor(Color(175, 175, 175));
	stat[2].setOutlineThickness(2);
	stat[2].setOutlineColor(Color::Black);
	stat[2].setCharacterSize(70);
	textRect = stat[2].getLocalBounds();
	stat[2].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	stat[2].setPosition(Vector2f(960, 540 + (delta_y / 2)));
	stat[3].setFont(font);
	stat[3].setString("Total points(hard): " + to_string(st[3]));
	stat[3].setFillColor(Color(175, 175, 175));
	stat[3].setOutlineThickness(2);
	stat[3].setOutlineColor(Color::Black);
	stat[3].setCharacterSize(70);
	textRect = stat[3].getLocalBounds();
	stat[3].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	stat[3].setPosition(Vector2f(960, 540 + delta_y + (delta_y / 2)));
	file.close();
	buttons[0].setFont(font);
	buttons[0].setString("Play");
	buttons[0].setFillColor(Color(125, 125, 125));
	buttons[0].setOutlineThickness(2);
	buttons[0].setOutlineColor(Color::Black);
	buttons[0].setCharacterSize(70);
	textRect = buttons[0].getLocalBounds();
	buttons[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttons[0].setPosition(Vector2f(960, 540 - delta_y - (delta_y / 2)));
	buttons[1].setFont(font);
	buttons[1].setString("Results");
	buttons[1].setFillColor(Color(175, 175, 175));
	buttons[1].setOutlineThickness(2);
	buttons[1].setOutlineColor(Color::Black);
	buttons[1].setCharacterSize(70);
	textRect = buttons[1].getLocalBounds();
	buttons[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttons[1].setPosition(Vector2f(960, 540 - (delta_y / 2)));
	buttons[2].setFont(font);
	buttons[2].setString("Settings");
	buttons[2].setFillColor(Color(175, 175, 175));
	buttons[2].setOutlineThickness(2);
	buttons[2].setOutlineColor(Color::Black);
	buttons[2].setCharacterSize(70);
	textRect = buttons[2].getLocalBounds();
	buttons[2].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttons[2].setPosition(Vector2f(960, 540 + (delta_y / 2)));
	buttons[3].setFont(font);
	buttons[3].setString("Exit");
	buttons[3].setFillColor(Color(175, 175, 175));
	buttons[3].setOutlineThickness(2);
	buttons[3].setOutlineColor(Color::Black);
	buttons[3].setCharacterSize(70);
	textRect = buttons[3].getLocalBounds();
	buttons[3].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttons[3].setPosition(Vector2f(960, 540 + delta_y + (delta_y / 2)));
}

void MainMenu::draw(RenderWindow& window) {
	if (mode == 0) {
		for (int i = 0; i < MAX_BUTTONS; ++i) {
			window.draw(buttons[i]);
		}
	}
	else if (mode == 1) {
		for (int i = 0; i < MAX_BUTTONS; ++i) {
			window.draw(stat[i]);
		}
	}
	else if (mode == 2) {
		for (int i = 0; i < MAX_SETTINGS; ++i) {
			window.draw(show_settings[i]);
		}
	}
}

void MainMenu::MoveUp() {
	if (mode == 0) {
		buttons[Button_now].setFillColor(Color(175, 175, 175));
		Button_now = (Button_now - 1 + MAX_BUTTONS) % MAX_BUTTONS;
		buttons[Button_now].setFillColor(Color(125, 125, 125));
	}
	else if (mode == 2) {
		show_settings[cur_setting].setFillColor(Color(175, 175, 175));
		cur_setting = (cur_setting - 1 + MAX_SETTINGS) % MAX_SETTINGS;
		show_settings[cur_setting].setFillColor(Color(125, 125, 125));
	}
}

void MainMenu::MoveDown() {
	if (mode == 0) {
		buttons[Button_now].setFillColor(Color(175, 175, 175));
		Button_now = (Button_now + 1) % MAX_BUTTONS;
		buttons[Button_now].setFillColor(Color(125, 125, 125));
	}
	else if (mode == 2) {
		show_settings[cur_setting].setFillColor(Color(175, 175, 175));
		cur_setting = (cur_setting + 1) % MAX_SETTINGS;
		show_settings[cur_setting].setFillColor(Color(125, 125, 125));
	}
}

void MainMenu::MoveLeft() {
	if (mode == 2) {
		if (settings[cur_setting] == 0) return;
		settings[cur_setting] = (settings[cur_setting] - 1 + max_settings[cur_setting]) % max_settings[cur_setting];
		show_settings[cur_setting].setString("Difficulty: " + dif[settings[cur_setting]]);
	}
}


void MainMenu::MoveRight() {
	if (mode == 2) {
		if (settings[cur_setting] == max_settings[cur_setting] - 1) return;
		settings[cur_setting] = (settings[cur_setting] + 1) % max_settings[cur_setting];
		show_settings[cur_setting].setString("Difficulty: " + dif[settings[cur_setting]]);
	}
}

void MainMenu::change_mode() {
	if (Button_now != 0) {
		mode = Button_now;
	}
	else {
		mode = -1;
	}
}

void MainMenu::reset() {
	mode = 0;
}