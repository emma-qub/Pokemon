#include "Game.h"

#include <iostream>

#include <SFML/Window/Event.hpp>

Game::Game(void) :
  m_window(sf::VideoMode(10*3*16, 9*3*16), "Pokemon"),
  m_playerTexture(),
  m_player(),
  m_playerDirection(PlayerDirection::Down),
  m_isMovingUp(false),
  m_isMovingDown(false),
  m_isMovingLeft(false),
  m_isMovingRight(false),
  m_isLeftLeg(true) {

  if (!m_playerTexture.loadFromFile("../Pokemon/resources/characters/red.png"))
    std::cerr << "Error: cannot load player." << std::endl;
  m_player.setTexture(m_playerTexture);
  m_player.setPosition(4*3*16.f, 4*3*16.f-3*4.f);
  m_player.setTextureRect(sf::IntRect(4*16, 0, 16, 16));
  m_player.setScale(3.f, 3.f);

  if (!m_backgroundTexture.loadFromFile("../Pokemon/resources/maps/NewBarkTown.png"))
    std::cerr << "Error: cannot load player." << std::endl;
  m_background.setTexture(m_backgroundTexture);
  m_background.setPosition(-9*32.f, 0.f);
  m_background.setScale(3.f, 3.f);
}

void Game::run(void) {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time TimePerFrame = sf::seconds(1.f / 30.f);

  while (m_window.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      if (m_isMovingUp || m_isMovingDown || m_isMovingLeft || m_isMovingRight) {
        if (hasToChangeDirection()) {
          changeDirection();
          render();
          for(int k = 0; k < 10; ++k) {
            walk();
            render();
          }
          changeDirection();
          render();
          m_isMovingUp = false;
          m_isMovingDown = false;
          m_isMovingLeft = false;
          m_isMovingRight = false;
        } else {
          for (int k = 0; k < 12; ++k) {
            update();
            render();
          }
          for(int k = 0; k < 10; ++k) {
            walk(m_isLeftLeg);
            update();
            render();
          }
          for (int k = 0; k < 2; ++k) {
            changeDirection();
            update();
            render();
          }
        }
        m_isLeftLeg = !m_isLeftLeg;
      } else {
        update();
        render();
      }
    }
  }
}

void Game::processEvents(void) {
  sf::Event event;
  while(m_window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      m_window.close();
      break;
    default:
      break;
    }
  }
}

void Game::update(void) {
  sf::Vector2f mouvement(0.f, 0.f);

  float playerSpeed = 2.f;

  if (m_isMovingUp)
    mouvement.y += playerSpeed;
  if (m_isMovingDown)
    mouvement.y -= playerSpeed;
  if (m_isMovingLeft)
    mouvement.x += playerSpeed;
  if (m_isMovingRight)
    mouvement.x -= playerSpeed;

  m_background.move(mouvement);
}

void Game::render(void) {
  m_window.clear();
  m_window.draw(m_background);
  m_window.draw(m_player);
  m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key p_key, bool p_isPressed) {
  if (p_key  == sf::Keyboard::Up)
    m_isMovingUp = p_isPressed;
  else if (p_key  == sf::Keyboard::Down)
    m_isMovingDown = p_isPressed;
  else if (p_key  == sf::Keyboard::Left)
    m_isMovingLeft = p_isPressed;
  else if (p_key  == sf::Keyboard::Right)
    m_isMovingRight = p_isPressed;
}

bool Game::hasToChangeDirection(void) const {
  return !((m_playerDirection == PlayerDirection::Down && m_isMovingDown)
      || (m_playerDirection == PlayerDirection::Up && m_isMovingUp)
      || (m_playerDirection == PlayerDirection::Left && m_isMovingLeft)
      || (m_playerDirection == PlayerDirection::Right && m_isMovingRight));
}

void Game::changeDirection(void) {
  if (m_isMovingDown) {
    m_player.setTextureRect(sf::IntRect(4*16, 0, 16, 16));
    m_playerDirection = PlayerDirection::Down;
  } else if (m_isMovingUp) {
    m_player.setTextureRect(sf::IntRect(7*16, 0, 16, 16));
    m_playerDirection = PlayerDirection::Up;
  } else if (m_isMovingLeft) {
    m_player.setTextureRect(sf::IntRect(2*16, 0, 16, 16));
    m_playerDirection = PlayerDirection::Left;
  } else if (m_isMovingRight) {
    m_player.setTextureRect(sf::IntRect(0*16, 0, 16, 16));
    m_playerDirection = PlayerDirection::Right;
  }
}

void Game::walk(bool leftLeg) {
  if (m_isMovingDown) {
    if (leftLeg)
      m_player.setTextureRect(sf::IntRect(5*16, 0, 16, 16));
    else
      m_player.setTextureRect(sf::IntRect(6*16, 0, 16, 16));
  } else if (m_isMovingUp) {
    if (leftLeg)
      m_player.setTextureRect(sf::IntRect(8*16, 0, 16, 16));
    else
      m_player.setTextureRect(sf::IntRect(9*16, 0, 16, 16));
  } else if (m_isMovingLeft) {
    m_player.setTextureRect(sf::IntRect(3*16, 0, 16, 16));
  } else if (m_isMovingRight) {
    m_player.setTextureRect(sf::IntRect(1*16, 0, 16, 16));
  }
}
