//
// Exception.hh for nibbler in /home/hero/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Feb 15 11:25:55 2013 Marin Alcaraz
// Last update Sun Mar 24 04:07:15 2013 Marin Alcaraz
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
    virtual const char *    what() const throw();
    ~Exception() throw();
};

class SelfHitException : public Exception
{
  public:
    SelfHitException(const std::string & msg) throw();
    ~SelfHitException() throw();
};

#endif
