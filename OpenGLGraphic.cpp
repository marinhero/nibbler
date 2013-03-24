//
// OpenGLGraphic.cpp for nibbler in /home/baezse_s/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sun Mar 24 19:03:21 2013 Sergio Baez
//

# include <iostream>
# include <GL/glew.h>
# include <GL/freeglut.h>
# include "OpenGLGraphic.hh"
# include "math_3d.h"

AGraphic                *graph;
GLuint                  VBO;

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
  GLenum res;

  c = 0;
  w = this->game()->get_width();
  h = this->game()->get_height();
  this->width_ = this->game()->get_width();
  this->height_ = this->game()->get_height();
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(w, h);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Nibbler");
  glutKeyboardFunc(keyboard);
  InitializeGlutCallbacks();
  res = glewInit();
  if (res != GLEW_OK)
  {
    std::cerr   << "Error"
                << glewGetErrorString(res)
                << std::endl;
    exit(0); //TODO-->exceptions
  }
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

void OpenGLGraphic::draw_rect(int x1, int y1, int x2, int y2)
{
  glRectf(x1, y1, x2, y2);
}

void render(void)
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
  field_object_t    **field = this->game()->get_field();
  int     x1;
  int     x2;
  int     y1;
  int     y2;

  if (glutGetWindowData() == NULL)
    std::cout << "algo" << std::endl;
  for (int i = 0; i <= this->height_; i++)
  {
    for (int j = 0; j <= this->width_; j++)
    {
      x1 = j * CELL_SIZE;
      y1 = i * CELL_SIZE;
      x2 = j * CELL_SIZE + CELL_SIZE;
      y2 = i * CELL_SIZE + CELL_SIZE;
      switch(field[i][j])
      {
        case F_EMPTY:
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          glColor3f(0.0f, 0.5f, 0.0f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_SNAKE_SECT:
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          glColor3f(0.5f, 0.5f, 0.5f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_FOOD:
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          glColor3f(0.5f, 0.5f, 1.0f);
          this->draw_rect(x1, y1,1.0, y2);
          break;
        case F_WALL:
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          glColor3f(0.0f, 0.0f, 0.0f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_SNAKE_HEAD:
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          glColor3f(1.0f, 0.2f, 0.2f);
          this->draw_rect(x1, y1, x2, y2);
          break;
      }
    }
  }
  glutSwapBuffers();
}

void OpenGLGraphic::wait(void)
{
    glutMainLoop();
}

