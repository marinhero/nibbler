//
// GameThread.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 20:17:33 2013 ivan ignatiev
// Last update Sun Mar 24 01:47:37 2013 ivan ignatiev
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

GameThread::~GameThread()
{

}

void    GameThread::start(void)
{
    pthread_create(&this->move_hndl_, NULL, GameThread::move_thread, this);
    pthread_create(&this->food_hndl_, NULL, GameThread::food_thread, this);
}

void    GameThread::wait(void)
{
    this->glib_->wait();
    pthread_join(this->move_hndl_, NULL);
    pthread_join(this->food_hndl_, NULL);
}

void    *GameThread::move_thread(void *attr)
{
    GameThread *th = static_cast<GameThread*>(attr);

    while (1)
    {
        th->glib_->refresh();
        th->game_->move();
        usleep(MOVE_INTERVAL);
    }
    return (NULL);
}

void    *GameThread::food_thread(void *attr)
{
    GameThread *th = static_cast<GameThread*>(attr);

    while (1)
    {
        //th->game_->regen_food();
        usleep(REGEN_FOOD_INTERVAL);
    }
    return (NULL);
}

