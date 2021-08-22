#ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZE_HH
#define MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZE_HH

#include <stdexcept>       // out_of_range

#include <MazeSize.hh>     // MazeSize
#include <MazePointMut.hh> // MazePointMut
#include <MazeCell.hh>     // MazeCell

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      /*!
       * \brief Лабиринт.
       */
      class Maze {

            /*!
             * \brief Размер лабиринта.
             *
             * \warning Treat as const (except at constructor and destructor).
             */
            MazeSize size;

            /*!
             * \brief Начальная точка (используется генератором).
             *
             * \warning Treat as const (except at constructor and destructor).
             */
            MazePointMut startPoint;

            /*!
             * \brief Клетки лабиринта.
             */
            mazeCell::MazeCell* mazeData;

            /*!
             * \brief Возвращает клетку по заданным координатам.
             *
             * \warning Координаты клетки должны быть валидными.
             * 
             * \param[in] x x-координата клетки
             * \param[in] y y-координата клетки
             * 
             * \return запрашиваемая клетка
             */
            mazeCell::MazeCell getCellUnsafe(uint8_t x, uint8_t y) const noexcept;

            /*!
             * \brief Применяет маску \a cell к клетке лабиринта, находящейся
             * по координатам \a point.
             *
             * \warning Если \a point не является валидной точкой лабиринта, то
             * поведение не определенно.
             * 
             * \param[in] point валидная точка лабиринта
             * \param[in] cell маска
             */
            void bitwiseOrAssignment_Unsafe(MazePointMut& point, mazeCell::MazeCell cell) noexcept;

            /*!
             * \brief Случайным образом выбирает соседнюю еще непосещенную
             * генератором клетку.
             * 
             * Если такой клетки не существует, то вернет \a false. Иначе
             * вернет \a true и запишет в \a point координаты найденной
             * клетки, а также запишет в старую клетку информацию о направление
             * движения.
             * 
             * \note Как генератор псевдослучайных чисел использует
             * \a std::rand. А значит, хорошо бы чтоб \a std::srand уже была
             * вызвана.
             * 
             * \param[in,out] point валидная точка
             * 
             * \return удалось ли найти соседнюю еще непосещенную клетку
             */
            bool getRandomUnvisitedNeighboringPointUnsafe(MazePointMut& point) noexcept;

         public:

            /*!
             * \brief Конструктор.
             * 
             * Генерирует лабиринт заданного размера. Начинает генерацию с
             * точки, указанной в \a startPoint.
             * 
             * \param[in] size размер лабиринта
             * \param[in] startPoint начальная точка
             * 
             * \throw std::out_of_range - если \a startPoint лежит за пределами
             * лабиринта.
             */
            Maze(MazeSize& size, MazePointMut& startPoint);

            /*!
             * \brief Деструктор.
             */
            ~Maze();

      };

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi

#endif // #ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZE_HH
