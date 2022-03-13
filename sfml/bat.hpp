//
//  bat.hpp
//  sfml
//
//  Created by Eli Dresnin on 7/10/20.
//  Copyright © 2020 Eli Dresnin. All rights reserved.
//

#ifndef bat_hpp
#define bat_hpp
#include <stdio.h>
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bat
{
public:
    Bat(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    
    
    void moveLeft();
    void moveRight();
    void update();
    
private:
    Vector2f position;
    RectangleShape batShape;
    float batSpeed = 0.3f;
};



#endif /* bat_hpp */
