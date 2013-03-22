/*
** GraphicFactory.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 18:31:26 2013 ivan ignatiev
** Last update Fri Mar 22 18:49:46 2013 ivan ignatiev
*/

#ifndef GRAPHICFACTORY_H_
# define GRAPHICFACTORY_H_

# include <stdlib.h>
# include <dlfcn.h>
# include "Game.hh"
# include "AGraphic.hh"

# define LOAD_FUNC_SYM      "load_graphic"
# define UNLOAD_FUNC_SYM    "unload_graphic"

typedef AGraphic *(*load_func_t)(Game *);
typedef void (*unload_func_t)(AGraphic *);

class   GraphicFactory
{
    private:
        void            *dl_handle_;
        load_func_t     lf_;
        unload_func_t   ulf_;

        GraphicFactory(GraphicFactory const &);
        GraphicFactory &operator=(GraphicFactory const &);
    public:
        GraphicFactory();
        ~GraphicFactory();

        AGraphic    *load(const char *filename, Game *game);
        void        unload(AGraphic *glib);
};

#endif /* !GRAPHICFACTORY_H_ */
