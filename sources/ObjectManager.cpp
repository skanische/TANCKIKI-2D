//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "ObjectManager.hpp"

ObjectManager::ObjectManager(sf::RenderWindow *window) {
    objects = std::vector <GameObject* > ();
}

const sf::RenderWindow &ObjectManager::getMainWindow() const {
    return mainWindow;
}

void ObjectManager::addGameObject(GameObject *obj) {
    objects.push_back(obj);
}

void ObjectManager::removeGameObject(GameObject *obj) {

}

GameObject* ObjectManager::getGameObjectById(int gameObjectId) {
    ///@todo реализовать
    return objects[gameObjectId];
}

const std::vector<GameObject *> &ObjectManager::getObjects() const {
    return objects;
}
