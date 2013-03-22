//
// Nibbler.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:02:34 2013 ivan ignatiev
// Last update Fri Mar 22 19:36:19 2013 ivan ignatiev
//

#include        "Nibbler.hh"

int             main(int argc, char **argv)
{
    AGraphic        *glib;
    GraphicFactory  *gfactory;
    Game            *game;
    GameThread      *gamethread;
    int             width;
    int             height;

    if (argc > 3)
    {
        /*
         * width = argv[1] width = argv[2]
         */
        game = new Game(width, height);
        gfactory = new GraphicFactory();
        glib = gfactory->load(argv[3], game);
        gamethread = new GameThread(game, glib);
        gamethread->start();
        gamethread->wait();
        gfactory->unload(glib);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE):
}
