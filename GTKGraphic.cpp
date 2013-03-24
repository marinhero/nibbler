//
// GTKGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sun Mar 24 18:00:32 2013 ivan ignatiev
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
    gdk_threads_init();
    this->window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(this->window_), "Nibbler");

    g_signal_connect(this->window_, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(this->window_, "key_press_event", G_CALLBACK(GTKGraphic::on_key_press), this);
    this->width_        = game->get_width();
    this->height_       = game->get_height();
    this->pix_width_    = this->width_ * CELL_SIZE + CELL_SIZE;
    this->pix_height_   = this->height_ * CELL_SIZE + CELL_SIZE;
    gtk_window_set_default_size(GTK_WINDOW(this->window_),  this->pix_width_, this->pix_height_);
    this->da_ = gtk_drawing_area_new();
    gtk_widget_set_size_request(this->da_, this->pix_width_, this->pix_height_);
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

void    GTKGraphic::draw_rect(int x1, int y1, int x2, int y2)
{
    cairo_set_line_width(this->cr_, 1);
    cairo_rectangle(this->cr_, x1, y1, x2, y2);
    cairo_fill(this->cr_);
    cairo_stroke(this->cr_);
}

void    GTKGraphic::cairo_color(double r, double g, double b)
{
    cairo_set_source_rgb(this->cr_, r, g, b);
}

void    GTKGraphic::prepare_cairo(void)
{
    this->surface_ = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, this->pix_width_, this->pix_height_);
    this->cr_ = cairo_create( this->surface_);
    cairo_set_source_rgb(this->cr_, 1, 1, 1);
    cairo_paint(this->cr_);
}

void    GTKGraphic::destroy_cairo(void)
{
    cairo_set_source_surface(this->cr_, this->surface_, 0, 0);
    cairo_paint(this->cr_);
    cairo_destroy(this->cr_);
    this->cr_ = gdk_cairo_create( gtk_widget_get_window (this->da_));
    cairo_set_source_surface(this->cr_, this->surface_, 0, 0);
    cairo_paint(this->cr_);
    cairo_destroy(this->cr_);
    cairo_surface_destroy(this->surface_);
}

void    GTKGraphic::refresh(void)
{
    field_object_t  **field = this->game()->get_field();
    int     x1;
    int     x2;
    int     y1;
    int     y2;

    gdk_threads_enter();
    this->prepare_cairo();
    for (int i = 0; i <= this->height_; ++i)
    {
        for (int j = 0; j <= this->width_; ++j)
        {
            x1 = j * CELL_SIZE;
            y1 = i * CELL_SIZE;
            x2 = j * CELL_SIZE + CELL_SIZE;
            y2 = i * CELL_SIZE + CELL_SIZE;
            switch(field[i][j])
            {
                case F_EMPTY :
                    this->cairo_color(0, 0.5, 0);
                    this->draw_rect(x1, y1, x2, y2);
                    break;
                case F_SNAKE_SECT:
                    this->cairo_color(0.5, 0.5, 0.5);
                    this->draw_rect(x1, y1, x2, y2);
                    break;
                case F_FOOD:
                    this->cairo_color(0.5, 0.5, 1);
                    this->draw_rect(x1, y1, x2, y2);
                    break;
                case F_WALL:
                    this->cairo_color(0, 0, 0);
                    this->draw_rect(x1, y1, x2, y2);
                    break;
                case F_SNAKE_HEAD:
                    this->cairo_color(1, 0.2, 0.2);
                    this->draw_rect(x1, y1, x2, y2);
                    break;
            }
        }
    }
    this->destroy_cairo();
    gdk_threads_leave();
}

gboolean       GTKGraphic::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
    AGraphic *th    = static_cast<AGraphic*>(data);

    (void) widget;
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
                break;
    }

    return (TRUE);
}
