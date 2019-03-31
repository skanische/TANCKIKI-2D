#include <utility>

//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "GameObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class Point
{
public:
    float x;
    float y;
};

GameObject::GameObject() {
    GameObject::sizeX=1;
    GameObject::sizeY=1;
    GameObject::speedX=0;
    GameObject::speedY=0;
    std::cout << "GameObject created.\n";
}

void GameObject::update() {

}

void GameObject::setRotation(int angle){
    GameObject::sprite.setRotation(-angle);
    cos = cosf((float)angle / 2 / M_PI));
    sin = sinf((float)angle / 2 / M_PI));
}

float GameObject::getRotation() const{
    return -sprite.getRotation();
}

float GameObject::getSizeX() const {
    return sizeX;
}

float GameObject::getSizeY() const {
    return sizeY;
}

void GameObject::setSizeObj(float sizeX_, float sizeY_) {
    GameObject::sizeX=sizeX_;
    GameObject::sizeY=sizeY_;
    d=sqrtf(powf(sizeX_/2,2)+powf(sizeY_/2,2));
}

void GameObject::setSizeSprite(float sizeX_, float sizeY_) {
    GameObject::sprite.setScale(sizeX_/GameObject::sizeX, sizeY_/GameObject::sizeY);
}

GameObject::~GameObject() {

}

int GameObject::collideCheck(GameObject *obj) {
    return false;
}

void GameObject::collideResponse(int P, GameObject *obj) {

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

}

void GameObject::setSprite(int X, int Y, int sizeX_, int sizeY_){
    GameObject::sizeX=sizeX_;
    GameObject::sizeY=sizeY_;
    GameObject::sprite.setTexture(GameObject::texture);
    GameObject::sprite.setTextureRect(sf::IntRect(X,Y,sizeX_,sizeY_));
    GameObject::sprite.setOrigin(sizeX_/2,sizeY_/2);
}

void GameObject::setTexture(sf::Texture texture_){
    GameObject::texture=texture_;
}

void GameObject::setTexture(const char* address) {
    sf::Image image;
    image.loadFromFile(address);
    GameObject::texture.loadFromImage(image);
}


void GameObject::setSpeed(float spX, float spY) {
    GameObject::speedX = spX;
    GameObject::speedY = spY;
}

void GameObject::draw(sf::RenderWindow *window) {

}

float GameObject::getSpeedX() const {
    return speedX;
}

float GameObject::getSpeedY() const {
    return speedY;
}

void GameObject::multSize(float k){
    GameObject::sizeX=k*sizeX;
    GameObject::sizeY=k*sizeY;
    GameObject::sprite.setScale(k*sprite.getScale().x, k*sprite.getScale().y);
    d=k*d;
}

gameObject_t GameObject::getType() const {
    return type;
}

float GameObject::getDiam() const {
    return d;
}

float GameObject::getSin() const{
    return sin;
}

float GameObject::getCos() const{
    return cos;
}