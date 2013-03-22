
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

Exception::VMException(const std::string & msg) throw() : message(msg)
{
}

const char *    Exception::what() const throw()
{
  return (this->message.data());
}

Exception::~VMException() throw()
{
}

OverflowException::OverflowException(const std::string & msg) throw()
  : Exception(std::string("Overflow Exception: ") + msg)
{
}

OverflowException::~OverflowException() throw()
{
}

ExitInstException::ExitInstException(const std::string & msg) throw()
  : Exception(std::string("No exit instruction Exception: ") + msg)
{
}

ExitInstException::~ExitInstException() throw()
{
}

BadParameterException::BadParameterException(const std::string & msg) throw()
  : Exception(std::string("Bad Parameter Exception: ") + msg)
{
}

BadParameterException::~BadParameterException() throw()
{
}

InstNotExistException::InstNotExistException(const std::string & msg) throw()
  : Exception(std::string("Instruction does not exist Exception: ") + msg)
{
}

InstNotExistException::~InstNotExistException() throw()
{
}

OpNotExistException::OpNotExistException(const std::string & msg) throw()
  : Exception(std::string("Operand does not exist Exception: ") + msg)
{
}

OpNotExistException::~OpNotExistException() throw()
{
}

DivisionByZeroException::DivisionByZeroException(const std::string & msg) throw()
  : Exception(std::string("Division by zero Exception: ") + msg)
{
}

DivisionByZeroException::~DivisionByZeroException() throw()
{
}

SyntaxErrorException::SyntaxErrorException(const std::string & msg, int ln) throw()
  : Exception(std::string("") + msg)
{
    std::cout << "Syntax Error at line: " << ln;
}

SyntaxErrorException::~SyntaxErrorException() throw()
{
}

FileException::FileException(const std::string & msg) throw()
  : Exception(std::string("File Error Exception: ") + msg)
{
}

FileException::~FileException() throw()
{
}

StackException::StackException(const std::string & msg) throw()
  : Exception(std::string("Stack Exception: ") + msg)
{
}

StackException::~StackException() throw()
{
}

WrongParameterException::WrongParameterException(const std::string & msg) throw()
  : Exception(std::string("Wrong parameter Exception: ") + msg)
{
}

WrongParameterException::~WrongParameterException() throw()
{
}

PrintErrorException::PrintErrorException(const std::string & msg) throw()
  : Exception(std::string("Print Exception: ") + msg)
{
}

PrintErrorException::~PrintErrorException() throw()
{
}

ExitProgramException::ExitProgramException(const std::string & msg) throw()
  : Exception(std::string("Exit") + msg)
{
}

ExitProgramException::~ExitProgramException() throw()
{
}

AssertException::AssertException(const std::string & msg) throw()
  : Exception(std::string("Assert Exception") + msg)
{
}

AssertException::~AssertException() throw()
{
}