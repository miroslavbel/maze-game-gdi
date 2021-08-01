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
