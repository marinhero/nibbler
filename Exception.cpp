
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

Exception::Exception(const std::string & msg) throw() : message(msg)
{
}

Exception::~Exception(void) throw()
{
}

const char *    Exception::what(void) const throw()
{
  return (this->message.data());
}

LibraryException::LibraryException(const std::string & msg) throw() : Exception(msg) {}

LibraryException::~LibraryException(void) throw() {}

ThreadException::ThreadException(const std::string & msg) throw() : Exception(msg) {}

ThreadException::~ThreadException(void) throw() {}

ArgsException::ArgsException(const std::string & msg) throw() : Exception(msg) {}

ArgsException::~ArgsException(void) throw() {}

GameException::GameException(const std::string & msg) throw() : Exception(msg) {}

GameException::~GameException(void) throw() {}

WindowException::WindowException(const std::string & msg) throw() : Exception(msg) {}

WindowException::~WindowException(void) throw() {}


