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

#  include  "Field.hh"
#  include  "Surface.hh"
#  include  "Food.hh"
#  include  "Snake.hh"

typedef enum field_object_t
{
  F_EMPTY = 0,
  F_SNAKE_HEAD,
  F_SNAKE_SECT,
  F_WALL,
  F_FOOD
};

typedef struct point_s
{
  int               x;
  int               y;
  field_object_t    type;
};

class Game
{
  protected:
    Field       field;
    Surface     surface;
    Snake       snake;
    Food        food;
  public:
    Game();
    Game(const int width, const int heigth);
    Game(const Game &_other);
    virtual ~Game();
    bool            left(void);
    bool            right(void);
    bool            move(void);
    void            quit(void);
    field_object_t  get_field(void);
    void            regen_food(void);
};

#endif /* !GAME_HH_ */
