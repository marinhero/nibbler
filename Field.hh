//
// Field.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:55:10 2013 Marin Alcaraz
// Last update Sat Mar 23 01:15:11 2013 ivan ignatiev
//

#ifndef _FIELD_H
# define _FIELD_H

class Field;

# include "Surface.hh"
# include "Snake.hh"
# include "Food.hh"
# include "Game.hh"

class Field
{
    Snake const     *snake_;
    Surface const   *surface_;
    Food const      *food_;
    field_object_t  **matrix_;
    int             width_;
    int             height_;

    Field(void);
    public:
           Field(Snake const *s, Surface const *sur, Food const *f);
           Field &operator=(Field const &f);
           Field(Field const &f);
           ~Field(void);

           void                 generate(void);
           field_object_t const **get_field(void) const;
};

#endif
