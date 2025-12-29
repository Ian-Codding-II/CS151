#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "mainMenu.h"
#include <iostream>

int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "MainMenu Test");
        window.setVerticalSyncEnabled(true);

        MainMenu menu(window);
        menu.initialize();  // NOW safe - OpenGL context ready!

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                menu.update(event);

                if (menu.shouldStartGame()) {
                    std::cout << "Start Game clicked! Starting game...\n";
                    menu.reset();
                }
                if (menu.shouldQuit()) {
                    std::cout << "Quit clicked! Exiting...\n";
                    window.close();
                }
            }

            menu.draw(window);
            window.display();
        }

    } catch (const std::exception& e) {
        std::cerr << "[FATAL ERROR] " << e.what() << "\n";
        return 1;
    }

    return 0;
}