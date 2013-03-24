//
// Nibbler.cpp for nibbler in /home/hero/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:02:34 2013 ivan ignatiev
// Last update Sun Mar 24 04:33:53 2013 Marin Alcaraz
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
        width = atoi(argv[1]);
        height = atoi(argv[2]);
        game = new Game(width, height);
        gfactory = new GraphicFactory();
        if ((glib = gfactory->load(argv[3], game)) != NULL)
        {
            gamethread = new GameThread(game, glib);
            gamethread->start();
            gamethread->wait();
            gfactory->unload(glib);
        }
        else
        {
            std::cerr << "Error : Can't load library : " << argv[3] << std::endl;
        }
        return (EXIT_SUCCESS);
   }
   return (EXIT_FAILURE);
}
