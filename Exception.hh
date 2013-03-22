//
// Exception.hh for nibbler in /Users/sabs231/Documents/EPITECH/Classes/C++/Projects/Nibbler/nibbler
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Feb 15 11:25:55 2013 Marin Alcaraz
// Last update Fri Mar 22 18:33:51 2013 sergioandres baezserrano
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

class OverflowException : public Exception
{
  public:
    OverflowException(const std::string & msg) throw();
    ~OverflowException() throw();
};

class ExitInstException : public Exception
{
  public:
    ExitInstException(const std::string & msg) throw();
    ~ExitInstException() throw();
};

class BadParameterException : public Exception
{
  public:
    BadParameterException(const std::string & msg) throw();
    ~BadParameterException() throw();
};

class InstNotExistException : public Exception
{
  public:
    InstNotExistException(const std::string & msg) throw();
    ~InstNotExistException() throw();
};

class OpNotExistException : public Exception
{
  public:
    OpNotExistException(const std::string & msg) throw();
    ~OpNotExistException() throw();
};

class DivisionByZeroException : public Exception
{
  public:
    DivisionByZeroException(const std::string & msg) throw();
    ~DivisionByZeroException() throw();
};

class SyntaxErrorException : public Exception
{
  public:
   SyntaxErrorException(const std::string & msg, int ln) throw();
    ~SyntaxErrorException() throw();
};

class FileException : public Exception
{
  public:
   FileException(const std::string & msg) throw();
    ~FileException() throw();
};

class StackException : public Exception
{
  public:
    StackException(const std::string & msg) throw();
    ~StackException() throw();
};

class WrongParameterException : public Exception
{
  public:
    WrongParameterException(const std::string & msg) throw();
    ~WrongParameterException() throw();
};

class PrintErrorException : public Exception
{
  public:
    PrintErrorException(const std::string & msg) throw();
    ~PrintErrorException() throw();
};

class ExitProgramException : public Exception
{
  public:
    ExitProgramException(const std::string & msg) throw();
    ~ExitProgramException() throw();
};

class AssertException : public Exception
{
  public:
    AssertException(const std::string & msg) throw();
    ~AssertException() throw();
};

#endif
