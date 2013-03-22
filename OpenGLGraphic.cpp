//
// OpenGLGraphic.cpp for nibbler in /home/baezse_s/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Fri Mar 22 21:39:46 2013 Sergio Baez
//

# include <GL/freeglut.h>
# include "OpenGLGraphic.hh"

extern "C" AGraphic     *load_graphic(Game *game)
{
  return (new OpenGLGraphic(game));
}

extern "C" void         *unload_graphic(AGraphic *glib)
{
  delete glib;
}

OpenGLGraphic::OpenGLGraphic(Game *game) : AGraphic(game)
{
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

static void RenderSceneCB()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
  glutDisplayFunc(RenderSceneCB);
}

void OpenGLGraphic::refresh(void)
{
  int   c;

  c = 0;
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Snake");

  InitializeGlutCallbacks();
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glutMainLoop();
}

