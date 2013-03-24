//
// GameThread.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 20:17:33 2013 ivan ignatiev
// Last update Sun Mar 24 17:38:55 2013 ivan ignatiev
//

#include "GameThread.hh"

GameThread::GameThread(void)
{
}

GameThread::GameThread(GameThread const &gt)
{
    (void) gt;
}

GameThread &GameThread::operator=(GameThread const &gt)
{
    (void) gt;
    return (*this);
}

GameThread::GameThread(Game *game, AGraphic *glib)
    : game_(game) , glib_(glib)
{
}

GameThread::~GameThread() {}

void    GameThread::start(void)
{
    if (pthread_create(&this->move_hndl_, NULL, GameThread::move_thread, this) != 0
        || pthread_create(&this->food_hndl_, NULL, GameThread::food_thread, this) != 0)
        throw (new ThreadException("Threads not started"));
}

void    GameThread::wait(void)
{
    this->glib_->wait();
    pthread_join(this->move_hndl_, NULL);
}

void    *GameThread::move_thread(void *attr)
{
    try
    {
        GameThread *th = static_cast<GameThread*>(attr);

        while (1)
        {
            th->glib_->refresh();
            if (!th->game_->move())
                throw (new GameException("Snake can't move more"));
            usleep(MOVE_INTERVAL);
        }
    }
    catch (std::exception *e)
    {
        std::cerr << "./nibbler[GameThread] : " << e->what() << std::endl;
        exit(1);
    }
    return (NULL);
}

void    *GameThread::food_thread(void *attr)
{
    try
    {
        GameThread *th = static_cast<GameThread*>(attr);

        while (1)
        {
            th->game_->regen_food();
            usleep(REGEN_FOOD_INTERVAL);
        }
    }
    catch (std::exception *e)
    {
        std::cerr << "./nibbler[GameAroundThread] : " << e->what() << std::endl;
    }
    return (NULL);
}

