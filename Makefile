##
## Makefile for nibbler in /home/ignatiev/Projects/nibbler
##
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
##
## Started on  Fri Mar 22 21:02:41 2013 ivan ignatiev
## Last update Sat Mar 23 02:44:55 2013 ivan ignatiev
##

NB_SRC 		= 		Nibbler.cpp \
					Game.cpp \
					Snake.cpp \
					Food.cpp \
					Surface.cpp \
					Field.cpp \
					GameThread.cpp \
					GraphicFactory.cpp

GTK_SRC  	= 		GTKGraphic.cpp \
					Game.cpp \
					AGraphic.cpp

QT_SRC 		=

OGL_SRC 	= 		OpenGLGraphic.cpp \
					AGraphic.cpp

NB_NAME 	= 		nibbler

GTK_NAME 	= 		lib_nibbler_gtkpp.so

OGL_NAME 	= 		lib_nibbler_opengl.so

QT_NAME 	= 		lib_nibbler_qt.so

RM 			= 		rm -f

CPPFLAGS 	+= 		-W -Wextra -Wall

CC 			= 		g++

NB_OBJ 		= 		$(NB_SRC:.cpp=.o)

CPPFLAGS 	+= 		-rdynamic -fPIC

GTK_OBJ  	= 		$(GTK_SRC:.cpp=.o)

QT_OBJ 		= 		$(QT_SRC:.cpp=.o)

OGL_OBJ 	= 		$(OGL_SRC:.cpp=.o)

all: 		$(NB_NAME) $(GTK_NAME) $(OGL_NAME) $(QT_NAME)

$(NB_NAME): 	$(NB_OBJ)
				$(CC) $(NB_OBJ) -lpthread -ldl -o $(NB_NAME)

$(GTK_NAME): 	$(GTK_OBJ)
				$(CC) -shared $(GTK_OBJ) -o $(GTK_NAME)

$(OGL_NAME): 	$(OGL_OBJ)
				$(CC) -shared $(OGL_OBJ) -o $(OGL_NAME)

$(QT_NAME): 	$(QT_NAME)
				$(CC) -shared $(QT_OBJ) -o $(QT_NAME)
clean:
				$(RM) 	$(NB_OBJ)
				$(RM) 	$(GTK_OBJ)
				$(RM) 	$(QT_OBJ)
				$(RM) 	$(OGL_OBJ)

fclean: 	clean
			$(RM) 	$(NB_NAME)
			$(RM) 	$(GTK_NAME)
			$(RM) 	$(QT_NAME)
			$(RM) 	$(OGL_NAME)

re: 		fclean all

.PHONY: all clean fclean re


