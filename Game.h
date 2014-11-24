#ifndef GAME_H
#define GAME_H

#include <SFML/Window/Keyboard.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Mapping.hxx"

class Game {

public:
  enum PlayerDirection {
    Up,
    Down,
    Left,
    Right
  };

public:
  Game(void);
  void run(void);

private:
  void processEvents(void);
  void update(void);
  void render(void);
  void handlePlayerInput(sf::Keyboard::Key p_key, bool p_isPressed);

  bool hasToChangeDirection(void) const;
  void changeDirection(void);

  void walk(bool p_leftLeg = true);
  bool canWalk(void) const;
  void updateMapping();

private:
  sf::RenderWindow m_window;

  sf::Texture m_playerTexture;
  sf::Sprite m_player;

  sf::Texture m_backgroundTexture;
  sf::Sprite m_background;

  PlayerDirection m_playerDirection;

  bool m_isMovingUp;
  bool m_isMovingDown;
  bool m_isMovingLeft;
  bool m_isMovingRight;

  bool m_isLeftLeg;

  Mapping m_mapping;
};

#endif // GAME_H
