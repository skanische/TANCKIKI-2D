//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "GameObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

GameObject::GameObject() {
    std::cout << "GameObject created.\n";
}

GameObject::GameObject(double x, double y) {
    std::cout << "GameObject (" << x << ", " << y << ") created.\n";
}

void GameObject::draw() {

}

void GameObject::update() {

}

GameObject::~GameObject() {

}

bool GameObject::collideCheck(GameObject *obj) {
    return false;
}

void GameObject::collideResponse(GameObject *obj) {

}

double GameObject::getX() const {
    return x;
}

double GameObject::getY() const {
    return y;
}

gameObject_t GameObject::getType() const {
    return type;
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
