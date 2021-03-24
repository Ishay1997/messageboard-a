#include <array>
#include <iostream>
#include "Direction.hpp"
#include <string>

namespace ariel {
        class Board{
            public  : 
            Board();
           static std::string read(unsigned int row, unsigned int col, Direction d, unsigned int length);
            void post(unsigned int row, unsigned int col, Direction direction, const std::string &str);
            void show();
        };
 }