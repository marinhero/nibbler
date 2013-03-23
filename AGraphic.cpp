//
// AGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Sat Mar 23 02:40:28 2013 ivan ignatiev
// Last update Sat Mar 23 02:43:00 2013 ivan ignatiev
//

#include "AGraphic.hh"

AGraphic::AGraphic(void)
{

}

AGraphic::AGraphic(Game *game)
    : game_(game)
{
}

AGraphic::AGraphic(AGraphic const &ag)
{
    (void) ag;
}

AGraphic &AGraphic::operator=(AGraphic const &ag)
{
    (void) ag;
    return (*this);
}

AGraphic::~AGraphic(void)
{
}

Game *AGraphic::game(void)
{
    return (this->game_);
}
