/*
** DLSymbol.h for dlclass in /Users/sabs231/Documents/EPITECH/Classes/C++/Projects/Nibbler/nibbler/src/dlclass
**
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
**
** Started on  Thu Mar 21 21:42:05 2013 sergioandres baezserrano
** Last update Thu Mar 21 21:42:13 2013 sergioandres baezserrano
*/

#ifndef DLSYMBOL_HH_
#  define DLSYMBOL_HH_

#  include  "DLHandler.hh"

class DLHandler;

class DLSymbol
{
  protected:
    DLHandler   *handler;

  public:
    DLSymbol();
    virtual ~DLSymbol();
};

#endif /* !DLSYMBOL_HH_ */
