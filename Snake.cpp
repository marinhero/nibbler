//
// Snake.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:52:37 2013 Marin Alcaraz
// Last update Sat Mar 23 02:30:40 2013 ivan ignatiev
//

#include "Snake.hh"

Snake :: Snake(Surface const *surface)
    : size(4), direction(X_POS), surface_(surface)
{
     std::vector<point_t> b;
     point_t    var;

     var.x = 1;
     var.y = 1;
     var.type = F_SNAKE_HEAD;
     body = b;
     while(var.x < 5)
     {
        body.push_back(var);
        var.type = F_SNAKE_SECT;
        var.x++;
        var.y++;
     }
     std::cout << "Created Snake X: "<< var.x - 1 << " Y: "<< var.y - 1 << " size 4 " << std::endl;
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
    int     i;

    for(i = 0; i <= this->get_size(); i++)
    {
        body[i].x = body[i-1].x;
        body[i].y = body[i-1].y;
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
