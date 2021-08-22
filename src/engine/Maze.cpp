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

      bool Maze::getRandomUnvisitedNeighboringPointUnsafe(MazePointMut& point) noexcept {
         const int numberOfDirection = 4;
         int numberOfParticipant = 0;
         // TOP, RIGHT, BOTTOM, LEFT
         bool isInCompetition[numberOfDirection] = {false, false, false, false};
         // TOP
         if (point.getY() < this->size.getHeight() - 1 && mazeCell::isNotVisited(this->getCellUnsafe(point.getX(), point.getY() + 1))) {
            isInCompetition[0] = true;
            ++numberOfParticipant;
         }
         // RIGHT
         if (point.getX() < this->size.getWidth() - 1 && mazeCell::isNotVisited(this->getCellUnsafe(point.getX() + 1, point.getY()))) {
            isInCompetition[1] = true;
            ++numberOfParticipant;
         }
         // BOTTOM
         if (point.getY() != 0 && mazeCell::isNotVisited(this->getCellUnsafe(point.getX(), point.getY() - 1))) {
            isInCompetition[2] = true;
            ++numberOfParticipant;
         }
         // LEFT
         if (point.getX() != 0 && mazeCell::isNotVisited(this->getCellUnsafe(point.getX() - 1, point.getY()))) {
            isInCompetition[3] = true;
            ++numberOfParticipant;
         }
         if (numberOfParticipant == 0) {
            return false;
         }
         int random = std::rand() % numberOfParticipant;
         int indexOfTrues = 0;
         int randomDirection = 0;
         for (int randomDirection = 0; randomDirection < numberOfDirection; ++randomDirection) {
            if (isInCompetition[randomDirection]) {
               if (random == indexOfTrues) {
                  break;
               } else {
                  ++indexOfTrues;
               }
            }
         }
         switch (randomDirection) {
            case 0: // TOP
               this->bitwiseOrAssignment_Unsafe(point, mazeCell::VISITED_FROM_BOTTOM);
               point.setY( point.getY() + 1 );
               break;
            case 1: // RIGHT
               this->bitwiseOrAssignment_Unsafe(point, mazeCell::VISITED_FROM_LEFT);
               point.setX( point.getX() + 1 );
               break;
            case 2: // BOTTOM
               this->bitwiseOrAssignment_Unsafe(point, mazeCell::VISITED_FROM_TOP);
               point.setY( point.getY() - 1 );
               break;
            case 3: // LEFT
               this->bitwiseOrAssignment_Unsafe(point, mazeCell::VISITED_FROM_RIGHT);
               point.setX( point.getX() - 1 );
               break;
            default:
               break;
         }
         return true;
      }

      Maze::~Maze() {
         delete this->mazeData;
      }

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi
