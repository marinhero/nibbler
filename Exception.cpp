
// Exception.cpp for nibbler in /Users/sabs231/Documents/EPITECH/Classes/C++/Projects/Nibbler/nibbler
//
// Made by sergioandres baezserrano
// Login   <baezse_s@epitech.net>
//
// Started on  Sat Feb 16 11:28:51 2013 sergioandres baezserrano
// Last update Fri Mar 22 18:29:55 2013 sergioandres baezserrano
//

#include "Exception.hh"
#include <iostream>

Exception::SnakeException(const std::string & msg) throw() : message(msg)
{
}

Exception::~SnakeException() throw()
{
}

const char *    Exception::what() const throw()
{
  return (this->message.data());
}

SelfHitException::SelfHitException(const std::string & msg) throw()
  : Exception(std::string("Self Hit Exception: ") + msg)
{
}

SelfHitException::~SelfHitException() throw()
{
}
