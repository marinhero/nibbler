/*
** AGraphic.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 18:36:59 2013 ivan ignatiev
** Last update Fri Mar 22 18:54:32 2013 ivan ignatiev
*/

#ifndef AGRAPHIC_H_
# define AGRAPHIC_H_

#include "Game.hh"

class   AGraphic
{
    private:
        Game    *game_;

        AGraphic(void);
    public:
        AGraphic(Game *game);
        AGraphic(AGraphic const &glib);
        AGraphic &operator(AGraphic const &glib);

        virtual ~AGraphic(void);
        virtual refresh(void) = 0;
        Game *game(void);
};

#endif /* !AGRAPHIC_H_ */
