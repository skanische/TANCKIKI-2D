#include <iostream>
#include "sources/GameObject.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(640,480),"Test"); //создаем окноэтих размеров

    Image tankImage;
    tankImage.loadFromFile("images/tanks_16.png"); //загружаем изображение
    tankImage.createMaskFromColor(sf::Color::Black);

    Texture tankTexture;
    tankTexture.loadFromImage(tankImage);


    Sprite tankSprite;
    tankSprite.setTexture(tankTexture);
    tankSprite.setTextureRect(IntRect(0,0,16,16));
    tankSprite.setScale(3,3);

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::A)))
        {
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 2) CurrentFrame -= 2; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            tankSprite.setTextureRect(IntRect(32+16* int(CurrentFrame), 0, 16, 16)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            tankSprite.move(-0.1*time, 0);//происходит само движение персонажа влево
        }

        if ((Keyboard::isKeyPressed(Keyboard::D)))
        {
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 2) CurrentFrame -= 2; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            tankSprite.setTextureRect(IntRect(96+16* int(CurrentFrame), 0, 16, 16)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            tankSprite.move(0.1*time, 0);//происходит само движение персонажа влево
        }

        if ((Keyboard::isKeyPressed(Keyboard::W)) && (Keyboard::isKeyPressed(Keyboard::A))==0 && (Keyboard::isKeyPressed(Keyboard::D))==0)
        {
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 2) CurrentFrame -= 2; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            tankSprite.setTextureRect(IntRect(16* int(CurrentFrame), 0, 16, 16)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            tankSprite.move(0, -0.1*time);//происходит само движение персонажа влево
        }

        if ((Keyboard::isKeyPressed(Keyboard::S)) && (Keyboard::isKeyPressed(Keyboard::A))==0 && (Keyboard::isKeyPressed(Keyboard::D))==0)
        {
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (CurrentFrame > 2) CurrentFrame -= 2; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            tankSprite.setTextureRect(IntRect(64+16* int(CurrentFrame), 0, 16, 16)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            tankSprite.move(0, 0.1*time);//происходит само движение персонажа влево
        }

        window.clear();
        window.draw(tankSprite);//выводим спрайт на экран
        window.display();
    }

    return 0;
}