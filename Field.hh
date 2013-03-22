//
// Field.hh for nibbler in /Users/Marin/EPITECH/c++/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Mar 22 18:55:10 2013 Marin Alcaraz
// Last update Fri Mar 22 19:07:22 2013 Marin Alcaraz
//

#ifndef _FIELD_H
# define _FIELD_H

#include "Surface.hh"
#include "Snake.hh"
#include "Food.hh"
#include "Game.hh"

class Field
{
    field_object_T  matrix;
    public:
           Field();
           Field(const &Field);
           ~Field();
           int              operator=(const &Field);
           field_object_T   generate() const;
};

#endif
