/*
** GTKGraphic.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 19:11:09 2013 ivan ignatiev
** Last update Fri Mar 22 19:13:33 2013 ivan ignatiev
*/

#ifndef GTKGRAPHIC_H_
# define GTKGRAPHIC_H_

# include "AGraphic.hh"

class GTKGraphic : public AGraphic
{
    public:
        GTKGraphic(Game *);
        virtual ~GTKGraphic(void);
        virtual refresh(void);
};

#endif /* !GTKGRAPHIC_H_ */
