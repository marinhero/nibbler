//
// Snake.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 19:52:37 2013 Marin Alcaraz
// Last update Sun Mar 24 18:13:19 2013 ivan ignatiev
//

#include "Snake.hh"

Snake :: Snake(Surface const *surface)
    : size(4), direction(X_POS), surface_(surface)
{
     std::vector<point_t> b;
     point_t    var;

     var.x = 1;
     var.y = 1;
     var.type = F_SNAKE_SECT;
     body = b;
     while(var.x < 4)
     {
        body.push_back(var);
        var.x++;
     }
     var.type = F_SNAKE_HEAD;
     body.push_back(var);
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
    if ((this->get_direction() == X_POS))
    {
        this->set_direction(Y_POS);
        return (true);
    }
    if ((this->get_direction() == X_NEG))
    {
        this->set_direction(Y_NEG);
        return (true);
    }
    if ((this->get_direction() == Y_POS) || (this->get_direction() == Y_NEG))
    {
        this->set_direction(X_NEG);
        return (true);
    }
    return (false);
}

bool        Snake :: right(void)
{
    if (this->get_direction() == X_POS)
    {
        this->set_direction(Y_NEG);
        return (true);
    }
    if (this->get_direction() == X_NEG)
    {
        this->set_direction(Y_POS);
        return (true);
    }
    if ((this->get_direction() == Y_POS) || (this->get_direction() == Y_NEG))
    {
        this->set_direction(X_POS);
        return (true);
    }
    return (false);
}

bool            Snake :: move_body(void)
{
    int         head;

    head = get_size() - 1;
    for (int i = 0; i <= head - 1; ++i)
    {
        body[i] = body[i + 1];
        body[i].type = F_SNAKE_SECT;
    }
    return (true);
}

bool            Snake :: colition(point_t head) const
{
    std::vector<point_t>::const_iterator it = this->body.begin();
    std::vector<point_t>::const_iterator snake_end = this->body.end();

    for (; it != snake_end; ++it)
    {
        if (it->x == head.x && it->y == head.y)
          return (true);
    }
    return (false);
}

bool            Snake :: move(void)
{
    int         head;
    point_t     nh;

    head = this->get_size() - 1;
    nh = body[head];
    switch (this->get_direction())
    {
      case  X_POS: nh.x++; break;
      case  Y_POS: nh.y--; break;
      case  X_NEG: nh.x--; break;
      case  Y_NEG: nh.y++; break;
      default: return (false);
    }
    if (!surface_->check_space(body[head]) || colition(nh))
      return (false);
    if (food_->try_eat(nh, this->size))
    {
      body[head].type = F_SNAKE_SECT;
      body.push_back(nh);
      return (true);
    }
    move_body();
    body[head] = nh;
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

void        Snake :: set_food(Food *food)
{
    this->food_ = food;
}
