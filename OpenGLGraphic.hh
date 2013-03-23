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

class OpenGLGraphic : public AGraphic
{
  public:
    OpenGLGraphic(Game *);
    virtual ~OpenGLGraphic(void);
    virtual void refresh(void);
    void renderSceneCB(void);
    void InitializeGlutCallbacks(void);

};

void keyboard(unsigned char, int, int);

#endif /* !OPENGLGRAPHIC_HH_ */
