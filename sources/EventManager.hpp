//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#ifndef TANCHIKI_EVENTMANAGER_HPP
#define TANCHIKI_EVENTMANAGER_HPP


#include <SFML/Graphics.hpp>
#include "gameStates.hpp"

class EventManager {
private:
    sf::RenderWindow* mainWindow;
    gameState_t* state;
    sf::Event* event;

public:
    EventManager(sf::RenderWindow *mainWindow, sf::Event *event);
    void pollEvent();
    std::string getMessageFromGameObjects();

};


#endif //TANCHIKI_EVENTMANAGER_HPP
