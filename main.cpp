#include <SFML/Graphics.hpp>
#include "sources/windowConfig.hpp"
#include "sources/GameManager.hpp"

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

    GameManager* Game = new GameManager(&mainWindow);
    Game->runGame();
    return 0;
}