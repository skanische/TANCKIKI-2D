//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "GameObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

GameObject::GameObject() {
    std::cout << "GameObject created.\n";
}

}

}

}

}


    GameObject::sizeY=sizeY;
}

GameObject::~GameObject() {

}

bool GameObject::collideCheck(GameObject *obj) {
    return false;
}

void GameObject::collideResponse(GameObject *obj) {

}

double GameObject::getX() const {
float GameObject::getX() const {
    return x;
}

double GameObject::getY() const {
float GameObject::getY() const {
    return y;
}

bool GameObject::isAlive() const {
    return alive;
}

const sf::Sprite &GameObject::getSprite() const {
    return sprite;
}

const sf::Texture &GameObject::getTexture() const {
    return texture;
}


void GameObject::setAlive(bool alive) {
    GameObject::alive = alive;
}

void GameObject::setPosition(float X, float Y){
    GameObject::x=X;
    GameObject::y=Y;
    GameObject::sprite.setPosition(X,Y);
}


    GameObject::sprite=sprite_;
    GameObject::sprite.setOrigin(x+sizeX/2,y+sizeY/2);

void GameObject::setSprite(int X, int Y, int sizeX, int sizeY){
    GameObject::sizeX=sizeX;
    GameObject::sizeY=sizeY;
    GameObject::sprite.setTexture(GameObject::texture);
    GameObject::sprite.setTextureRect(sf::IntRect(X,Y,sizeX,sizeY));
    GameObject::sprite.setOrigin(sizeX/2,sizeY/2);
}

void GameObject::setTexture(sf::Texture texture_){
    GameObject::texture=texture_;
}
    image.loadFromFile(address);
    GameObject::texture.loadFromImage(image);
}


void GameObject::setSpeed(float v) {
    GameObject::speed = v;
}

void GameObject::draw(sf::RenderWindow *window) {

}

float GameObject::getSpeed() const {
    return speed;
}
