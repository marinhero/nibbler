//
// GTKGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sat Mar 23 03:03:41 2013 ivan ignatiev
//

# include "GTKGraphic.hh"

extern "C" AGraphic *load_graphic(Game *game)
{
    return (new GTKGraphic(game));
}

extern "C" void     unload_graphic(AGraphic *glib)
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
    field_object_t **field = this->game()->get_field();
    int     w   = this->game()->get_width();
    int     h   = this->game()->get_height();

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            switch(field[i][j])
            {
                case F_EMPTY :
                    std::cout << ".";
                    break;
                case F_SNAKE_SECT:
                    std::cout << "+";
                    break;
                case F_SNAKE_HEAD:
                    std::cout << "@";
                    break;
            }
        }
        std::cout << std::endl;
    }
}
