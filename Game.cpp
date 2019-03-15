//
// Created by Jakob on 15.03.2019.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Game.h"

using Sep::Game;

Game::Game()
{
  board_width_ = 0;
  board_height_ = 0;
  map_ = new char *[board_height_];
}

void Game::loadConfig(std::string cfg_file)
{
  std::ifstream config(cfg_file.c_str());
  std::string line;
  int lineCount = 0;
  while (std::getline(config, line))
  {
    if (line.empty() || (line != "#SWORMS" && line.at(0) == '#'))
    {
      continue;
    }
    if (lineCount == 0 && line != "#SWORMS")
    {
      std::cout << "[ERROR] invalid config file" << std::endl;
      return;
    }
    lineCount++;
    std::cout << line << std::endl;
  }
}

void Game::addWorm(int row, int col)
{

}

void Game::printMap()
{

}

void Game::move(int row, int col, int steps)
{

}

Game::~Game()
{

}

int main(void)
{
  Sep::Game game;
  game.loadConfig("config");
  return 0;
}

