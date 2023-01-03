#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

using namespace std;
using namespace sf;

const int COL = 4;

class MyGame {
private:
	int speed, mode, cnt_all, cnt_ok, speed_boost, max_speed, delta;
	vector <CircleShape> my_obj[COL];
	CircleShape buttons[COL];
public:
	MyGame(int dif);
	void MoveDown();
	void Clear();
	void Add();
	void change_speed();
	void Pressed(int v);
	void draw(RenderWindow& window);
	bool lose() {
		if (cnt_all - cnt_ok >= 10) return 1;
		return 0;
	}
	int get_p() { return cnt_ok; }
};