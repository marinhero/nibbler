//
// GTKGraphic.cpp for nibbler in /home/baezse_s/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Fri Mar 22 20:57:48 2013 Sergio Baez
//

# include "GTKGraphic.hh"

extern "C" AGraphic *load_graphic(Game *game)
{
    return (new GTKGraphic(game));
}

extern "C" void     *unload_graphic(AGraphic *glib)
{
    delete glib;
}

GTKGraphic::GTKGraphic(Game *game) : AGraphic(game)
{

}

GTKGraphic::~GTKGraphic(void)
{

}

void GTKGraphic::refresh(void)
{

}
