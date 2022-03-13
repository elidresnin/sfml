//
//  main.cpp
//  sfml
//
//  Created by Eli Dresnin on 7/9/20.
//  Copyright © 2020 Eli Dresnin. All rights reserved.
//

#include "Bat.hpp"
#include "Ball.hpp"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "iD Pong");

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }

        // Ball hit the top of the window
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
        }

        // Ball hit the bottom of the window
        if (ball.getPosition().top > windowHeight)
        {
            ball.hitBottom();
        }

        // Ball hits the sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        // Ball hit the bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
        }

        ball.update();
        bat.update();

        window.clear(Color(148, 213, 0, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
}
