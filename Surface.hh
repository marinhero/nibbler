//
// Surface.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:34:40 2013 Marin Alcaraz
// Last update Fri Mar 22 21:00:55 2013 ivan ignatiev
//

#ifndef _SURFACE_H
# define _SURFACE_H

#include <vector>
#include "Game.hh"

class Surface
{
    int                     width;
    int                     height;
    std::vector<point_t>     bounds_;
    field_object_t          **surface_;

    public:
        Surface(int width, int height);
        Surface(Surface const &);
       ~Surface();
        Surface &operator=(Surface const &);
        bool check_space(point_t);

        std::vector<point_t>  const &get_bounds(void) const;
        int     get_width() const;
        int     get_height() const;
};

#endif
