#ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZESIZE_HH
#define MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZESIZE_HH

#include <cstdint>         // uint8_t
#include <stdexcept>       // out_of_range

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      /*!
       * \brief Размеры лабиринта.
       */
      class MazeSize {
         
            /*!
            * \brief Ширина лабиринта в клетках.
            *
            * Больше нуля.
            * 
            * \warning Treat as const (except at constructor and destructor).
            */
            uint8_t width;

            /*!
            * \brief Высота лабиринта в клетках.
            *
            * Больше нуля.
            *
            * \warning Treat as const (except at constructor and destructor).
            */
            uint8_t height;

         public:

            /*!
            * \brief Ширина лабиринта в клетках.
            *
            * Больше нуля.
            */
            uint8_t getWidth() const noexcept;

            /*!
            * \brief Высота лабиринта в клетках.
            * 
            * Больше нуля.
            */
            uint8_t getHeight() const noexcept;

            /*!
            * \brief Конструктор.
            *
            * \param[in] width ширина лабиринта в клетках
            * \param[in] height высота лабиринта в клетках
            * 
            * \throws std::out_of_range если \a width и/или \a height равно(-ы)
            * \a 0
            */
            MazeSize(uint8_t width, uint8_t height);

            /*!
             * \brief Деструктор.
             */
            ~MazeSize();
      };

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi

#endif // #ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZESIZE_HH
