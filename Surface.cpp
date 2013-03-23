//
// Surface.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 02:32:13 2013 ivan ignatiev
// Last update Sat Mar 23 02:35:30 2013 ivan ignatiev
//

#include "Surface.hh"

Surface::Surface(void)
{
}

Surface::Surface(int width, int height)
    : width_(width), height_(height)
{

}

Surface::Surface(Surface const &s)
{
    (void) s;
}

Surface::~Surface(void)
{
}

Surface &Surface::operator=(Surface const &s)
{
    (void) s;
    return (*this);
}

bool Surface::check_space(point_t const &p) const
{
    (void) p;
    return (true);
}

std::vector<point_t>  const &Surface::get_bounds(void) const
{
    return (this->bounds_);
}

int     Surface::get_width(void) const
{
    return (this->width_);
}

int     Surface::get_height(void) const
{
    return (this->height_);
}

