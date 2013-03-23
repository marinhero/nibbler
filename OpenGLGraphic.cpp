//
// OpenGLGraphic.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sat Mar 23 16:36:57 2013 ivan ignatiev
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

  c = 0;
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(this->game()->get_width(), this->game()->get_height());
  glutInitWindowPosition(0,0);
  glutCreateWindow("Snake");
  glutKeyboardFunc(keyboard);

  InitializeGlutCallbacks();
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

void keyboard(unsigned char key)
{
  switch(key)
  {
    case GLUT_KEY_LEFT:
      this->game()->left();
      break;
    case GLUT_KEY_RIGHT:
      this->game()->right();
      break;
    case GLUT_KEY_END:
      this->game()->quit();
      break;
  }
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
}

