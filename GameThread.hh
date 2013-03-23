/*
** GameThread.h for nibbler in /home/ignatiev/Projects/nibbler
**
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
**
** Started on  Fri Mar 22 18:54:57 2013 ivan ignatiev
** Last update Fri Mar 22 19:00:51 2013 ivan ignatiev
*/

#ifndef GAMETHREAD_H_
# define GAMETHREAD_H_

# include <pthread.h>
# include <unistd.h>
# include "Game.hh"
# include "AGraphic.hh"

# define  MOVE_INTERVAL     10000
# define  REGEN_FOOD_INTERVAL 1000000

class   GameThread
{
    private:
        Game            *game_;
        AGraphic        *glib_;
        pthread_t       move_hndl_;
        pthread_t       food_hndl_;

        static void    *move_thread(void *);
        static void    *food_thread(void *);

        GameThread(void);
        GameThread(GameThread const &);
        GameThread &operator= (GameThread const &);
    public:
        GameThread(Game *game, AGraphic *glib);
        ~GameThread(void);

        void    start(void);
        void    wait(void);
};

#endif /* !GAMETHREAD_H_ */
