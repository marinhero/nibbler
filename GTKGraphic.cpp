//
// GTKGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sat Mar 23 22:13:36 2013 ivan ignatiev
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
    int     w   = game->get_width() * CELL_SIZE + 200;
    int     h   = game->get_height() * CELL_SIZE + 200;

    gtk_init(&c, NULL);
    this->window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(this->window_), "Nibbler");
    g_signal_connect(this->window_, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_default_size(GTK_WINDOW(this->window_),  w, h);

    this->da_ = gtk_drawing_area_new();
    gtk_widget_set_size_request(this->da_, w, h);
    gtk_container_add(GTK_CONTAINER(this->window_), this->da_);
    gtk_widget_show_all(this->window_);
}

GTKGraphic::~GTKGraphic(void)
{

}

void    GTKGraphic::clear_surface(void)
{
}

void    GTKGraphic::wait(void)
{
    gtk_main();
}

void    GTKGraphic::refresh(void)
{
    field_object_t **field = this->game()->get_field();
    int     w   = this->game()->get_width();
    int     h   = this->game()->get_height();

    std::cout << "Current position : " << std::endl;
    this->clear_surface();
    cairo_t    *cr = gdk_cairo_create( gtk_widget_get_window(this->da_) );
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    for (int i = 0; i <= h; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            switch(field[i][j])
            {
                case F_EMPTY :
                    cairo_set_source_rgb(cr, 0.5, 0.5, 0.4);
                    cairo_set_line_width(cr, 1);
                    cairo_rectangle(cr, 0, 0, 150, 150);
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

     cairo_stroke(cr);
     cairo_destroy(cr);


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
