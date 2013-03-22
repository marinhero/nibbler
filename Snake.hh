//
// Snake.hh for nibbler in /Users/Marin/EPITECH/c++/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:00:51 2013 Marin Alcaraz
// Last update Fri Mar 22 23:10:32 2013 Marin Alcaraz
//

#ifndef _SNAKE_H
# define _SNAKE_H

#include <vector>

class Snake;

#include "Game.hh"
#include "Food.hh"
#include "Surface.hh"

class Snake
{
    std::vector<point_t>    body;
    size_t                  size; //should be 4 by default

    public:
        Snake(Food const *f, Surface const *s);
        Snake(const Snake &s);
        ~Snake();
        Snake&                             operator=(const Snake &s);
        bool                            left(void);
        bool                            right(void);
        bool                            move(void);
        std::vector<point_t> const      &get_snake(void) const;
        size_t                          get_size(void);
};

#endif
