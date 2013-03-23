//
// GTKGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sun Mar 24 00:33:12 2013 ivan ignatiev
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
    int     w   = game->get_width() * CELL_SIZE;
    int     h   = game->get_height() * CELL_SIZE;

    gtk_init(&c, NULL);
    gdk_threads_init();
    this->window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(this->window_), "Nibbler");

    g_signal_connect(this->window_, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(this->window_, "key_press_event", G_CALLBACK(GTKGraphic::on_key_press), this);

    gtk_window_set_default_size(GTK_WINDOW(this->window_),  w, h);

    this->da_ = gtk_drawing_area_new();
    gtk_widget_set_size_request(this->da_, w, h);
    gtk_container_add(GTK_CONTAINER(this->window_), this->da_);
    gtk_widget_show_all(this->window_);

    this->surface_ = gdk_window_create_similar_surface( gtk_widget_get_window(this->da_),
                                                        CAIRO_CONTENT_COLOR,
                                                        gtk_widget_get_allocated_width(this->da_),
                                                        gtk_widget_get_allocated_height(this->da_));

}

GTKGraphic::~GTKGraphic(void)
{
    cairo_surface_destroy(this->surface_);
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
    gdk_threads_enter();
    cairo_t    *cr = cairo_create( this->surface_ );
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
                    cairo_rectangle(cr, j * CELL_SIZE, i * CELL_SIZE,
                                        j * CELL_SIZE + CELL_SIZE,
                                        i * CELL_SIZE + CELL_SIZE);
                    cairo_fill(cr);
                    cairo_stroke(cr);

                    std::cout << ".";
                    break;
                case F_SNAKE_SECT:
                    cairo_set_source_rgb(cr, 1, 0.5, 1);
                    cairo_set_line_width(cr, 2);
                    cairo_rectangle(cr, j * CELL_SIZE, i * CELL_SIZE,
                                        j * CELL_SIZE + CELL_SIZE,
                                        i * CELL_SIZE + CELL_SIZE);
                    cairo_fill(cr);
                    cairo_stroke(cr);

                    std::cout << "+";
                    break;
                case F_FOOD:
                    cairo_set_source_rgb(cr, 1, 0.5, 0.4);
                    cairo_set_line_width(cr, 3);
                    cairo_rectangle(cr, j * CELL_SIZE, i * CELL_SIZE,
                                        j * CELL_SIZE + CELL_SIZE,
                                        i * CELL_SIZE + CELL_SIZE);
                    cairo_fill(cr);
                    cairo_stroke(cr);

                    std::cout << "$";
                    break;
                case F_WALL:
                    cairo_set_source_rgb(cr, 0.5, 1, 0.4);
                    cairo_set_line_width(cr, 4);
                    cairo_rectangle(cr, j * CELL_SIZE, i * CELL_SIZE,
                                        j * CELL_SIZE + CELL_SIZE,
                                        i * CELL_SIZE + CELL_SIZE);
                    cairo_fill(cr);
                    cairo_stroke(cr);

                    std::cout << "#";
                    break;
                case F_SNAKE_HEAD:
                    cairo_set_source_rgb(cr, 0.5, 0.5, 1);
                    cairo_set_line_width(cr, 5);
                    cairo_rectangle(cr, j * CELL_SIZE, i * CELL_SIZE,
                                        j * CELL_SIZE + CELL_SIZE,
                                        i * CELL_SIZE + CELL_SIZE);
                    cairo_fill(cr);
                    cairo_stroke(cr);
                    std::cout << "@";
                    break;
            }
        }
        std::cout << std::endl;
    }

    cairo_set_source_surface(cr, this->surface_, 0, 0);
    cairo_paint(cr);
    cairo_destroy(cr);
    cr = gdk_cairo_create( gtk_widget_get_window (this->da_));
    cairo_set_source_surface(cr, this->surface_, 0, 0);
    cairo_paint(cr);
    gdk_threads_leave();
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

gboolean       GTKGraphic::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
    AGraphic *th    = static_cast<AGraphic*>(data);

    switch(event->keyval)
    {
        case    GDK_KEY_Left:
                th->game()->left();
                break;
        case    GDK_KEY_Right:
                th->game()->right();
                break;
        case    GDK_KEY_Escape:
                th->game()->quit();
                exit(0);
                break;
    }

    return (TRUE);
}
