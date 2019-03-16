//
// Created by Jakob on 15.03.2019.
//

#include <string>
#ifndef SWORMS_GAME_H
#define SWORMS_GAME_H

namespace Sep
{
  class Game
  {
    public:
      Game();
      int loadConfig(std::string cfg_file);
      void addWorm(int row, int col);
      void printMap();
      void move(int row, int col, int steps);
      virtual ~Game();
    private:
      int board_width_;

      int board_height_;

      char** map_;
  };
}

#endif //SWORMS_GAME_H
