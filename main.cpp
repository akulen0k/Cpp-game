#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MyGame.h"
#include <Windows.h>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Game", 0);
    window.setMouseCursorVisible(false);
    window.setFrameLimit(60);
    Texture t;
    t.loadFromFile("images/menu4.jpg");
    Sprite s(t);
    s.setScale(1920 / s.getLocalBounds().width, 1080 / s.getLocalBounds().height);
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyReleased) {
                if (mainMenu.get_mode() == 0) {
                    if (event.key.code == Keyboard::Up) {
                        mainMenu.MoveUp();
                    }
                    else if (event.key.code == Keyboard::Down) {
                        mainMenu.MoveDown();
                    }
                    else if (event.key.code == Keyboard::Enter) {
                        if (mainMenu.MainPressed() == 3) window.close();
                        else if (mainMenu.MainPressed() == 0) {
                            mainMenu.change_mode();
                            bool fl = 1;
                            int lel = 0;
                            MyGame myGame(mainMenu.get_set(0));
                            while (fl) {
                                Event game_event;
                                while (window.pollEvent(game_event)) {
                                    if (game_event.type == Event::Closed) {
                                        window.close();
                                        fl = 0;
                                    }
                                    if (game_event.type == Event::KeyReleased) {
                                        if (game_event.key.code == Keyboard::Escape) {
                                            fl = 0;
                                        }
                                        // тут кнопки игры
                                        if (game_event.key.code == Keyboard::Z) myGame.Pressed(0);
                                        if (game_event.key.code == Keyboard::X) myGame.Pressed(1);
                                        if (game_event.key.code == Keyboard::C) myGame.Pressed(2);
                                        if (game_event.key.code == Keyboard::V) myGame.Pressed(3);
                                    }
                                }
                                myGame.Clear();
                                if (lel % 50 == 0) {
                                    myGame.Add();
                                }
                                if (lel % 100 == 0) myGame.change_speed();
                                myGame.MoveDown();
                                window.clear();
                                window.draw(s);
                                myGame.draw(window);
                                window.display();
                                //Sleep(10);
                                lel += 1;
                                if (myGame.lose()) {
                                    lel = 0;
                                    fl = 0;
                                    mainMenu.inc(mainMenu.get_set(0), myGame.get_p());
                                }
                            }
                            mainMenu.reset();
                        }
                        else mainMenu.change_mode();
                    }
                }
                if (event.key.code == Keyboard::Escape) {
                    mainMenu.reset();
                }
                if (mainMenu.get_mode() == 2) {
                    if (event.key.code == Keyboard::Left) mainMenu.MoveLeft();
                    else if (event.key.code == Keyboard::Right) mainMenu.MoveRight();
                }
            }
        }
        window.clear();
        window.draw(s);
        mainMenu.draw(window);
        window.display();
    }
    return 0;
}
