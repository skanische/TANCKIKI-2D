//
// Created by Apxapa on 30.03.2019.
//

#include "Tank.hpp"
#include <cmath>


class Point
{
public:
    float x;
    float y;
};


Tank::Tank() : GameObject::GameObject() {
    Tank::type=TANK;
}


int Tank::getHealth() {
    return Tank::health;
}

void Tank::setHealth(int health) {
    Tank::health=health;
}

void Tank::update() {
    setPosition(x+speedX*TIME,y+speedY*TIME);
}

void Tank::draw(sf::RenderWindow* window) {
    window->draw(Tank::sprite);
}

int checkLocPointStraight(Point A, Point B, Point C){ ///A и B задают прямую, C - точка, 1 - если точка слева над прямой, 0 - если под
    if(A.x==B.x){
        return C.x < A.x;
    }
        float k=atanf((B.y-A.y)/(B.x-A.x));
        float b=A.y-k*A.x;
        return C.y > k * C.x + b;
}

bool checkLocPointSquare(Point A, Point B, Point C, Point D, Point X){ ///сначала НИЖНЯЯ левая, против часовой стрелки
    return checkLocPointStraight(A, B, X) && !checkLocPointStraight(B, C, X) && !checkLocPointStraight(C, D, X) && checkLocPointStraight(D, A, X);
}

int Tank::collideCheck(GameObject* obj) {
    if(obj->getType()==TANK) {
        Point A[4], B[4];
        float d1 = d;
        float d2 = obj->getDiam();
        if (powf(d1 + d2, 2) < powf(x - obj->getX(), 2) + powf(y - obj->getY(), 2))
            return 0;
        float cos1 = cosf((GameObject::getRotation()) / 2 / (float) M_PI);
        float sin1 = sinf((GameObject::getRotation()) / 2 / (float) M_PI);
        float cos2 = cosf((obj->getRotation()) / 2 / (float) M_PI);
        float sin2 = sinf((obj->getRotation()) / 2 / (float) M_PI);

        float Asx = sizeX / 2, Ax = x, Asy = sizeY / 2, Ay = y;
        float Bsx = obj->getSizeX() / 2, Bx = obj->getX(), Bsy = obj->getSizeY() / 2, By = obj->getY();

        A[0].x = Ax - Asx * cos1 + Asy * sin1; A[0].y = Ay - Asx / 2 * sin1 - Asy * cos1;
        A[1].x = Ax + Asx * cos1 + Asy * sin1; A[1].y = Ay + Asx / 2 * sin1 - Asy * cos1;
        A[2].x = Ax + Asx * cos1 - Asy * sin1; A[2].y = Ay + Asx / 2 * sin1 + Asy * cos1;
        A[3].x = Ax - Asx * cos1 - Asy * sin1; A[3].y = Ay - Asx / 2 * sin1 + Asy * cos1;

        B[0].x = Bx - Bsx * cos2 + Bsy * sin2; B[0].y = By - Bsx / 2 * sin2 - Bsy * cos2;
        B[1].x = Bx + Bsx * cos2 + Bsy * sin2; B[1].y = By + Bsx / 2 * sin2 - Bsy * cos2;
        B[2].x = Bx + Bsx * cos2 - Bsy * sin2; B[2].y = By + Bsx / 2 * sin2 + Bsy * cos2;
        B[3].x = Bx - Bsx * cos2 - Bsy * sin2; B[3].y = By - Bsx / 2 * sin2 + Bsy * cos2;

        for (int i = 0; i < 4; ++i) {
            if (checkLocPointSquare(A[0], A[1], A[2], A[3], B[i])) return 4+i;
        }
        for (int i = 0; i < 4; ++i) {
            if (checkLocPointSquare(B[0], B[1], B[2], B[3], A[i])) return i;
        }
        return 0;
    }
    return false;
}

void Tank::collideResponse(GameObject *obj) {
    if(obj->getType()==TANK) {

    }
}

float Tank::getDiam() {
    return d;
}



