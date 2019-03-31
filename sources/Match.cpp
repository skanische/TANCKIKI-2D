//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#include <string>
#include "Match.hpp"
#include "blocks.hpp"
#include "Tank.hpp"


Match::Match(sf::RenderWindow *mainWindow, std::string players_info_json, std::string map_json) {
    ///@todo распарсить map_json
    mapName = "MAP_NAME";
    amount_of_blocks_x = 30;
    amount_of_blocks_y = 30;
    blocks = new block_t[amount_of_blocks_x*amount_of_blocks_y];
    ///@todo заполнить blocks


    objectManager = new ObjectManager(mainWindow);
    graphicsManager = new GraphicsManager(objectManager, blocks, amount_of_blocks_y, amount_of_blocks_x, mainWindow);
    physicsManager = new PhysicsManager(objectManager);

    ///@todo распарсить players_info_json
    amount_of_players = 3;
    players_names = std::vector <std::string> (amount_of_players);
    ///@todo заполнить players_names

    ///@todo решить, с какими начальными координатами ставить игроков на карту
    std::pair <int, int> playersInitialCoordinates[amount_of_players];
    ///@todo заполнить playersInitialCoordinates

    ///@todo создать amount_of_players танков
    ///@todo передать все эти танки в objectManager, вызывая у него addGameObject

    ///@todo узнать свой player_id (подумать, кто будет назначать player_id)

    Tank *tank1 = new Tank();
    tank1->setTexture("C:/Users/Apxapa/Documents/Github/TANCKIKI-2D-/images/tanks_16.png");
    tank1->setSprite(96,48,16,16);  //задает вид спрайта на основе уже имеющейся тестуры
    tank1->setPosition(200,200);
    objectManager->addGameObject(tank1);

}

void Match::drawMatch() {
    graphicsManager->drawGameObjects();
}

void Match::updateMatch() {
    physicsManager->updateGameObjects();
}

const std::string &Match::getMapName() const {
    return mapName;
}

void Match::processMessage(std::string message) {
    ///@todo распарсить message
    ///@todo обработать message
}


