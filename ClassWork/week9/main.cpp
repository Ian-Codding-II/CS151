#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

int main() {
    Game game;
    // const sf::Time TIME_PER_FRAME = sf::milliseconds(1.f / 60.f);
    sf::Clock clock;
    // float currentTime = clock.restart().asSeconds();
    // // display speed in frames per second
    // float fps = 1.0 / currentTime;
    // std::cout << "fps: " << fps << std::endl;
    while (!game.isDone()) {
        float dt = clock.restart().asSeconds();
        game.handleInput();
        game.update(dt);
        game.render();

        // sf::sleep(start + TIME_PER_FRAME - clock.getElapsedTime());
    }
    return 0;
}