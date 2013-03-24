//
// Surface.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 02:32:13 2013 ivan ignatiev
// Last update Sun Mar 24 16:10:04 2013 ivan ignatiev
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
    if (p.x >= this->get_width() || p.x < 1)
      return (false);
    if (p.y >= this->get_height() || p.y < 1)
      return (false);
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

