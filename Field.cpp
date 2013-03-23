//
// Field.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 01:02:33 2013 ivan ignatiev
// Last update Sat Mar 23 15:18:49 2013 ivan ignatiev
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
    this->matrix_ = new field_object_t * [this->height_ + 1];
    for (int i = 0; i <= this->width_; ++i)
    {
        this->matrix_[i] = new field_object_t[this->width_ + 1];
        for (int j = 0; j <= this->height_; ++j)
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

void    Field::empty_matrix(void)
{
    for (int i = 0; i <= this->width_; ++i)
    {
        for (int j = 0; j <= this->height_; ++j)
        {
            this->matrix_[i][j] = F_EMPTY;
        }
    }
}

void    Field::generate(void)
{
    std::vector<point_t>::const_iterator snake = this->snake_->get_snake().begin();
    std::vector<point_t>::const_iterator snake_end  = this->snake_->get_snake().end();

    this->empty_matrix();
    for (;snake != snake_end; ++snake)
    {
        this->matrix_[snake->y][snake->x] = snake->type;
    }

    point_t const *food  = this->food_->get_food();

    this->matrix_[food->y][food->x] = food->type;

    std::vector<point_t>::const_iterator walls = this->surface_->get_bounds().begin();
    std::vector<point_t>::const_iterator walls_end = this->surface_->get_bounds().end();

    for (;walls != walls_end; ++walls)
    {
        this->matrix_[walls->y][walls->x] = walls->type;
    }
}

field_object_t  **Field::get_field(void) const
{
    return (this->matrix_);
}
