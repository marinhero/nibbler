//
// GTKGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sat Mar 23 16:48:03 2013 ivan ignatiev
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
    int     c = 0;
    gtk_init(&c, NULL);
    this->window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(this->window_), "Nibbler");
    g_signal_connect(this->window_, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(this->window_);
}

GTKGraphic::~GTKGraphic(void)
{

}

void GTKGraphic::wait(void)
{
    gtk_main();
}

void GTKGraphic::refresh(void)
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

    /*char c;
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
    read(1, &c, 1);*/
}
