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

EventManager::EventManager(sf::RenderWindow *theMainWindow, sf::Event *the_event, int playerId, gameState_t *the_state)
        :
playerId(playerId)
{
    mainWindow = theMainWindow;
    event = the_event;
    state = the_state;
}

std::string EventManager::getMessageFromGameObjects() {
    ///@todo реализовать согласно ТЗ
    if (pollEvent())
    {
        switch (*state) {
            case GAME_STATE_MATCH: {
                matchActions();
                break;
            }
            case GAME_STATE_MATCH_PAUSE: {
                MatchPauseActions();
                break;
            }
            default:
                break;
        }


    }
    return std::string();
}

std::string EventManager::matchActions() {
    switch (event->type) {
        case sf::Event::Closed: {
            mainWindow->close();
            break;
        }
        case sf::Event::KeyPressed:
        {
            switch (event->key.code) {
                case sf::Keyboard::Left:
                case sf::Keyboard::A: {
                    json json_message;
                    //                        json_message["status"] = "OK";
                    //                        json_message["from"] = playerId;
                    //                        json_message["method"] = "getAcceleration";
                    //                        json_message["params"] = json::array({-2, 0});
                    //                        std::cout << json_message.dump();
                    return json_message.dump();
                }
                case sf::Keyboard::Right:
                case sf::Keyboard::D: {
                    json json_message;
                    //                        json_message["status"] = "OK";
                    //                        json_message["from"] = playerId;
                    //                        json_message["method"] = "getAcceleration";
                    //                        json_message["params"] = json::array({-2, 0});
                    //                        std::cout << json_message.dump();
                    return json_message.dump();
                }
                case sf::Keyboard::Up:
                case sf::Keyboard::W: {
                    json json_message;
                    //                        json_message["status"] = "OK";
                    //                        json_message["from"] = playerId;
                    //                        json_message["method"] = "getAcceleration";
                    //                        json_message["params"] = json::array({-2, 0});
                    //                        std::cout << json_message.dump();
                    return json_message.dump();
                }
                case sf::Keyboard::Down:
                case sf::Keyboard::S: {
                    json json_message;
                    //                        json_message["status"] = "OK";
                    //                        json_message["from"] = playerId;
                    //                        json_message["method"] = "getAcceleration";
                    //                        json_message["params"] = json::array({-2, 0});
                    //                        std::cout << json_message.dump();
                    return json_message.dump();
                }
                case sf::Keyboard::Escape: {
                    *state = GAME_STATE_MATCH_PAUSE;
                    std::cout << "Game state is MATCH_PAUSE\n";
                    break;
                }
                case sf::Keyboard::Space: {
                    json json_message;
                    json_message["status"] = "OK";
                    json_message["from"] = playerId;
                    json_message["method"] = "shoot";
                    json_message["params"] = json::array(/*!some params from Maxim*/);
                    std::cout << json_message.dump() << std::endl;
                    return json_message.dump();
                }
                default: {
                    std::cout << "You pressed " << event->key.code << std::endl;
                    break;
                }
            }
            break;
        }
        case sf::Event::KeyReleased: {
            ///@todo keyRelease events...
            break;
        }
        default:
            break;
    }

    return std::string();
}

void EventManager::MatchPauseActions() {
    switch (event->type)
    {
        case sf::Event::Closed: {
            mainWindow->close();
            break;
        }
        case sf::Event::KeyPressed: {
            switch (event->key.code) {
                case sf::Keyboard::Escape: {
                    *state = GAME_STATE_MATCH;
                    std::cout << "Game state is MATCH\n";
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

}
