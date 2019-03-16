//
// Created by Кежик Кызыл-оол on 2019-02-26.
//

#ifndef TANCHIKI_GAMEOBJECT_HPP
#define TANCHIKI_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>


enum gameObject_t {
    ABYSS = 0,
    TANK,
    BULLET,
    GROUND
};

/*!
 *      \brief
 *      Родительский класс для всех игровых объектов
 */
class GameObject
{
protected:
    bool alive;             /// жив ли ещё объект
    gameObject_t type;      /// тип игрового объекта
    double x, y;            /// координаты объекта на экране
    sf::Sprite sprite;
    sf::Texture texture;


public:
    GameObject();
    GameObject(double x, double y);
    virtual ~GameObject();

    /*!
     * \brief Рисует игровой объект на экране
     *
     * Спрайт тупо рисуется на экране с координатами x, y.
     */
    virtual void draw();

    /*!
     * \brief Обновляет игровой объект. У каждого игрового объекта своя реализация этого метода.
     */
    virtual void update();

    /*!
     * \brief
     * Проверяет, есть ли взаимодействие с игровым объектом obj
     *
     * @param obj - указатель на игровой объект, взаимодействие с которым проверяется
     * @return true, если есть взаимодействие. В противном случае – false
     */
    virtual bool collideCheck(GameObject* obj);

    /*!
     * \brief
     * Выполняет акт взаимодействия с игровым объектом obj
     *
     * @param obj - указатель на игровой объект, с которым будет выполнен акт взаимодействия
     */
    virtual void collideResponse(GameObject* obj);

    double getX() const;

    double getY() const;

    gameObject_t getType() const;

    bool isAlive() const;

    const sf::Sprite &getSprite() const;

    const sf::Texture &getTexture() const;

    void setAlive(bool alive);
};

class tank : GameObject {
protected:

    int health;

public:
    tank();

    int getHealth();

    void setHealth(int healthScore);
};












#endif //TANCHIKI_GAMEOBJECT_HPP

