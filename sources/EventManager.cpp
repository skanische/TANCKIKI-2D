//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#include "EventManager.hpp"

void EventManager::pollEvent() {
//    mainWindow->pollEvent(*event);
}

EventManager::EventManager(sf::RenderWindow *mainWindow, sf::Event *event)
{
    mainWindow = mainWindow;
    event = event;
}

std::string EventManager::getMessageFromGameObjects() {
    ///@todo реализовать согласно ТЗ
    return std::string();
}


