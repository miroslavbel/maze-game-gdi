#include <Maze.hh>

#include <cstring> // memset

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      Maze::Maze(MazeSize& size, MazePointMut& startPoint) : size(size.getWidth(), size.getHeight()), startPoint(startPoint.getX(), startPoint.getY()) {
         if (this->startPoint.getX() >= this->size.getWidth() || this->startPoint.getY() >= this->size.getHeight()) {
            throw std::out_of_range("Start point must be valid.");
         }
         this->mazeData = new mazeCell::MazeCell[this->size.getWidth() * this->size.getHeight()];
         std::memset(this->mazeData,  mazeCell::ALL_WALLS, this->size.getArea());
         // TODO: generate maze
      }

      mazeCell::MazeCell Maze::getCellUnsafe(uint8_t x, uint8_t y) const noexcept {
         return this->mazeData[ static_cast<uint16_t>(this->size.getWidth()) * static_cast<uint16_t>(y) + static_cast<uint16_t>(x) ];
      }

      void Maze::bitwiseOrAssignment_Unsafe(MazePointMut& point, mazeCell::MazeCell cell) noexcept {
         this->mazeData[static_cast<uint16_t>(this->size.getWidth()) * static_cast<uint16_t>(point.getY()) + point.getX()] |= cell;
      }

      Maze::~Maze() {
         delete this->mazeData;
      }

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi
