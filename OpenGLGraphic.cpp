//
// OpenGLGraphic.cpp for nibbler in /home/baezse_s/nibbler
//
// Made by Sergio Baez
// Login   <baezse_s@epitech.net>
//
// Started on  Fri Mar 22 20:52:43 2013 Sergio Baez
// Last update Sun Mar 24 16:37:46 2013 Sergio Baez
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
  createVertexBuffer();
}

OpenGLGraphic::~OpenGLGraphic(void)
{
}

void createVertexBuffer()
{
  Vector3f  vertices[3];

  vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
  vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
  vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
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

void OpenGLGraphic::wait(void)
{
    glutMainLoop();
}

