//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "PhysicsManager.hpp"

PhysicsManager::PhysicsManager(ObjectManager *theObjectManager) {
    objectManager = theObjectManager;
}

void PhysicsManager::updateGameObjects() {
    for (const auto &object : objectManager->getObjects()) {
        object->update();
    }
}
