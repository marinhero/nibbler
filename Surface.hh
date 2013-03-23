//
// Surface.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:34:40 2013 Marin Alcaraz
// Last update Sat Mar 23 01:33:13 2013 ivan ignatiev
//

#ifndef _SURFACE_H
# define _SURFACE_H

class Surface;

#include <vector>
#include "Game.hh"

class Surface
{
    int                     width_;
    int                     height_;
    std::vector<point_t>     bounds_;
    field_object_t          **surface_;

    Surface(void);
    public:
        Surface(int width, int height);
        Surface(Surface const &s);
       ~Surface(void);
        Surface &operator=(Surface const &s);
        bool check_space(point_t const &p) const;

        std::vector<point_t>  const &get_bounds(void) const;
        int     get_width(void) const;
        int     get_height(void) const;
};

#endif
