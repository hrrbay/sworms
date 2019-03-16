//
// Created by Jakob on 15.03.2019.
//

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "Game.h"

using Sep::Game;

Game::Game()
{
  board_width_ = 0;
  board_height_ = 0;
  map_ = new char *[board_height_];
}

int Game::loadConfig(std::string cfg_file)
{
  std::ifstream config(cfg_file.c_str());
  std::string line;
  int lineCount = 0;
  while (std::getline(config, line))
  {
    if (line.empty() || (line != "#SWORMS" && line.at(0) == '#' && !lineCount)
        || (line.at(0) == '#' && lineCount))
    {
      continue;
    }
    if (lineCount == 0 && line != "#SWORMS")
    {
      std::cout << "[ERROR] invalid config file" << std::endl;
      return -1;
    }

    //check if size is given
    if (lineCount == 1)
    {
      std::regex size_regex("\\s*SIZE:(\\s+([1-7][0-9])|80]){2}\\s*");
      if(!regex_match(line, size_regex))
      {
        std::cout << "[ERROR] invalid config file" << std::endl;
        return -1;
      }

      board_width_ = 40;
      board_height_ = 10;
    }

    //check for map
    if (lineCount == 2)
    {
      std::regex map_regex("\\s*MAP:\\s*");
      if(!regex_match(line, map_regex))
      {
        std::cout << "[ERROR] invalid config file" << std::endl;
        return -1;
      }
    }

    if (lineCount > 2)
    {
      std::string regex_str;
      regex_str.append("(A|E|W|\\s){");
      regex_str.append(std::to_string(board_width_));
      regex_str.append("}");
      std::regex field_regex(regex_str);

      if(!regex_match(line, field_regex))
      {
        std::cout << "[ERROR] invalid config file" << std::endl;
      }
    }
    if (lineCount > board_height_ + 3) {
      std::cout << "[ERROR] invalid config file" << std::endl;
      return -1;
    }

    //check for fields

    lineCount++;
    std::cout << line << std::endl;
  }
  return 0;
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
  game.loadConfig("config_invalid");
  return 0;
}
