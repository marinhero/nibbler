//
// Food.hh for nibbler in /Users/Marin/EPITECH/c++/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:44:11 2013 Marin Alcaraz
// Last update Fri Mar 22 23:02:11 2013 Marin Alcaraz
//

#ifndef _FOOD_HH
# define _FOOD_HH

#include  <cstdlib>
#include "Game.hh"

class Food
{
    public:
         Food();
         Food(const Food &f);
         ~Food();
         int operator=(const Food &f);
         point_t    f;
         bool       try_eat(size_t, point_t);
         void       gen_food(void);
         point_t    *get_food(void);
};

#endif
