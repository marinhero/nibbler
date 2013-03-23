//
// Field.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 01:02:33 2013 ivan ignatiev
// Last update Sat Mar 23 02:38:06 2013 ivan ignatiev
//

#include "Field.hh"

Field::Field(void)
{

}

Field::Field(Snake const *snake, Surface const *surface, Food const *food)
    : snake_(snake), surface_(surface), food_(food)
{
    this->width_ = surface->get_width();
    this->height_ = surface->get_height();
    this->matrix_ = new field_object_t * [this->height_];
    for (int i = 0; i < this->width_; ++i)
    {
        this->matrix_[i] = new field_object_t[this->width_];
        for (int j = 0; j < this->height_; ++j)
        {
            this->matrix_[i][j] = F_EMPTY;
        }
    }
}

Field &Field::operator=(Field const &f)
{
    (void) f;
    return (*this);
}

Field::Field(Field const &f)
{
    (void) f;
}

Field::~Field(void)
{
}

void    Field::generate(void)
{
    std::vector<point_t>::const_iterator snake = this->snake_->get_snake().begin();
    std::vector<point_t>::const_iterator end  = this->snake_->get_snake().end();

    for (;snake != end; ++snake)
    {
        this->matrix_[snake->y][snake->x] = snake->type;
    }
}

field_object_t  **Field::get_field(void) const
{
    return (this->matrix_);
}
