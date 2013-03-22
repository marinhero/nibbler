//
// Snake.hh for nibbler in /Users/Marin/EPITECH/c++/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:00:51 2013 Marin Alcaraz
// Last update Fri Mar 22 19:34:03 2013 Marin Alcaraz
//

#ifndef _SNAKE_H
# define _SNAKE_H

#include "Food.hh"
#include "Surface.hh"
#include "Game.hh"

class Snake
{
    point_t     body;
    size_t      size(); //should be 4 by default

    public:
        Snake(Food *f, Surface *s);
        Snake(const &Snake);
        ~Snake();
        int         operator=(const &Snake);
        bool        left(void);
        bool        right(void);
        bool        move(void);
        point_t     *get_snake(void) const;
        size_t      get_size(void);
};

#endif
