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
          * \brief Посетил ли генератор эту клетку?
          * 
          * \param[in] cell клетка лабиринта
          * 
          * \return посетил ли генератор эту клетку
          */
         inline bool isNotVisited(MazeCell cell) noexcept;

      } // namespace mazeCell

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi

#endif // #ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZECELL_HH
