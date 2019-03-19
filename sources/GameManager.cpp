//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#include "GameManager.hpp"
#include <SFML/Graphics.hpp>

GameManager::GameManager(sf::RenderWindow* the_mainWindow)
{
    ///@todo проверить наличие файла player_info.json
    state = GAME_STATE_ENTER_NAME;
    event = new sf::Event;
    mainWindow = the_mainWindow;

    interfaceManager = new InterfaceManager(mainWindow, nullptr, &state);
    eventManager = new EventManager(mainWindow, event);
}

void GameManager::runGame() {
    while (mainWindow->isOpen()) {
        interfaceManager->makeInterface();
        handleEvent();

        switch (state) {
            case GAME_STATE_CREATE_MATCH: {
                std::string players_info_json, map_json;
                match = new Match(mainWindow, players_info_json, map_json);
                interfaceManager->setMapName(match->getMapName());

                state = GAME_STATE_MATCH;
                break;
            }
            case GAME_STATE_MATCH: {
                std::string message = eventManager->getMessageFromGameObjects();
                match->processMessage(message);
                match->updateMatch();
                match->drawMatch();
            }
            default: {
                break;
            }
        }
        mainWindow->clear();
        mainWindow->display();
    }
}

void GameManager::handleEvent() {
    ///@todo дописать этот метод
    if (eventManager->pollEvent()) {
        switch (event->type) {
            case sf::Event::Closed: {
                mainWindow->close();
                break;
            }
            default: {
                break;
            }
        }
    }


}
