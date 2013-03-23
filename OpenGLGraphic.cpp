//
// OpenGLGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sat Mar 23 16:52:18 2013 ivan ignatiev
//

# include <GL/freeglut.h>
# include "OpenGLGraphic.hh"

extern "C" AGraphic     *load_graphic(Game *game)
{
  return (new OpenGLGraphic(game));
}

extern "C" void         unload_graphic(AGraphic *glib)
{
  delete glib;
}

OpenGLGraphic::OpenGLGraphic(Game *game) : AGraphic(game)
{
  int   c;
  int   w;
  int   h;

  c = 0;
  w = this->game()->get_width();
  h = this->game()->get_height();
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(w, h);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Snake");
  glutKeyboardFunc(keyboard);

  InitializeGlutCallbacks();
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

void keyboard(unsigned char key, int x, int y)
{
  (void)x;
  (void)y;

  switch(key)
  {
    case GLUT_KEY_LEFT:

      break;
    case GLUT_KEY_RIGHT:
      this->game()->right();
      break;
    case GLUT_KEY_END:
      this->game()->quit();
      break;
  }
}

void OpenGLGraphic::renderSceneCB()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

void OpenGLGraphic::InitializeGlutCallbacks()
{
  glutDisplayFunc(this->renderSceneCB);
}

void OpenGLGraphic::refresh(void)
{
}

