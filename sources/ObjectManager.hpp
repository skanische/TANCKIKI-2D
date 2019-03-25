//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#ifndef TANCHIKI_OBJECTMANAGER_HPP
#define TANCHIKI_OBJECTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"


/*!
 * Этот менеджер отвечает за хранение игровых объектов.
 */
class ObjectManager
{
private:
    /// \todo Нужно придумать свойство, в котором будут храниться все игровые объекты.
    std::vector <GameObject*> objects;
public:
    const std::vector<GameObject *> &getObjects() const;

private:
    sf::RenderWindow mainWindow;

public:
    ObjectManager(sf::RenderWindow* window);

    void addGameObject(GameObject* obj);
    void removeGameObject(GameObject* obj);
    GameObject* getGameObjectById(int gameObjectId);
    /// \todo Доступ к объектам (геттер игрового объекта)
    const sf::RenderWindow &getMainWindow() const;



};

#endif //TANCHIKI_OBJECTMANAGER_HPP
