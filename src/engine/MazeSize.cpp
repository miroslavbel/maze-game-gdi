#include <MazeSize.hh>

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      MazeSize::MazeSize(uint8_t width, uint8_t height) {
         if (width == 0) {
            throw std::out_of_range("Width must be greater then zero.");
         }
         if (height == 0) {
            throw std::out_of_range("Height must be greater then zero.");
         }
         this->width = width;
         this->height = height;
      }

      uint8_t MazeSize::getWidth() const noexcept {
         return this->width;
      }

      uint8_t MazeSize::getHeight() const noexcept {
         return this->height;
      }
      
      MazeSize::~MazeSize() = default;

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi
