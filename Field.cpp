//
// Field.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 01:02:33 2013 ivan ignatiev
// Last update Sat Mar 23 01:14:32 2013 ivan ignatiev
//

#include "Field.hh"

Field::Field(void)
{

}

Field(Snake const *snake, Surface const *surface, Food const *food)
    : snake_(snake), surface_(surface), food_(food)
{
    this->width_ = surface->get_width();
    this->height_ = surface->get_heiht();
    for (int i = 0; i < this->width_; ++i)
    {
        for (int j = 0; j < this->height_; ++j)
        {
            matrix[i][j] = F_EMPTY;
        }
    }
}

Field &Filed:::operator=(Field const &f)
{
    (void) f;
    return (*this);
}

Filed::Filed(Filed const &f)
{
    (void) f;
}

Filed::~Filed(void)
{
}

void    Field::generate(void)
{
    std::vector<point_t>::const_iterator snake = this->snake_->get_snake().begin();
    std::vector<point_t>::const_iterator end  = this->shake_->get_snake().end();

    for (;snake != end; ++snake)
    {
        this->matrix_[*snake.y][*snake.x] = *snake.type;
    }
}

filed_object const **get_field(void) const
{
    return (this->matrix_);
}
