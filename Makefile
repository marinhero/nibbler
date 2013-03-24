##
## Makefile for nibbler in /home/baezse_s/nibbler
## Makefile for nibbler in /home/baezse_s/nibbler
##
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
##
## Started on  Fri Mar 22 21:02:41 2013 ivan ignatiev
## Last update Sun Mar 24 22:04:12 2013 Sergio Baez
##

NB_SRC 		= 		Nibbler.cpp \
					Exception.cpp \
					Game.cpp \
					Snake.cpp \
					Food.cpp \
					Surface.cpp \
					Field.cpp \
					GameThread.cpp \
					GraphicFactory.cpp

GTK_SRC  	= 		GTKGraphic.cpp \
					Exception.cpp \
					Game.cpp \
					Field.cpp \
					Snake.cpp \
					AGraphic.cpp

XLIB_SRC 		= 	XlibGraphic.cpp \
					Game.cpp \
					Exception.cpp \
					Field.cpp \
					Snake.cpp \
					AGraphic.cpp

OGL_SRC 	= 		OpenGLGraphic.cpp \
					Exception.cpp \
					Game.cpp \
					Field.cpp \
					Snake.cpp \
					AGraphic.cpp

DEBUG_SRC 		= 	DebugGraphic.cpp \
					Game.cpp \
					Field.cpp \
					Snake.cpp \
					AGraphic.cpp

NB_NAME 	= 		nibbler

GTK_NAME 	= 		lib_nibbler_gtkpp.so

OGL_NAME 	= 		lib_nibbler_opengl.so

XLIB_NAME 	= 		lib_nibbler_xlib.so

DEBUG_NAME 	= 		lib_nibbler_debug.so

RM 			= 		rm -f

CPPFLAGS 	+= 		-W -Wextra -Wall
CPPFLAGS 	+= 		-rdynamic -fPIC

CC 			= 		g++

NB_OBJ 		= 		$(NB_SRC:.cpp=.o)

GTK_OBJ  	= 		$(GTK_SRC:.cpp=.o)

XLIB_OBJ 	= 		$(XLIB_SRC:.cpp=.o)

OGL_OBJ 	= 		$(OGL_SRC:.cpp=.o)

DEBUG_OBJ 	= 		$(DEBUG_SRC:.cpp=.o)

all: 		$(NB_NAME) $(GTK_NAME) $(OGL_NAME) $(QT_NAME)

$(NB_NAME): 	$(NB_OBJ)
				$(CC) $(NB_OBJ) -lpthread -ldl -o $(NB_NAME)

GTKGraphic.o: 	GTKGraphic.cpp
				$(CC) -DGDK_DISABLE_DEPRECATION_WARNINGS -c $(CPPFLAGS) `pkg-config --cflags gtk+-3.0` $<  -o $@

$(GTK_NAME): 	$(GTK_OBJ)
				$(CC) -shared $(GTK_OBJ) -o $(GTK_NAME) `pkg-config --libs gtk+-3.0`

$(OGL_NAME): 	$(OGL_OBJ)
				$(CC) -shared $(OGL_OBJ) -o $(OGL_NAME) -lglut -lGL -lGLU

XlibGraphic.o: 	XlibGraphic.cpp
				$(CC) -I/usr/X11R6/include -c $(CPPFLAGS)  $<  -o $@

$(XLIB_NAME): 	$(XLIB_OBJ)
				$(CC) -shared $(XLIB_OBJ) -o $(XLIB_NAME) -lX11 -L/usr/X11R6/lib

$(DEBUG_NAME): 	$(DEBUG_OBJ)
				$(CC) -shared $(DEBUG_OBJ) -o $(DEBUG_NAME)
clean:
				$(RM) 	$(NB_OBJ)
				$(RM) 	$(GTK_OBJ)
				$(RM) 	$(XLIB_OBJ)
				$(RM) 	$(DEBUG_OBJ)
				$(RM) 	$(OGL_OBJ)

fclean: 	clean
			$(RM) 	$(NB_NAME)
			$(RM) 	$(GTK_NAME)
			$(RM) 	$(XLIB_NAME)
			$(RM) 	$(DEBUG_NAME)
			$(RM) 	$(OGL_NAME)

re: 		fclean all

.PHONY: all clean fclean re


