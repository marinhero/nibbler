//
// Surface.hh for nibbler in /Users/Marin/EPITECH/c++/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:34:40 2013 Marin Alcaraz
// Last update Fri Mar 22 19:07:06 2013 Marin Alcaraz
//

#ifndef _SURFACE_H
# define _SURFACE_H

#include "Game.hh"

class Surface
{

    point_t     bounds;

    public:
        Surface();
        Surface(const &Surface);
       ~Surface();
        int operator=(const &Surface);
        bool check_space(point_t);
        *point_t  get_bounds(void) const;
};

#endif
