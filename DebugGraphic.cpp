//
// DebugGraphic.cpp for nibbler in /home/hero/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sun Mar 24 09:16:14 2013 Marin Alcaraz
//

# include "DebugGraphic.hh"

extern "C" AGraphic *load_graphic(Game *game)
{
    return (new DebugGraphic(game));
}

extern "C" void     unload_graphic(AGraphic *glib)
{
    delete glib;
}

DebugGraphic::DebugGraphic(Game *game) : AGraphic(game)
{

}

DebugGraphic::~DebugGraphic(void)
{

}

void DebugGraphic::refresh(void)
{
    field_object_t **field = this->game()->get_field();
    int     w   = this->game()->get_width();
    int     h   = this->game()->get_height();

    std::cout << "Current position : " << std::endl;

    for (int i = 0; i <= h; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            switch(field[i][j])
            {
                case F_EMPTY :
                    std::cout << ".";
                    break;
                case F_SNAKE_SECT:
                    std::cout << "+";
                    break;
                case F_FOOD:
                    std::cout << "$";
                    break;
                case F_WALL:
                    std::cout << "#";
                    break;
                case F_SNAKE_HEAD:
                    std::cout << "@";
                    break;
            }
        }
        std::cout << std::endl;
    }

    char c;
    read(1, &c , 1);
    switch(c)
    {
        case 'l':
            this->game()->left();
            break;
        case 'r':
            this->game()->right();
            break;
        case 'q':
            this->game()->quit();
            exit(0);
            break;
        case 's' :
            break;
    }
    read(1, &c, 1);
}

void DebugGraphic::wait(void)
{

}
