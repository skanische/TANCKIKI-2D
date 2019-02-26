//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#ifndef TANCHIKI_GAMEMANAGER_HPP
#define TANCHIKI_GAMEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "ObjectManager.hpp"
#include "PhysicsManager.hpp"
#include "GraphicsManager.hpp"
#include "InterfaceManager.hpp"


/*!
 * \brief Главный класс в программе, который агрегирует в себе всё, что работает в игре.
 */
class GameManager
{
private:
    sf::RenderWindow* mainWindow;       /// окно для рисования

    ObjectManager* objectManager;       /// менеджер объектов
    PhysicsManager* physicsManager;     /// менеджер физики
    GraphicsManager* graphicsManager;   /// менеджер графики
    InterfaceManager* interfaceManager; /// менеджер игрового интерфейса

    sf::Event mainEvent;                /// переменная событий

public:
    GameManager(sf::RenderWindow* initMainWindow);

    /*!
     * \brief запуск игры
     *
     * \details После вызова этого метода игра должна открыться
     * в окне и отобразить главное меню, где можно начать игру,
     * либо выйти из неё.
     */
    void runGame();

    /*!
     * \brief Обработка событий с источников ввода (мышка, клавиатура).
     *
     */
    void checkEvents();

    /*!
     * \brief Очищает экран.
     */
    void clearWindow();

    /*!
     * \brief Рисует все игровые объекты на экран.
     */
    void drawObjects();

    /*!
     * \brief Обновляет все игровые объекты.
     */
    void updateObjecst();

    /*!
     * \brief Закрывает игру.
     *
     * \details После вызова этого метода программа очищает память и закрывает окно с игрой.
     */
    void stopGame();
};

#endif //TANCHIKI_GAMEMANAGER_HPP
