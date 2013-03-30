/*
** GTKGraphic.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 19:11:09 2013 ivan ignatiev
** Last update Fri Mar 22 19:13:33 2013 ivan ignatiev
*/

#ifndef XLIBGRAPHIC_H_
# define XLIBGRAPHIC_H_

# include <iostream>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <cstring>

# include "AGraphic.hh"
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>
# include "Exception.hh"

# define CELL_SIZE 20

char                colors[5][8] = {"#00FF00", "#FFFFFF", "#FF0000", "#FFAA00", "#00C9FF"};

class XlibGraphic : public AGraphic
{
    int                 width_;
    int                 height_;
    int                 pix_width_;
    int                 pix_height_;
    Display             *dis;
    Window              win;
    XEvent              report;
    GC                  xgc[5];
    XColor              pal[5];
    Colormap            colormap;

    void                draw_rect(int x1, int y1, int x2, int y2, GC color);
    public:
        XlibGraphic(Game *);
        virtual ~XlibGraphic(void);
        virtual void                refresh(void);
        virtual void                wait(void);
};

#endif /* !XLIBGRAPHIC_H_ */
