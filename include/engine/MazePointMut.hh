#ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZEPOINTMUT_HH
#define MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZEPOINTMUT_HH

#include <cstdint>         // uint8_t

namespace miroslavbel_maze_game_gdi {

   namespace engine {

      /*!
       * \brief Точка лабиринта.
       */
      struct MazePointMut {
         
            /*!
            * \brief X-координата точки.
            */
            uint8_t x;

            /*!
            * \brief Y-координата точки.
            */
            uint8_t y;

         public:

            /*!
            * \brief Конструктор.
            *
            * \param[in] x x-координата точки
            * \param[in] y y-координата точки
            */
            MazePointMut(uint8_t x, uint8_t y) noexcept;

            /*!
             * \brief Возвращает x-координату точки.
             * 
             * \return x-координата точки
             */
            uint8_t getX() const noexcept;

            /*!
             * \brief Возвращает y-координату точки.
             * 
             * \return y-координата точки
             */
            uint8_t getY() const noexcept;

            /*!
             * \brief Устанавливает x-координату точки.
             * 
             * \param[in] x x-координата точки
             * 
             * \return ссылка на экземпляр
             */
            MazePointMut& setX(uint8_t x) noexcept;

            /*!
             * \brief Устанавливает y-координату точки.
             * 
             * \param[in] y y-координата точки
             * 
             * \return ссылка на экземпляр
             */
            MazePointMut& setY(uint8_t x) noexcept;

            /**
             * \brief Устанавливает координаты точки.
             * 
             * \param[in] x x-координата точки
             * \param[in] y y-координата точки
             * 
             * \return ссылка на экземпляр
             */
            MazePointMut& set(uint8_t x, uint8_t y) noexcept;

            /*!
             * \brief Деструктор.
             */
            ~MazePointMut() noexcept;
      };

   } // namespace engine

} // namespace miroslavbel_maze_game_gdi

#endif // #ifndef MIROSLAVBEL_MAZE_GAME_GDI_ENGINE_MAZEPOINTMUT_HH
