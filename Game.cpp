//
// Game.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 20:33:45 2013 ivan ignatiev
// Last update Sat Mar 23 02:28:15 2013 ivan ignatiev
//

#include "Game.hh"

Game::Game()
{
}

Game::Game(Game const &g)
{
    (void) g;
}

Game &Game::operator=(Game const &g)
{
    (void) g;
    return (*this);
}

Game::Game(int width, int height)
    : width_(width), height_(height)
{
    this->surface_ = new Surface(width, height);
    this->snake_ = new Snake(this->surface_);
    this->food_ = new Food(this->snake_, this->surface_);
    this->snake_->set_food(this->food_);
    this->field_ = new Field(this->snake_, this->surface_, this->food_);
}

Game::~Game()
{
    delete this->field_;
    delete this->food_;
    delete this->snake_;
    delete this->surface_;
}

bool    Game::left(void)
{
    bool result = this->snake_->left();
    return (result);
}

bool    Game::right(void)
{
    bool result = this->snake_->right();
    return (result);
}

bool    Game::move(void)
{
    bool result = this->snake_->move();
    this->field_->generate();
    return (result);
}

void    Game::quit(void)
{
}

field_object_t  **Game::get_field(void) const
{
    return (this->field_->get_field());
}

void    Game::regen_food(void)
{
    this->food_->gen_food();
    this->field_->generate();
}

int         Game::get_width(void) const
{
    return (this->width_);
}

int         Game::get_height(void) const
{
    return (this->height_);
}
