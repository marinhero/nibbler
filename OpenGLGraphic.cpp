//
// OpenGLGraphic.cpp for nibbler in /home/baezse_s/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sat Mar 23 17:11:49 2013 Sergio Baez
//

# include <GL/freeglut.h>
# include "OpenGLGraphic.hh"

AGraphic                *graph;

extern "C" AGraphic     *load_graphic(Game *game)
{
  graph = new OpenGLGraphic(game);
  return (graph);
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
      graph->game()->left();
      break;
    case GLUT_KEY_RIGHT:
      graph->game()->right();
      break;
    case GLUT_KEY_END:
      graph->game()->quit();
      break;
  }
}

void renderSceneCB()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

void OpenGLGraphic::InitializeGlutCallbacks()
{
  glutDisplayFunc(renderSceneCB);
}

void OpenGLGraphic::refresh(void)
{
}

