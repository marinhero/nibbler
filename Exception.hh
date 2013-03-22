//
// VMException.hh for abstractvm in /home/baezse_s/CPP/projects/AbstractVM/abstractvm
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Fri Feb 15 11:25:55 2013 Marin Alcaraz
// Last update Sat Feb 23 14:57:55 2013 Sergio Baez
//

#ifndef VMEXCEPTION_HH_
# define VMEXCEPTION_HH_

#include <string>
#include <exception>

class VMException : public std::exception
{
  protected:
    std::string             message;
  public:
    VMException(const std::string & msg) throw();
    virtual const char *    what() const throw();
    ~VMException() throw();
};

class OverflowException : public VMException
{
  public:
    OverflowException(const std::string & msg) throw();
    ~OverflowException() throw();
};

class ExitInstException : public VMException
{
  public:
    ExitInstException(const std::string & msg) throw();
    ~ExitInstException() throw();
};

class BadParameterException : public VMException
{
  public:
    BadParameterException(const std::string & msg) throw();
    ~BadParameterException() throw();
};

class InstNotExistException : public VMException
{
  public:
    InstNotExistException(const std::string & msg) throw();
    ~InstNotExistException() throw();
};

class OpNotExistException : public VMException
{
  public:
    OpNotExistException(const std::string & msg) throw();
    ~OpNotExistException() throw();
};

class DivisionByZeroException : public VMException
{
  public:
    DivisionByZeroException(const std::string & msg) throw();
    ~DivisionByZeroException() throw();
};

class SyntaxErrorException : public VMException
{
  public:
   SyntaxErrorException(const std::string & msg, int ln) throw();
    ~SyntaxErrorException() throw();
};

class FileException : public VMException
{
  public:
   FileException(const std::string & msg) throw();
    ~FileException() throw();
};

class StackException : public VMException
{
  public:
    StackException(const std::string & msg) throw();
    ~StackException() throw();
};

class WrongParameterException : public VMException
{
  public:
    WrongParameterException(const std::string & msg) throw();
    ~WrongParameterException() throw();
};

class PrintErrorException : public VMException
{
  public:
    PrintErrorException(const std::string & msg) throw();
    ~PrintErrorException() throw();
};

class ExitProgramException : public VMException
{
  public:
    ExitProgramException(const std::string & msg) throw();
    ~ExitProgramException() throw();
};

class AssertException : public VMException
{
  public:
    AssertException(const std::string & msg) throw();
    ~AssertException() throw();
};

#endif
