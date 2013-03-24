/*
** QTGraphic.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 19:11:09 2013 ivan ignatiev
** Last update Fri Mar 22 19:13:33 2013 ivan ignatiev
*/

#ifndef QTGRAPHIC_H_
# define QTGRAPHIC_H_

# include <iostream>
# include <unistd.h>

# include "AGraphic.hh"

class QTGraphic : public AGraphic
{
    public:
        QTGraphic(Game *);
        virtual ~QTGraphic(void);
        virtual void refresh(void);
        virtual void wait(void);
};

#endif /* !QTGRAPHIC_H_ */
