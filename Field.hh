//
// Field.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:55:10 2013 Marin Alcaraz
// Last update Fri Mar 22 20:57:23 2013 ivan ignatiev
//

#ifndef _FIELD_H
# define _FIELD_H

#include "Surface.hh"
#include "Snake.hh"
#include "Food.hh"
#include "Game.hh"

class Field
{
    field_object_t  **matrix;
    Field();
    public:
           Field(Snake const *s, Surface const *sur, Food const *f);
           Field &operator=(Field const &);
           Field(const &Field);
           ~Field();

           void   generate(void);
           field_object_t const **get_field(void) const;
};

#endif
