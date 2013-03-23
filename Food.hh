//
// Food.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:44:11 2013 Marin Alcaraz
// Last update Sat Mar 23 14:20:17 2013 ivan ignatiev
//

#ifndef _FOOD_HH
# define _FOOD_HH

# include    <cstdlib>

class   Food;

# include    "Game.hh"
# include    "Snake.hh"
# include    "Surface.hh"

class   Food
{
    Snake   const   *snake_;
    Surface const   *surface_;

    point_t         food;

    Food(void);
    public:
         Food(Snake const *, Surface const *);
         Food(const Food &f);
         ~Food(void);
         Food &operator=(const Food &f);

         bool       try_eat(point_t head, size_t &size) const;
         void       gen_food(void);
         point_t  const  *get_food(void) const;
};

#endif
