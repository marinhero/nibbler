/*
** Game.h for nibbler in /Users/sabs231/Documents/EPITECH/Classes/C++/Projects/Nibbler/nibbler
**
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
**
** Started on  Fri Mar 22 18:37:56 2013 sergioandres baezserrano
** Last update Fri Mar 22 18:38:03 2013 sergioandres baezserrano
*/

#ifndef GAME_HH_
#  define GAME_HH_

# include <cstdlib>
# include <ctime>

typedef enum{
  F_EMPTY = 0,
  F_SNAKE_HEAD,
  F_SNAKE_SECT,
  F_WALL,
  F_FOOD
}  field_object_t;

typedef enum
{
    X_POS = 0,
    X_NEG,
    Y_POS,
    Y_NEG
} direction_t;

typedef struct point_s
{
  int               x;
  int               y;
  field_object_t    type;
} point_t;

class Game;

#  include  "Field.hh"
#  include  "Surface.hh"
#  include  "Food.hh"
#  include  "Snake.hh"

class Game
{
    Field               *field_;
    Surface             *surface_;
    Snake               *snake_;
    Food                *food_;
    int                 width_;
    int                 height_;

    Game();
    Game &operator=(Game const &);
    Game(const Game &_other);
  public:
    Game(int width, int heigth);
    ~Game();
    bool            left(void);
    bool            right(void);
    bool            move(void);
    void            quit(void);
    field_object_t  **get_field(void) const;
    void            regen_food(void);
    int             get_width() const;
    int             get_height() const;
};

#endif /* !GAME_HH_ */
