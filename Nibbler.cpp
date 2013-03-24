//
// Nibbler.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:02:34 2013 ivan ignatiev
// Last update Sun Mar 24 17:10:23 2013 ivan ignatiev
//

#include        "Nibbler.hh"

int             main(int argc, char **argv)
{
    try
    {
        AGraphic        *glib;
        GraphicFactory  *gfactory;
        Game            *game;
        GameThread      *gamethread;
        int             width;
        int             height;

        if (argc > 3)
        {
            width = atoi(argv[1]);
            height = atoi(argv[2]);
            if ( width < 5 || height < 5 || width > 50 || height > 50)
                throw (new ArgsException("Wrong game field size"));
            game = new Game(width, height);
            gfactory = new GraphicFactory();
            if ((glib = gfactory->load(argv[3], game)) != NULL)
            {
                gamethread = new GameThread(game, glib);
                gamethread->start();
                gamethread->wait();
                gfactory->unload(glib);
            }
            return (EXIT_SUCCESS);
        }
        else
            throw (new ArgsException("./nibbler WIDTH HEIGHT ./lib_nibbler_[LIBNAME].so"));
    }
    catch(std::exception *e)
    {
        std::cerr << "nibbler: " << e->what() << std::endl;
    }
   return (EXIT_FAILURE);
}
