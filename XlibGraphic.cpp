//
// XLibGraphic.cpp for nibbler in /home/hero/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:16:19 2013 ivan ignatiev
// Last update Sun Mar 24 10:19:08 2013 Marin Alcaraz
//

# include "XlibGraphic.hh"

extern "C" AGraphic *load_graphic(Game *game)
{
    return (new XlibGraphic(game));
}

extern "C" void     unload_graphic(AGraphic *glib)
{
    delete glib;
}

XlibGraphic::XlibGraphic(Game *game) : AGraphic(game)
{
    this->width_        = game->get_width();
    this->height_       = game->get_height();
    this->pix_width_    = this->width_ * CELL_SIZE + CELL_SIZE;
    this->pix_height_   = this->height_ * CELL_SIZE + CELL_SIZE;
    this->init_colors();
	dis = XOpenDisplay(NULL);
	win = XCreateSimpleWindow(dis, RootWindow(dis, 0), 1, 1,
        this->pix_width_, this->pix_height_ , 0, BlackPixel (dis, 0), BlackPixel(dis, 0));
	XMapWindow(dis, win);
	colormap = DefaultColormap(dis, 0);
    for (int i = 0; i < 5; i = i + 1)
    {
      xgc[i] = XCreateGC(dis, win, 0, 0);
      XParseColor(dis, colormap, colors[i], &pal[i]);
      XAllocColor(dis, colormap, &pal[i]);
      XSetForeground(dis, xgc[i], pal[i].pixel);
    }
	XSelectInput(dis, win, ExposureMask | KeyPressMask | LeaveWindowMask);
}

XlibGraphic::~XlibGraphic(void)
{
}

void    XlibGraphic::init_colors(void)
{
  this->colors[0] = strdup("#00FF00");
  this->colors[1] = strdup("#FFFFFF");
  this->colors[2] = strdup("#FF0000");
  this->colors[3] = strdup("#FFAA00");
  this->colors[4] = strdup("#00C9FF");
}

void    XlibGraphic::wait(void)
{
	while (1)  {
      XNextEvent(dis, &report);
      switch  (report.type)
      {
        case ClientMessage:
            throw(new LibraryException("Window closed"));
        case KeyPress:
          if (XLookupKeysym(&report.xkey, 0) == XK_q)
            this->game()->quit();
          if (XLookupKeysym(&report.xkey, 0) == XK_Left)
            this->game()->left();
          if (XLookupKeysym(&report.xkey, 0) == XK_Right)
            this->game()->right();
          break;
      }
	}
}

void    XlibGraphic::draw_rect(int x1, int y1, int x2, int y2, GC color)
{
	XDrawRectangle(dis, win, color, x1, y1, x2, y2);
    XFillRectangle(dis, win, color, x1, y1, x2, y2);
}

void    XlibGraphic::refresh(void)
{
    field_object_t  **field = this->game()->get_field();
    int     x1;
    int     x2;
    int     y1;
    int     y2;

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
                    this->draw_rect(x1, y1, x2, y2, xgc[4]);
                    break;
                case F_SNAKE_SECT:
                    this->draw_rect(x1, y1, x2, y2, xgc[0]);
                    break;
                case F_FOOD:
                    this->draw_rect(x1, y1, x2, y2, xgc[3]);
                    break;
                case F_WALL:
                    this->draw_rect(x1, y1, x2, y2, xgc[1]);
                    break;
                case F_SNAKE_HEAD:
                    this->draw_rect(x1, y1, x2, y2, xgc[2]);
                    break;
            }
        }
    }
	XFlush(dis);
}
