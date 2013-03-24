//
// Snake.hh for nibbler in /home/hero/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:00:51 2013 Marin Alcaraz
// Last update Sat Mar 23 23:57:18 2013 Marin Alcaraz
//

#ifndef _SNAKE_H
# define _SNAKE_H

#include <vector>
#include <iostream>

class Snake;

#include "Game.hh"
#include "Food.hh"
#include "Surface.hh"

class Snake
{
    std::vector<point_t>    body;
    size_t                  size;
    direction_t             direction;

    Surface const           *surface_;
    Food               *food_;

    public:
        Snake(Surface const *s);
        Snake(const Snake &s);
        ~Snake();
        Snake&                          operator=(const Snake &s);
        bool                            left(void);
        bool                            right(void);
        bool                            move(void);
        bool                            colition(point_t);
        bool                            move_body(void);
        std::vector<point_t> const      &get_snake(void) const;
        size_t                          get_size(void);
        direction_t                     get_direction() const;
        void                            set_direction(direction_t);
        void                            set_food(Food *);
};

#endif
