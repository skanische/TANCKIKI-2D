//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "GameObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


GameObject::GameObject() {
    GameObject::sizeX=1;
    GameObject::sizeY=1;
    GameObject::speed=0;
    std::cout << "GameObject created.\n";
}

void GameObject::update() {

}

void GameObject::setRotation(int angle){
    GameObject::sprite.setRotation(-1*angle);
}

float GameObject::getRotation() const{
    return sprite.getRotation();
}

float GameObject::getSizeX() const {
    return sizeX;
}

float GameObject::getSizeY() const {
    return sizeY;
}

void GameObject::setSize(float sizeX, float sizeY) {
    GameObject::sprite.setScale(sizeX/GameObject::sizeX, sizeY/GameObject::sizeY);
    GameObject::sizeX=sizeX;
    GameObject::sizeY=sizeY;
}

GameObject::~GameObject() {

}

bool GameObject::collideCheck(GameObject *obj) {
    return false;
}

void GameObject::collideResponse(GameObject *obj) {

}

float GameObject::getX() const {
    return x;
}

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


void GameObject::setSprite(sf::Sprite sprite_){
    GameObject::sprite=sprite_;
    GameObject::sprite.setOrigin(sizeX/2,sizeY/2);
}

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

void GameObject::setTexture(const char* address) {
    sf::Image image;
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
