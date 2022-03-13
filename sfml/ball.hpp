//
//  ball.hpp
//  sfml
//
//  Created by Eli Dresnin on 7/10/20.
//  Copyright © 2020 Eli Dresnin. All rights reserved.
//


#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;
class Ball
{
public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    
    float getXVelocity();
    void reboundSides();
    void reboundBatOrTop();
    void hitBottom();
    void update();
private:
    Vector2f position;
    RectangleShape ballShape;
    
    float xVelocity = .1f;
    float yVelocity = .1f;
};
