#pragma once

#include <SFML/Graphics.hpp>
class Game {
  public:
    Game();
    ~Game() {};
    void handleInput();
    void update(float time);
    void render();
    bool isDone() const;

  private:
    sf::RenderWindow mWindow;
    bool mIsDone;
    sf::Texture mTextureTile;
    sf::CircleShape mCherryPlant;
    sf::Vector2f mIncrement;
    void moveCherry(float time);
};