#ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZECELL_HH
#define MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZECELL_HH

#include <cstdint>         // uint8_t

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      namespace mazeCell {

         /*!
         * \brief Клетка лабиринта.
         * 
         * Младшие 4 бита служат для хранения информации об окружающих стенках:
         *    - бит 0 установлен тогда и только тогда, когда имеется верхняя
         * стенка
         *    - бит 1 установлен тогда и только тогда, когда имеется правая
         * стенка
         *    - бит 2 установлен тогда и только тогда, когда имеется нижняя
         * стенка
         *    - бит 3 установлен тогда и только тогда, когда имеется левая
         * стенка
         * 
         * Старшие 4 бита использует генератор лабиринтов:
         *    - бит 4 установлен тогда и только тогда, когда генератор пришел в
         * эту клетку снизу
         *    - бит 5 установлен тогда и только тогда, когда генератор пришел в
         * эту клетку слева
         *    - бит 6 установлен тогда и только тогда, когда генератор пришел в
         * эту клетку сверху
         *    - бит 7 установлен тогда и только тогда, когда генератор пришел в
         * эту клетку справа
         */
         typedef uint8_t MazeCell;

         /*!
          * \brief У клетки присутствует верхняя стенка.
          */
         constexpr MazeCell TOP_WALL = 0b1 << 0;

         /*!
          * \brief У клетки присутствует правая стенка.
          */
         constexpr MazeCell RIGHT_WALL = 0b1 << 1;

         /*!
          * \brief У клетки присутствует нижняя стенка.
          */
         constexpr MazeCell BOTTOM_WALL = 0b1 << 2;

         /*!
          * \brief У клетки присутствует левая стенка.
          */
         constexpr MazeCell LEFT_WALL = 0b1 << 3;

         /*!
          * \brief У клетки присутствуют все четыре стенки.
          */
         constexpr MazeCell ALL_WALLS = TOP_WALL | RIGHT_WALL | BOTTOM_WALL | LEFT_WALL;

         /*!
          * \brief Генератор пришел в клетку снизу.
          */
         constexpr MazeCell VISITED_FROM_BOTTOM = 0b1 << 4;

         /*!
          * \brief Генератор пришел в клетку слева.
          */
         constexpr MazeCell VISITED_FROM_LEFT = 0b1 << 5;

         /*!
          * \brief Генератор пришел в клетку сверху.
          */
         constexpr MazeCell VISITED_FROM_TOP = 0b1 << 6;

         /*!
          * \brief Генератор пришел в клетку справа.
          */
         constexpr MazeCell VISITED_FROM_RIGHT = 0b1 << 7;

         /*!
          * \brief Посетил ли генератор эту клетку?
          * 
          * \param[in] cell клетка лабиринта
          * 
          * \return посетил ли генератор эту клетку
          */
         bool isNotVisited(MazeCell cell) noexcept;

      } // namespace mazeCell

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi

#endif // #ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZECELL_HH
