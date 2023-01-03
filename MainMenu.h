#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

const int MAX_BUTTONS = 4, MAX_STAT = 4, MAX_SETTINGS = 1;
const std::string dif[3] = { "Easy", "Meadium", "Hard" };

class MainMenu {
private:
	int Button_now, mode, settings[MAX_SETTINGS], cur_setting, max_settings[MAX_SETTINGS];
	Font font;
	Text buttons[MAX_BUTTONS], stat[MAX_STAT], show_settings[MAX_SETTINGS];
public:
	MainMenu(float width, float height);
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void change_mode();
	void reset();
	int MainPressed() {
		return Button_now;
	}
	int get_mode() {
		return mode;
	}
	int get_set(int v) {
		return settings[v];
	}
	void inc(int v, int c) {
		++settings[0];
		settings[v] += c;
	}
};