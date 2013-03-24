//
// Food.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 02:24:06 2013 ivan ignatiev
// Last update Sun Mar 24 15:19:16 2013 ivan ignatiev
//

#include "Food.hh"

Food::Food(void)
{
}

Food::Food(Snake const *snake, Surface const *surface)
    : snake_(snake), surface_(surface)
{
  this->gen_food();
}

Food::Food(const Food &f)
{
    (void) f;
}
Food::~Food(void)
{
}

Food &Food::operator=(const Food &f)
{
    (void) f;
    return (*this);
}

bool       Food::try_eat(point_t head, size_t &size)
{
  if (head.x == this->food.x && head.y == this->food.y)
  {
    size++;
    this->gen_food();
    return (true);
  }
  return (false);
}

void       Food::gen_food(void)
{
    int     w   =       this->surface_->get_width();
    int     h   =       this->surface_->get_height();

    this->food.x    = rand() % (w - 1) + 1;
    this->food.y    = rand() % (h - 1) + 1;
    this->food.type = F_FOOD;
    while (!this->surface_->check_space(this->food) ||
           this->snake_->colition(this->food)
        )
    {
        this->food.x    = rand() % (w - 1) + 1;
        this->food.y    = rand() % (h - 1) + 1;
    }
}

point_t  const  *Food::get_food(void) const
{
    return (&food);
}

