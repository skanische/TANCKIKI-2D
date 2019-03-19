//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#include "EventManager.hpp"

bool EventManager::pollEvent() {
    return mainWindow->pollEvent(*event);
}

EventManager::EventManager(sf::RenderWindow *the_mainWindow, sf::Event *the_event)
{
    mainWindow = the_mainWindow;
    event = the_event;
}

std::string EventManager::getMessageFromGameObjects() {
    ///@todo реализовать согласно ТЗ
    return std::string();
}


