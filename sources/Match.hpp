//
// Created by Кежик Кызыл-оол on 2019-03-19.
//

#ifndef TANCHIKI_MATCH_HPP
#define TANCHIKI_MATCH_HPP


#include "GraphicsManager.hpp"
#include "PhysicsManager.hpp"
#include "ObjectManager.hpp"

class Match {
private:
    ObjectManager* objectManager;
    GraphicsManager* graphicsManager;
    PhysicsManager* physicsManager;
    std::string mapName;
    int myPlayerId;

    unsigned int amount_of_blocks_x, amount_of_blocks_y;
    block_t* blocks;

    unsigned int amount_of_players;
    std::vector <std::string> players_names;

public:
    Match(sf::RenderWindow *mainWindow, std::string players_info_json, std::string map_json);

    void drawMatch();
    void updateMatch();
    void processMessage(std::string message);
    const std::string &getMapName() const;
};


#endif //TANCHIKI_MATCH_HPP
