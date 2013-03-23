//
// Snake.cpp for nibbler in /home/hero/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:52:37 2013 Marin Alcaraz
// Last update Sat Mar 23 14:59:28 2013 Marin Alcaraz
//

#include "Snake.hh"

Snake :: Snake(Surface const *surface)
    : size(4), direction(X_POS), surface_(surface)
{
     std::vector<point_t> b;
     point_t    var;

     var.x = 10;
     var.y = 10;
     var.type = F_SNAKE_SECT;
     body = b;
     while(var.x < 4)
     {
        body.push_back(var);
        var.x++;
     }
     var.type = F_SNAKE_HEAD;
     body.push_back(var);
     std::cout << "Created Snake. Head on X: "<< var.x  << " Y: "<< var.y  << " size 4 " << std::endl;
}

Snake :: Snake(const Snake &obj) : body(obj.body), size(obj.size) {}

Snake :: ~Snake() {}

void  Snake :: set_direction(direction_t dir)
{
    this->direction = dir;
}

direction_t Snake :: get_direction() const
{
    return (this->direction);
}

bool        Snake :: left(void)
{
    if ((this->get_direction() == X_POS) || (this->get_direction() == X_NEG))
        this->set_direction(Y_POS);
    if ((this->get_direction() == Y_POS) || (this->get_direction() == Y_NEG))
        this->set_direction(X_NEG);
    return (true);
}

bool        Snake :: right(void)
{
    if ((this->get_direction() == X_POS) || (this->get_direction() == X_NEG))
        this->set_direction(Y_NEG);
    if ((this->get_direction() == Y_POS) || (this->get_direction() == Y_NEG))
        this->set_direction(X_POS);
    return (true);
}

bool        Snake :: move(void)
{
    size_t      i;

    for(i = 0; i <= this->get_size(); i++)
    {
        body[i].x = body[i + 1].x;
        body[i].y = body[i + 1].y;
        if (body[this->get_size() - 1].x > this->surface_->get_width() || body[this->get_size() - 1].y > this->surface_->get_height())
            return (false);
    }
    return (true);
}

std::vector<point_t> const &Snake :: get_snake(void) const
{
    return (this->body);
}

size_t      Snake :: get_size(void)
{
    return (this->size);
}

void        Snake :: set_food(Food const *food)
{
    this->food_ = food;
}
