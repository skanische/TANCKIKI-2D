//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#include <iostream>
#include <stdio.h>
#include "EventManager.hpp"
#include "json/json.hpp"
using json = nlohmann::json;

bool EventManager::pollEvent() {
    return mainWindow->pollEvent(*event);
}

EventManager::EventManager(sf::RenderWindow *theMainWindow, sf::Event *the_event, int playerId):
playerId(playerId)
{
    mainWindow = theMainWindow;
    event = the_event;
}

std::string EventManager::getMessageFromGameObjects() {
    ///@todo реализовать согласно ТЗ
    if (pollEvent())
    {
        switch (event->type) {
            case sf::Event::Closed: {
                mainWindow->close();
            }
            case sf::Event::KeyPressed: {
                switch (event->key.code) {
                    case sf::Keyboard::A: {
                        json j;
                        j["status"] = "OK";
                        j["from"] = playerId;
                        j["method"] = "moveleft";
                        j["params"] = json::array({-2, 0});
                        std::cout << j.dump();
                        break;
                        return j.dump();
                    }
                    default: {
                        std::cout << "You pressed " << event->key.code << std::endl;
                        break;
                    }
                }
                break;
            }
            default: {
                break;
            }
        }

    }
    return std::string();
}


