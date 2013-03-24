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
# define CELL_SIZE 0.2f

class OpenGLGraphic : public AGraphic
{
    int                 width_;
    int                 height_;

  public:
    OpenGLGraphic(Game *);
    virtual ~OpenGLGraphic(void);
    virtual void refresh(void);
    virtual void wait(void);
    void InitializeGlutCallbacks(void);
    void draw_rect(int x1, int y1, int x2, int y2);

};

void keyboard(unsigned char, int, int);
void renderSceneCB(void);
void render(void);

#endif /* !OPENGLGRAPHIC_HH_ */
