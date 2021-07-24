#include <MazePointMut.hh>

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      MazePointMut::MazePointMut(uint8_t x, uint8_t y) noexcept {
         this->x = x;
         this->y = y;
      }
      
      uint8_t MazePointMut::getX() const noexcept {
         return this->x;
      }

      uint8_t MazePointMut::getY() const noexcept {
         return this->y;
      }

      MazePointMut& MazePointMut::setX(uint8_t x) noexcept {
         this->x = x;
         return *this;
      }

      MazePointMut& MazePointMut::setY(uint8_t x) noexcept {
         this->y = y;
         return *this;
      }

      MazePointMut& MazePointMut::set(uint8_t x, uint8_t y) noexcept {
         this->x = x;
         this->y = y;
         return *this;
      }
      
      MazePointMut::~MazePointMut() = default;

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi
