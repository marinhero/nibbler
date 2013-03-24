//
// Exception.hh for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Feb 15 11:25:55 2013 Marin Alcaraz
// Last update Sun Mar 24 17:29:39 2013 ivan ignatiev
//

#ifndef EXCEPTION_HH_
# define EXCEPTION_HH_

#include <string>
#include <exception>

class Exception : public std::exception
{
  protected:
    std::string             message;
  public:
    Exception(const std::string & msg) throw();
    virtual const char *    what(void) const throw();
    virtual ~Exception(void) throw();
};

class LibraryException : public Exception
{
  public:
    LibraryException(const std::string & msg) throw();
    virtual ~LibraryException(void) throw();
};

class ThreadException : public Exception
{
  public:
    ThreadException(const std::string & msg) throw();
    virtual ~ThreadException(void) throw();
};

class ArgsException : public Exception
{
  public:
    ArgsException(const std::string & msg) throw();
    virtual ~ArgsException(void) throw();
};

class GameException : public Exception
{
  public:
    GameException(const std::string & msg) throw();
    virtual ~GameException(void) throw();
};

#endif
