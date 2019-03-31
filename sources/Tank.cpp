//
// Created by Apxapa on 30.03.2019.
//

#include "Tank.hpp"

Tank::Tank()  : GameObject::GameObject()  {
    Tank::type=TANK;
}


int Tank::getHealth() {
    return Tank::health;
}

void Tank::setHealth(int health) {
    Tank::health=health;
}

void Tank::update() {
    float dx, dy;
    int angle = (int)getRotation();
    switch (angle)
    {
        case 0: dx = speed; dy = 0; break;
        case 180: dx = -speed; dy = 0; break;
        case 270: dx = 0; dy = speed; break;
        case 90: dx = 0; dy = -speed; break;
        default: dx = 0; dy = 0; break;
    }

    setPosition(dx*TIME,dy*TIME);
}

void Tank::draw(sf::RenderWindow* window) {
    window->draw(Tank::sprite);
}

