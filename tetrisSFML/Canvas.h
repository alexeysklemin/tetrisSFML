#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>

using namespace sf;

class Canvas {
public:
    double timer = 0.0, delay = 0.3;
    void canvas() {
        Clock clock;
        RenderWindow window(VideoMode(320, 480), "The Game!");
        Texture t1, t2, t3;
        t1.loadFromFile("images/tiles.png");
        t2.loadFromFile("images/background.png");
        t3.loadFromFile("images/frame.png");

        Sprite s(t1), background(t2), frame(t3);
        window.clear(Color::White);
        window.draw(background);
    }
    void display() {
        Clock clock;
        RenderWindow window(VideoMode(320, 480), "The Game!");
        while (window.isOpen()) {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();


            }
        }

    }
};