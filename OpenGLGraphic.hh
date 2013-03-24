/*
** OpenGLGraphic.h for nibbler in /home/baezse_s/nibbler
**
** Made by Sergio Baez
** Login   <baezse_s@epitech.net>
**
** Started on  Fri Mar 22 20:45:44 2013 Sergio Baez
** Last update Fri Mar 22 20:45:54 2013 Sergio Baez
*/

#ifndef OPENGLGRAPHIC_HH_
# define OPENGLGRAPHIC_HH_

# include "AGraphic.hh"
# define CELL_SIZE 20

class OpenGLGraphic : public AGraphic
{
    int                 width_;
    int                 height_;
    int                 pix_width_;
    int                 pix_height_;

  public:
    OpenGLGraphic(Game *);
    virtual ~OpenGLGraphic(void);
    virtual void refresh(void);
    virtual void wait(void);
    void draw_rect(float x1, float y1, float x2, float y2);

};

void keyboard(int, int, int);
void render(void);
void idle(void);

#endif /* !OPENGLGRAPHIC_HH_ */
