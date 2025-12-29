/**
 * @file main.cpp
 * @author Ekaterina Miller
 * @brief  This program testing class buton
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 * @aknolegment https://code.markrichards.ninja/sfml/how-to-create-simple-buttons-for-your-sfml-game
 *
 *
 */
#include "button.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 500), "MyButton!");
//     sf::Texture texture;
//     if (!texture.loadFromFile("button.png"))
//     {
//         std::cout<<"Error opening file\n";
//         exit(1);
//     }
//     //create sprite that look like a button
//     sf::Sprite button(texture);

//     //get size of image
//     sf::Vector2u imageSize=texture.getSize();
//     //change origin to the center of the image (makes rotation easy)
//     button.setOrigin(imageSize.x/2, imageSize.y/2);
//     //set position
//     sf::Vector2f position={300,200};
//     button.setPosition(position.x,position.y);
//     //choose color
//     button.setColor(sf::Color(0, 0, 255));
//     //set size as a ration of original size
//     button.setScale(0.5,0.5);
//     //Make label
//     sf::Font font;
//     if (!font.loadFromFile("college.ttf"))
//     {
//         std::cout<<"Error opening file\n";
//         exit(2);
//     }
//     sf::Text text;
//     text.setFont(font);
//     //choose the font size based on button size (I choose half)
//     unsigned int fontSize = button.getGlobalBounds().height/2;
//     text.setCharacterSize(fontSize);
//     //set label
//     text.setString("Push me!");
//     //set origin to the middle
//     text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
//     //set position at the middle of the button
//     text.setPosition(position.x, position.y-fontSize/4);
//     //choose colors
//     sf::Color textNormal = sf::Color::Green;
//     sf::Color textHover = sf::Color::Red;
//     text.setFillColor(textNormal);
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             //get position of the mouse
//             //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//             sf::Vector2i mPos = sf::Mouse::getPosition(window);
//             sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
//             bool mouseInButton =    mousePosition.x >= button.getPosition().x - button.getGlobalBounds().width/2
//                                     && mousePosition.x <= button.getPosition().x + button.getGlobalBounds().width/2
//                                     && mousePosition.y >= button.getPosition().y - button.getGlobalBounds().height/2
//                                     && mousePosition.y <= button.getPosition().y + button.getGlobalBounds().height/2;
//             if(event.type == sf::Event::MouseMoved)
//             {
//                 if(mouseInButton)
//                 {
//                     text.setFillColor(textHover);
//                 }
//                 else
//                 {
//                     text.setFillColor(textNormal);
//                 }
//             }
//             if (event.type == sf::Event::MouseButtonPressed)
//             {
//                 if(event.mouseButton.button==sf::Mouse::Left)
//                 {
//                     if(mouseInButton)
//                     {
//                         button.setRotation(180);
//                     }
//                     else
//                     {
//                         button.setRotation(0);
//                     }
//                 }
//             }
//             if (event.type == sf::Event::MouseButtonReleased)
//             {
//                 if (event.mouseButton.button==sf::Mouse::Left)
//                 {
//                     if(mouseInButton)
//                     {
//                         text.setFillColor(textHover);
//                         button.setRotation(0);
//                     }
//                     else
//                     {
//                         text.setFillColor(textNormal);
//                         button.setRotation(0);
//                     }
//                 }
//             }
//         }
//         window.clear();
//         window.draw(button);
//         window.draw(text);
//         window.display();
//     }
//     return 0;
// }

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "MyButton!");
    window.setPosition(sf::Vector2i(30,30));
    Button yes("Yes", {200, 300}, {200, 71}, sf::Color::Red);
    Button no;
    no.setText("No");
    no.setPosition({600, 300});
    no.setSize({200, 71});
    no.setColor(sf::Color(0, 255, 255));
    // no.setColorTextHover(sf::Color::Red);
    // no.setColorTextNormal(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                {window.close();}
            yes.update(event, window);
            no.update(event, window);
        }

        window.clear();
        window.draw(yes);
        window.draw(no);
        window.display();
    }

    return 0;
}