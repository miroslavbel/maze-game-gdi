#include <MazeCell.hh>         // uint8_t

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      namespace mazeCell {

         inline bool isNotVisited(MazeCell cell) noexcept {
            return cell >> 4 == 0 ? true : false;
         }

      } // namespace mazeCell

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi
