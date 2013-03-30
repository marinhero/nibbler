//
// OpenGLGraphic.cpp for nibbler-2016-alcara_m in /home/ignati_i/projects/nibbler-2016-alcara_m
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sun Mar 24 22:27:05 2013 ivan ignatiev
//

# include <iostream>
# include <GL/freeglut.h>
# include "OpenGLGraphic.hh"
# include "Exception.hh"
# include "math_3d.h"

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
  this->pix_width_ = w * CELL_SIZE + CELL_SIZE;
  this->pix_height_ = h * CELL_SIZE + CELL_SIZE;
  this->width_ = this->game()->get_width();
  this->height_ = this->game()->get_height();
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(this->pix_width_, this->pix_height_);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Nibbler");
  glViewport(0, 0, this->pix_width_, this->pix_height_);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, this->pix_width_, 0, this->pix_height_);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(skeyboard);
  glutIdleFunc(idle);
  glutDisplayFunc(render);
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

void OpenGLGraphic::draw_rect(float x1, float y1, float x2, float y2)
{
  glRectf(x1, this->pix_height_ - y1, x2, this->pix_height_ - y2);
}

void keyboard(unsigned char key, int x, int y)
{
    (void) x;
    (void) y;

    switch (key)
    {
      case 27:
        graph->game()->quit();
    }
}

void skeyboard(int key, int x, int y)
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
  }
}

void idle(void)
{
  glutPostRedisplay();
}

void OpenGLGraphic::refresh(void)
{
  field_object_t    **field = this->game()->get_field();
  int     x1;
  int     x2;
  int     y1;
  int     y2;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
          glColor3f(0.1f, 0.9f, 0.1f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_SNAKE_SECT:
          glColor3f(0.5f, 0.5f, 0.5f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_FOOD:
          glColor3f(0.5f, 0.5f, 1.0f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_WALL:
          glColor3f(0.0f, 0.0f, 0.0f);
          this->draw_rect(x1, y1, x2, y2);
          break;
        case F_SNAKE_HEAD:
          glColor3f(1.0f, 0.2f, 0.2f);
          this->draw_rect(x1, y1, x2, y2);
          break;
      }
    }
  }
}

void render(void)
{
  glutSwapBuffers();
}

void OpenGLGraphic::wait(void)
{
    glutMainLoop();
}

