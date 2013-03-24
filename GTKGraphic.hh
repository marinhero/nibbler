/*
** GTKGraphic.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 19:11:09 2013 ivan ignatiev
** Last update Fri Mar 22 19:13:33 2013 ivan ignatiev
*/

#ifndef GTKGRAPHIC_H_
# define GTKGRAPHIC_H_

# include <iostream>
# include <unistd.h>

# include <gtk/gtk.h>
# include <gdk/gdk.h>
# include "AGraphic.hh"

# define CELL_SIZE 20

class GTKGraphic : public AGraphic
{
    GtkWidget           *window_;
    GtkWidget           *da_;
    cairo_surface_t     *surface_;
    cairo_t             *cr_;
    int                 width_;
    int                 height_;
    int                 pix_width_;
    int                 pix_height_;

    void                clear_surface(void);
    static gboolean     on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data);
    static gboolean     on_window_close(void);
    void                destroy_cairo(void);
    void                prepare_cairo(void);
    void                cairo_color(double r, double g, double b);
    void                draw_rect(int x1, int y1, int x2, int y2);

    public:
        GTKGraphic(Game *);
        virtual ~GTKGraphic(void);
        virtual void refresh(void);
        virtual void wait(void);
};

#endif /* !GTKGRAPHIC_H_ */
